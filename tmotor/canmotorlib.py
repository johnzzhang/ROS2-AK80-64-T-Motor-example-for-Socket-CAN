import socket
import struct
import time
import math
from bitstring import BitArray

# CAN frame packing/unpacking (see `struct can_frame` in <linux/can.h>)
# 8 bytes of data is sent to the motor
can_frame_fmt_send = "=IB3x8s"
# 6 bytes are received from the motor
can_frame_fmt_recv = "=IB3x6s"
# Total CAN Frame size is 14 Bytes: 8 Bytes overhead + 6 Bytes data
recvBytes = 14

# Working parameters for AK80_64
AK80_64_PARAMS = {
                    "P_MIN" : -12.5,
                    "P_MAX" : 12.5,
                    "V_MIN" : -8.0,
                    "V_MAX" : 8.0,
                    "KP_MIN" : 0.0,
                    "KP_MAX" : 500.0,
                    "KD_MIN" : 0.0,
                    "KD_MAX" : 5.0,
                    "T_MIN" : -144.0,
                    "T_MAX" : 144.0,
                    "AXIS_DIRECTION" : 1
                    }

AK80_64_PARAMS_REVERSED = {
                    "P_MIN" : -12.5,
                    "P_MAX" : 12.5,
                    "V_MIN" : -8.0,
                    "V_MAX" : 8.0,
                    "KP_MIN" : 0.0,
                    "KP_MAX" : 500.0,
                    "KD_MIN" : 0.0,
                    "KD_MAX" : 5.0,
                    "T_MIN" : -144.0,
                    "T_MAX" : 144.0,
                    "AXIS_DIRECTION" : -1
                    }

maxRawPosition = 2**16 - 1                      # 16-Bits for Raw Position Values
maxRawVelocity = 2**12 - 1                      # 12-Bits for Raw Velocity Values
maxRawTorque = 2**12 - 1                        # 12-Bits for Raw Torque Values
maxRawKp = 2**12 - 1                            # 12-Bits for Raw Kp Values
maxRawKd = 2**12 - 1                            # 12-Bits for Raw Kd Values
maxRawCurrent = 2**12 - 1                       # 12-Bits for Raw Current Values

def float_to_uint(x, x_min, x_max, numBits):
    span = x_max - x_min
    offset = x_min
    if numBits == 16:
        bitRange = maxRawPosition
    elif numBits == 12:
        bitRange = maxRawVelocity
    else:
        bitRange = 2**numBits - 1
    return int(((x - offset) * (bitRange)) / span)

def uint_to_float(x_int, x_min, x_max, numBits):
    span = x_max - x_min
    offset = x_min
    if numBits == 16:
        bitRange = maxRawPosition
    elif numBits == 12:
        bitRange = maxRawVelocity
    else:
        bitRange = 2**numBits - 1
    return ((x_int * span) / (bitRange)) + offset

