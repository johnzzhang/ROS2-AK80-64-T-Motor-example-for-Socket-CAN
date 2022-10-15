// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
#define TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MotorCmd in the package tmotor.
typedef struct tmotor__msg__MotorCmd
{
  float ref1;
  float kp1;
  float kd1;
  float ref2;
  float kp2;
  float kd2;
} tmotor__msg__MotorCmd;

// Struct for a sequence of tmotor__msg__MotorCmd.
typedef struct tmotor__msg__MotorCmd__Sequence
{
  tmotor__msg__MotorCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tmotor__msg__MotorCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
