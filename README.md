ROS2 example with socket CAN library to interface with a AK80-64 T-Motor Module.
Refresh rates of 25 Hz are possible with two motors.

To build this project go to your top level ROS2 workspace and run `colcon build --packages-select tmotor`.
You will have to run `. install/local_setup.bash` to add the built files to your path.
You can run the ros node with the command `ros2 run tmotor run_motor.py` and write/read from the motor using `rqt &`.
I have included a rqt perspective that plots the positions.
You can use `ros2 topic hz tmotor` to verify the loop rate of the node.