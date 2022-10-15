// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tmotor:msg/MotorDebug.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_DEBUG__STRUCT_H_
#define TMOTOR__MSG__DETAIL__MOTOR_DEBUG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos1'
// Member 'vel1'
// Member 'torq1'
// Member 'pos2'
// Member 'vel2'
// Member 'torq2'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/MotorDebug in the package tmotor.
typedef struct tmotor__msg__MotorDebug
{
  rosidl_runtime_c__String pos1;
  rosidl_runtime_c__String vel1;
  rosidl_runtime_c__String torq1;
  rosidl_runtime_c__String pos2;
  rosidl_runtime_c__String vel2;
  rosidl_runtime_c__String torq2;
} tmotor__msg__MotorDebug;

// Struct for a sequence of tmotor__msg__MotorDebug.
typedef struct tmotor__msg__MotorDebug__Sequence
{
  tmotor__msg__MotorDebug * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tmotor__msg__MotorDebug__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TMOTOR__MSG__DETAIL__MOTOR_DEBUG__STRUCT_H_
