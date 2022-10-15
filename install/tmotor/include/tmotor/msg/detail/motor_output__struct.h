// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tmotor:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_
#define TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MotorOutput in the package tmotor.
typedef struct tmotor__msg__MotorOutput
{
  float pos1;
  float vel1;
  float torq1;
  float pos2;
  float vel2;
  float torq2;
} tmotor__msg__MotorOutput;

// Struct for a sequence of tmotor__msg__MotorOutput.
typedef struct tmotor__msg__MotorOutput__Sequence
{
  tmotor__msg__MotorOutput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tmotor__msg__MotorOutput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_
