#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from canmotorlib import CanMotorController
from tmotor_interface.msg import MotorCmd
from tmotor_interface.msg import MotorOutput
from tmotor_interface.msg import MotorDebug

class MotorNode(Node):
    def __init__(self):
        super().__init__('motor_node')
        # Create a subscriber to listen for drive motor commands
        self.motor_sub = self.create_subscription(
            MotorCmd,
            'motor_cmd',
            self.motor_callback,
            10)
        self.motor_sub  # prevent unused variable warning

        # Create a publisher to publish motor data
        self.motor_pub = self.create_publisher(
            MotorOutput, # message interface
            'motor_output', # topic name
            10) # queue length

        # 0.5 second timeout is too fast for PCAN
        self.motor1 = CanMotorController(can_socket='can0', motor_id=0x01, socket_timeout=2, motor_response_timeout=0.001, motor_type='AK80_64_REVERSED')
        #self.motor2 = CanMotorController(can_socket='can0', motor_id=0x02, socket_timeout=2, motor_response_timeout=0.001)
        
        self.motor1.enable_motor()
        #self.motor2.enable_motor()
        
        self.motor1.set_zero_position()
        #self.motor2.set_zero_position()
        
    def motor_callback(self, msg):
        vel_ref = 0 # not used for position control
        ff = 0 # feed forward torque

        # command message
        ref1 = msg.ref1 # desired position in rad
        Kp1 = msg.kp1
        Kd1 = msg.kd1

        ref2 = msg.ref2 # desired position in rad
        Kp2 = msg.kp2
        Kd2 = msg.kd2

        motor_output_msg = MotorOutput()
        pos1, vel1, torq1 = self.motor1.send_rad_command(ref1,vel_ref,Kp1,Kd1,ff)
        # pos2, vel2, torq2 = self.motor2.send_rad_command(ref2,vel_ref,Kp2,Kd2,ff)
        
        motor_output_msg.pos1 = pos1
        motor_output_msg.vel1 = vel1
        motor_output_msg.torq1 = torq1

        # motor_output_msg.pos2 = pos2
        # motor_output_msg.vel2 = vel2
        # motor_output_msg.torq2 = torq2

        self.motor_pub.publish(motor_output_msg)

    def disable_motors(self):
        self.motor1.disable_motor()
        #self.motor2.disable_motor()
        print('Disabled motors...')

    def destroy_node(self):
        self.disable_motors()
        super().destroy_node()

def main():
    rclpy.init()

    try:
        motor_node = MotorNode()
        rclpy.spin(motor_node)
    except KeyboardInterrupt:
        motor_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()