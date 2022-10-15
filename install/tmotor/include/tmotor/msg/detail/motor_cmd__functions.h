// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_CMD__FUNCTIONS_H_
#define TMOTOR__MSG__DETAIL__MOTOR_CMD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tmotor/msg/rosidl_generator_c__visibility_control.h"

#include "tmotor/msg/detail/motor_cmd__struct.h"

/// Initialize msg/MotorCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tmotor__msg__MotorCmd
 * )) before or use
 * tmotor__msg__MotorCmd__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
bool
tmotor__msg__MotorCmd__init(tmotor__msg__MotorCmd * msg);

/// Finalize msg/MotorCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
void
tmotor__msg__MotorCmd__fini(tmotor__msg__MotorCmd * msg);

/// Create msg/MotorCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tmotor__msg__MotorCmd__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
tmotor__msg__MotorCmd *
tmotor__msg__MotorCmd__create();

/// Destroy msg/MotorCmd message.
/**
 * It calls
 * tmotor__msg__MotorCmd__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
void
tmotor__msg__MotorCmd__destroy(tmotor__msg__MotorCmd * msg);


/// Initialize array of msg/MotorCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * tmotor__msg__MotorCmd__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
bool
tmotor__msg__MotorCmd__Sequence__init(tmotor__msg__MotorCmd__Sequence * array, size_t size);

/// Finalize array of msg/MotorCmd messages.
/**
 * It calls
 * tmotor__msg__MotorCmd__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
void
tmotor__msg__MotorCmd__Sequence__fini(tmotor__msg__MotorCmd__Sequence * array);

/// Create array of msg/MotorCmd messages.
/**
 * It allocates the memory for the array and calls
 * tmotor__msg__MotorCmd__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
tmotor__msg__MotorCmd__Sequence *
tmotor__msg__MotorCmd__Sequence__create(size_t size);

/// Destroy array of msg/MotorCmd messages.
/**
 * It calls
 * tmotor__msg__MotorCmd__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tmotor
void
tmotor__msg__MotorCmd__Sequence__destroy(tmotor__msg__MotorCmd__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TMOTOR__MSG__DETAIL__MOTOR_CMD__FUNCTIONS_H_
