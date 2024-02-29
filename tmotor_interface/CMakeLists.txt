cmake_minimum_required(VERSION 3.8)
project(tmotor_interface)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#==========================================================#
#                       Dependencies                       #
#==========================================================#
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

#==========================================================#
#                        Interfaces                        #
#==========================================================#

rosidl_generate_interfaces(${PROJECT_NAME}
    msg/MotorCmd.msg
    msg/MotorOutput.msg
    msg/MotorDebug.msg
)

ament_package()