class CanMotorController():
    """
    Class for creating a Mini-Cheetah Motor Controller over CAN. Uses SocketCAN driver for
    communication.
    """
    
    def __init__(self, can_socket='can0', motor_id=0x01, motor_type = 'AK80_64',
                socket_timeout=0.05, motor_response_timeout=0.001):
        """
        Instantiate the class with socket name, motor ID, and socket timeout.
        Sets up the socket communication for rest of the functions.
        """
        self.can_socket_id = int(can_socket[-1])
        self.motor_response_timeout = motor_response_timeout
        
        self.motorParams = AK80_64_PARAMS # default choice
        
        if motor_type = 'AK80_64_REVERSED':
            self.motorParams = AK80_64_PARAMS_REVERSED

        print('Using Motor Type: {}'.format(motor_type))
        
        can_socket = (can_socket, )
        self.motor_id = motor_id
        # create a raw socket and bind it to the given CAN interface
        try:
            self.motor_socket = socket.socket(socket.AF_CAN, socket.SOCK_RAW,
                                                            socket.CAN_RAW)
            self.motor_socket.bind(can_socket)
            self.motor_socket.settimeout(socket_timeout)
            print("Bound to: ", can_socket)
        except Exception as e:
            print("Unable to Connect to Socket Specified: ", can_socket)
            print("Error:", e)

        # Initialize the command BitArrays for performance optimization
        self._p_des_BitArray = BitArray(uint=float_to_uint(0, self.motorParams['P_MIN'],
                                                        self.motorParams['P_MAX'], 16), length=16)
        self._v_des_BitArray = BitArray(uint=float_to_uint(0, self.motorParams['V_MIN'],
                                                        self.motorParams['V_MAX'], 12), length=12)
        self._kp_BitArray = BitArray(uint=0, length=12)
        self._kd_BitArray = BitArray(uint=0, length=12)
        self._tau_BitArray = BitArray(uint=0, length=12)
        self._cmd_bytes = BitArray(uint=0, length=64)
        self._recv_bytes = BitArray(uint=0, length=48)

    def _send_can_frame(self, data):
        """
        Send raw CAN data frame (in bytes) to the motor.
        """
        can_dlc = len(data)
        can_msg = struct.pack(can_frame_fmt_send, self.motor_id, can_dlc, data)
        try:
            self.motor_socket.send(can_msg)
        except Exception as e:
            print("Unable to Send CAN Frame.")
            print("Error: ", e)

    def _recv_can_frame(self):
        """
        Receive a CAN frame and unpack it. Returns can_id, can_dlc (data length), data (in bytes)
        """
        try:
            # The motor sends back only 6 bytes.
            frame, addr = self.motor_socket.recvfrom(recvBytes)
            can_id, can_dlc, data = struct.unpack(can_frame_fmt_recv, frame)
            return can_id, can_dlc, data[:can_dlc]
        except Exception as e:
            print("Unable to Receive CAN Frame.")
            print("Error: ", e)

    def enable_motor(self):
        """
        Sends the enable motor command to the motor.
        """
        try:
            self._send_can_frame(b'\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFC')
            motorStatusData = self.wait_motor_response()
            rawMotorData = self.decode_motor_status(motorStatusData)
            pos, vel, curr = self.convert_raw_to_physical_rad(rawMotorData[1], rawMotorData[2],
                                                            rawMotorData[3])
            print("Motor Enabled.")
            return pos, vel, curr
        except Exception as e:
            print('Error Enabling Motor!')
            print("Error: ", e)

    def disable_motor(self):
        """
        Sends the disable motor command to the motor.
        """
        try:
            # Bugfix: To remove the initial kick at motor start.
            # The current working theory is that the motor "remembers" the last command. And this
            # causes an initial kick as the motor controller starts. The fix is then to set the 
            # last command to zero so that this does not happen. For the user, the behavior does
            # not change as zero command + disable is same as disable.
            _, _, _ = self.send_rad_command(0, 0, 0, 0, 0)

            # Do the actual disabling after zero command.
            self._send_can_frame(b'\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFD')
            motorStatusData = self.wait_motor_response()
            rawMotorData = self.decode_motor_status(motorStatusData)
            pos, vel, curr = self.convert_raw_to_physical_rad(rawMotorData[1], rawMotorData[2],
                                                            rawMotorData[3])
            print("Motor Disabled.")
            return pos, vel, curr
        except Exception as e:
            print('Error Disabling Motor!')
            print("Error: ", e)

    def set_zero_position(self):
        """
        Sends command to set current position as Zero position.
        """
        try:
            self._send_can_frame(b'\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFE')
            motorStatusData = self.wait_motor_response()
            rawMotorData = self.decode_motor_status(motorStatusData)
            pos, vel, curr = self.convert_raw_to_physical_rad(rawMotorData[1], rawMotorData[2],
                                                            rawMotorData[3])
            print("Zero Position set.")
            return pos, vel, curr
        except Exception as e:
            print('Error Setting Zero Position!')
            print("Error: ", e)

    def decode_motor_status(self, data_frame):
        '''
        Function to decode the motor status reply message into its constituent raw values.

        /// CAN Reply Packet Structure ///
        /// 16 bit position, between -4*pi and 4*pi
        /// 12 bit velocity, between -30 and + 30 rad/s
        /// 12 bit current, between -40 and 40;
        /// CAN Packet is 5 8-bit words
        /// Formatted as follows.  For each quantity, bit 0 is LSB
        /// 0: [position[15-8]]
        /// 1: [position[7-0]]
        /// 2: [velocity[11-4]]
        /// 3: [velocity[3-0], current[11-8]]
        /// 4: [current[7-0]]

        returns: the following raw values as (u)int: position, velocity, current
        '''

        # Convert the message from motor to a bit string as this is easier to deal with than hex
        # while seperating individual values.
        self._recv_bytes.bytes = data_frame
        dataBitArray = self._recv_bytes.bin

        # Separate motor status values from the bit string.
        # Motor ID not considered necessary at the moment.
        motorIDBitArray = dataBitArray[:8]
        positionBitArray = dataBitArray[8:24]
        velocityBitArray = dataBitArray[24:36]
        currentBitArray = dataBitArray[36:48]

        motor_id = int(motorIDBitArray, 2)
        positionRawValue = int(positionBitArray, 2)
        velocityRawValue = int(velocityBitArray, 2)
        currentRawValue = int(currentBitArray, 2)

        return motor_id, positionRawValue, velocityRawValue, currentRawValue

    def convert_raw_to_physical_rad(self, positionRawValue, velocityRawValue, currentRawValue):
        '''
        Function to convert the raw values from the motor to physical values:

        /// CAN Reply Packet Structure ///
        /// 16 bit position, between -4*pi and 4*pi
        /// 12 bit velocity, between -30 and + 30 rad/s
        /// 12 bit current, between -40 and 40;
        /// CAN Packet is 5 8-bit words
        /// Formatted as follows.  For each quantity, bit 0 is LSB
        /// 0: [position[15-8]]
        /// 1: [position[7-0]]
        /// 2: [velocity[11-4]]
        /// 3: [velocity[3-0], current[11-8]]
        /// 4: [current[7-0]]

        returns: position (radians), velocity (rad/s), current (amps)
        '''

        physicalPositionRad = uint_to_float(positionRawValue, self.motorParams['P_MIN'],
                                            self.motorParams['P_MAX'], 16)
        physicalVelocityRad = uint_to_float(velocityRawValue, self.motorParams['V_MIN'],
                                            self.motorParams['V_MAX'], 12)
        physicalCurrent = uint_to_float(currentRawValue, self.motorParams['T_MIN'],
                                        self.motorParams['T_MAX'], 12)

        # Correct Axis Direction
        physicalPositionRad = physicalPositionRad * self.motorParams['AXIS_DIRECTION']
        physicalVelocityRad = physicalVelocityRad * self.motorParams['AXIS_DIRECTION']
        physicalCurrent = physicalCurrent * self.motorParams['AXIS_DIRECTION']

        return physicalPositionRad, physicalVelocityRad, physicalCurrent

    def convert_physical_rad_to_raw(self, p_des_rad, v_des_rad, kp, kd, tau_ff):
        # Correct the Axis Direction
        p_des_rad = p_des_rad * self.motorParams['AXIS_DIRECTION']
        v_des_rad = v_des_rad * self.motorParams['AXIS_DIRECTION']
        tau_ff = tau_ff * self.motorParams['AXIS_DIRECTION']

        rawPosition = float_to_uint(p_des_rad, self.motorParams['P_MIN'],
                                    self.motorParams['P_MAX'], 16)
        rawVelocity = float_to_uint(v_des_rad, self.motorParams['V_MIN'],
                                    self.motorParams['V_MAX'], 12)
        rawTorque = float_to_uint(tau_ff, self.motorParams['T_MIN'], self.motorParams['T_MAX'], 12)

        rawKp = ((maxRawKp * kp) / self.motorParams['KP_MAX'])

        rawKd = ((maxRawKd * kd) / self.motorParams['KD_MAX'])

        return int(rawPosition), int(rawVelocity), int(rawKp), int(rawKd), int(rawTorque)

    def _send_raw_command(self, p_des, v_des, kp, kd, tau_ff):
        """
        Package and send raw (uint) values of correct length to the motor.

        _send_raw_command(desired position, desired velocity, position gain, velocity gain,
                        feed-forward torque)

        Sends data over CAN, reads response, and returns the motor status data (in bytes).
        """
        self._p_des_BitArray.uint = p_des
        self._v_des_BitArray.uint = v_des
        self._kp_BitArray.uint = kp
        self._kd_BitArray.uint = kd
        self._tau_BitArray.uint = tau_ff
        cmd_BitArray = self._p_des_BitArray.bin + self._v_des_BitArray.bin + self._kp_BitArray.bin \
                        + self._kd_BitArray.bin + self._tau_BitArray.bin

        self._cmd_bytes.bin = cmd_BitArray

        try:
            self._send_can_frame(self._cmd_bytes.tobytes())
            data = self.wait_motor_response()
            
            return data
        except Exception as e:
            print('Error Sending Raw Commands!')
            print("Error: ", e)

    def send_deg_command(self, p_des_deg, v_des_deg, kp, kd, tau_ff):
        """
        Function to send data to motor in physical units:
        send_deg_command(position (deg), velocity (deg/s), kp, kd, Feedforward Torque (Nm))
        Sends data over CAN, reads response, and prints the current status in deg, deg/s, amps.
        If any input is outside limits, it is clipped. Only if torque is outside limits, a log 
        message is shown.
        """
        p_des_rad = math.radians(p_des_deg)
        v_des_rad = math.radians(v_des_deg)

        pos_rad, vel_rad, curr = self.send_rad_command(p_des_rad, v_des_rad, kp, kd, tau_ff)
        pos = math.degrees(pos_rad)
        vel = math.degrees(vel_rad)
        return pos, vel, curr

    def send_rad_command(self, p_des_rad, v_des_rad, kp, kd, tau_ff):
        """
        Function to send data to motor in physical units:
        send_rad_command(position (rad), velocity (rad/s), kp, kd, Feedforward Torque (Nm))
        Sends data over CAN, reads response, and prints the current status in rad, rad/s, amps.
        If any input is outside limits, it is clipped. Only if torque is outside limits, a log 
        message is shown.
        """
        # Check for Torque Limits
        if (tau_ff < self.motorParams['T_MIN']):
            print('Torque Commanded lower than the limit. Clipping Torque...')
            print('Commanded Torque: {}'.format(tau_ff))
            print('Torque Limit: {}'.format(self.motorParams['T_MIN']))
            tau_ff = self.motorParams['T_MIN']
        elif (tau_ff > self.motorParams['T_MAX']):
            print('Torque Commanded higher than the limit. Clipping Torque...')
            print('Commanded Torque: {}'.format(tau_ff))
            print('Torque Limit: {}'.format(self.motorParams['T_MAX']))
            tau_ff = self.motorParams['T_MAX']

        # Clip Position if outside Limits
        p_des_rad = min(max(self.motorParams['P_MIN'], p_des_rad), self.motorParams['P_MAX'])
        # Clip Velocity if outside Limits
        v_des_rad = min(max(self.motorParams['V_MIN'], v_des_rad), self.motorParams['V_MAX'])
        # Clip Kp if outside Limits
        kp = min(max(self.motorParams['KP_MIN'], kp), self.motorParams['KP_MAX'])
        # Clip Kd if outside Limits
        kd = min(max(self.motorParams['KD_MIN'], kd), self.motorParams['KD_MAX'])

        rawPos, rawVel, rawKp, rawKd, rawTauff = self.convert_physical_rad_to_raw(p_des_rad,
                                                                v_des_rad, kp, kd, tau_ff)

        motorStatusData = self._send_raw_command(rawPos, rawVel, rawKp, rawKd, rawTauff)
        rawMotorData = self.decode_motor_status(motorStatusData)
        pos, vel, curr = self.convert_raw_to_physical_rad(rawMotorData[1], rawMotorData[2],
                                                            rawMotorData[3])

        
        return pos, vel, curr

    def wait_motor_response(self):
        startTime = time.time()
        while time.time() - startTime < self.motor_response_timeout:
            can_id, _, data = self._recv_can_frame()
            
            self._recv_bytes.bytes = data
            dataBitArray = self._recv_bytes.bin
            motorIDBitArray = dataBitArray[:8]
            motor_id = int(motorIDBitArray, 2)

            if can_id == self.can_socket_id and self.motor_id == motor_id:
                return data

        raise Exception("Motor response timeout: {} elapsed and no return from motor".format(motor_response_timeout)) 