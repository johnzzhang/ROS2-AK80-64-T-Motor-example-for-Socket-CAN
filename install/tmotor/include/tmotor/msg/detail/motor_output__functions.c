// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tmotor:msg/MotorOutput.idl
// generated code does not contain a copyright notice
#include "tmotor/msg/detail/motor_output__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
tmotor__msg__MotorOutput__init(tmotor__msg__MotorOutput * msg)
{
  if (!msg) {
    return false;
  }
  // pos1
  // vel1
  // torq1
  // pos2
  // vel2
  // torq2
  return true;
}

void
tmotor__msg__MotorOutput__fini(tmotor__msg__MotorOutput * msg)
{
  if (!msg) {
    return;
  }
  // pos1
  // vel1
  // torq1
  // pos2
  // vel2
  // torq2
}

tmotor__msg__MotorOutput *
tmotor__msg__MotorOutput__create()
{
  tmotor__msg__MotorOutput * msg = (tmotor__msg__MotorOutput *)malloc(sizeof(tmotor__msg__MotorOutput));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tmotor__msg__MotorOutput));
  bool success = tmotor__msg__MotorOutput__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tmotor__msg__MotorOutput__destroy(tmotor__msg__MotorOutput * msg)
{
  if (msg) {
    tmotor__msg__MotorOutput__fini(msg);
  }
  free(msg);
}


bool
tmotor__msg__MotorOutput__Sequence__init(tmotor__msg__MotorOutput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tmotor__msg__MotorOutput * data = NULL;
  if (size) {
    data = (tmotor__msg__MotorOutput *)calloc(size, sizeof(tmotor__msg__MotorOutput));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tmotor__msg__MotorOutput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tmotor__msg__MotorOutput__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tmotor__msg__MotorOutput__Sequence__fini(tmotor__msg__MotorOutput__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tmotor__msg__MotorOutput__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tmotor__msg__MotorOutput__Sequence *
tmotor__msg__MotorOutput__Sequence__create(size_t size)
{
  tmotor__msg__MotorOutput__Sequence * array = (tmotor__msg__MotorOutput__Sequence *)malloc(sizeof(tmotor__msg__MotorOutput__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tmotor__msg__MotorOutput__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tmotor__msg__MotorOutput__Sequence__destroy(tmotor__msg__MotorOutput__Sequence * array)
{
  if (array) {
    tmotor__msg__MotorOutput__Sequence__fini(array);
  }
  free(array);
}
