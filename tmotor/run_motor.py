#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from motor_driver.canmotorlib import CanMotorController
from tmotor.msg import MotorCmd
from tmotor.msg import MotorOutput

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
        self.motor1 = CanMotorController(can_socket='can0', motor_id=0x01, motor_type='AK80_6_V2',socket_timeout=2)
        time.sleep(1)
        self.motor2 = CanMotorController(can_socket='can0', motor_id=0x02, motor_type='AK80_6_V2',socket_timeout=2)
        time.sleep(1)

        print('Enabling motor...')
        self.motor1.enable_motor()
        time.sleep(1)
        self.motor2.enable_motor()
        time.sleep(1)

        print('Zeroing motor position...')
        self.motor1.set_zero_position()
        time.sleep(1)
        self.motor2.set_zero_position()
        time.sleep(1)

    def motor_callback(self, msg):
        max_vel = 0
        ff = 0
        ref1 = msg.ref1 # desired position in degrees
        Kp1 = msg.kp1
        Kd1 = msg.kd1
        ref2 = msg.ref2 # desired position in degrees
        Kp2 = msg.kp2
        Kd2 = msg.kd2

        motor_output_msg = MotorOutput()
        pos1, vel1, torq1 = self.motor1.send_deg_command(ref1,max_vel,Kp1,Kd1,ff)
        pos2, vel2, torq2 = self.motor2.send_deg_command(ref2,max_vel,Kp2,Kd2,ff)

        motor_output_msg.pos1 = pos1
        motor_output_msg.vel1 = vel1
        motor_output_msg.torq1 = torq1

        motor_output_msg.pos2 = pos2
        motor_output_msg.vel2 = vel2
        motor_output_msg.torq2 = torq2

        self.motor_pub.publish(motor_output_msg)

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