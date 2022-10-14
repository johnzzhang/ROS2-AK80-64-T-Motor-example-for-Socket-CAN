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

        self.motor1 = CanMotorController('can0', 0x01)
        time.sleep(0.1)
        self.motor1.enable_motor()
        time.sleep(0.1)
        self.motor1.set_zero_position()
        time.sleep(0.1)

    def motor_callback(self, msg):
        max_vel = 0
        ff = 0
        ref = msg.ref # desired position in degrees
        Kp = msg.kp
        Kd = msg.kd

        motor_output_msg = MotorOutput()
        pos, vel, torq = self.motor1.send_deg_command(ref,max_vel,Kp,Kd,ff)

        motor_output_msg.pos = pos
        motor_output_msg.vel = vel
        motor_output_msg.torq = torq

        self.motor_pub.publish(motor_output_msg)


def main():
    rclpy.init()

    motor_node = MotorNode()
    rclpy.spin(motor_node)

    motor_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()