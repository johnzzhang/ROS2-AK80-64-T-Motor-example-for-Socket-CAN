// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice
#include "tmotor/msg/detail/motor_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
tmotor__msg__MotorCmd__init(tmotor__msg__MotorCmd * msg)
{
  if (!msg) {
    return false;
  }
  // ref1
  // kp1
  // kd1
  // ref2
  // kp2
  // kd2
  return true;
}

void
tmotor__msg__MotorCmd__fini(tmotor__msg__MotorCmd * msg)
{
  if (!msg) {
    return;
  }
  // ref1
  // kp1
  // kd1
  // ref2
  // kp2
  // kd2
}

tmotor__msg__MotorCmd *
tmotor__msg__MotorCmd__create()
{
  tmotor__msg__MotorCmd * msg = (tmotor__msg__MotorCmd *)malloc(sizeof(tmotor__msg__MotorCmd));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tmotor__msg__MotorCmd));
  bool success = tmotor__msg__MotorCmd__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tmotor__msg__MotorCmd__destroy(tmotor__msg__MotorCmd * msg)
{
  if (msg) {
    tmotor__msg__MotorCmd__fini(msg);
  }
  free(msg);
}


bool
tmotor__msg__MotorCmd__Sequence__init(tmotor__msg__MotorCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tmotor__msg__MotorCmd * data = NULL;
  if (size) {
    data = (tmotor__msg__MotorCmd *)calloc(size, sizeof(tmotor__msg__MotorCmd));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tmotor__msg__MotorCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tmotor__msg__MotorCmd__fini(&data[i - 1]);
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
tmotor__msg__MotorCmd__Sequence__fini(tmotor__msg__MotorCmd__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tmotor__msg__MotorCmd__fini(&array->data[i]);
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

tmotor__msg__MotorCmd__Sequence *
tmotor__msg__MotorCmd__Sequence__create(size_t size)
{
  tmotor__msg__MotorCmd__Sequence * array = (tmotor__msg__MotorCmd__Sequence *)malloc(sizeof(tmotor__msg__MotorCmd__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tmotor__msg__MotorCmd__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tmotor__msg__MotorCmd__Sequence__destroy(tmotor__msg__MotorCmd__Sequence * array)
{
  if (array) {
    tmotor__msg__MotorCmd__Sequence__fini(array);
  }
  free(array);
}
