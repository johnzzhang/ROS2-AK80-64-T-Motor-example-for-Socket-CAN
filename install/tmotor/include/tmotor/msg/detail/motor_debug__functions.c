// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tmotor:msg/MotorDebug.idl
// generated code does not contain a copyright notice
#include "tmotor/msg/detail/motor_debug__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `pos1`
// Member `vel1`
// Member `torq1`
// Member `pos2`
// Member `vel2`
// Member `torq2`
#include "rosidl_runtime_c/string_functions.h"

bool
tmotor__msg__MotorDebug__init(tmotor__msg__MotorDebug * msg)
{
  if (!msg) {
    return false;
  }
  // pos1
  if (!rosidl_runtime_c__String__init(&msg->pos1)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  // vel1
  if (!rosidl_runtime_c__String__init(&msg->vel1)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  // torq1
  if (!rosidl_runtime_c__String__init(&msg->torq1)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  // pos2
  if (!rosidl_runtime_c__String__init(&msg->pos2)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  // vel2
  if (!rosidl_runtime_c__String__init(&msg->vel2)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  // torq2
  if (!rosidl_runtime_c__String__init(&msg->torq2)) {
    tmotor__msg__MotorDebug__fini(msg);
    return false;
  }
  return true;
}

void
tmotor__msg__MotorDebug__fini(tmotor__msg__MotorDebug * msg)
{
  if (!msg) {
    return;
  }
  // pos1
  rosidl_runtime_c__String__fini(&msg->pos1);
  // vel1
  rosidl_runtime_c__String__fini(&msg->vel1);
  // torq1
  rosidl_runtime_c__String__fini(&msg->torq1);
  // pos2
  rosidl_runtime_c__String__fini(&msg->pos2);
  // vel2
  rosidl_runtime_c__String__fini(&msg->vel2);
  // torq2
  rosidl_runtime_c__String__fini(&msg->torq2);
}

tmotor__msg__MotorDebug *
tmotor__msg__MotorDebug__create()
{
  tmotor__msg__MotorDebug * msg = (tmotor__msg__MotorDebug *)malloc(sizeof(tmotor__msg__MotorDebug));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tmotor__msg__MotorDebug));
  bool success = tmotor__msg__MotorDebug__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tmotor__msg__MotorDebug__destroy(tmotor__msg__MotorDebug * msg)
{
  if (msg) {
    tmotor__msg__MotorDebug__fini(msg);
  }
  free(msg);
}


bool
tmotor__msg__MotorDebug__Sequence__init(tmotor__msg__MotorDebug__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tmotor__msg__MotorDebug * data = NULL;
  if (size) {
    data = (tmotor__msg__MotorDebug *)calloc(size, sizeof(tmotor__msg__MotorDebug));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tmotor__msg__MotorDebug__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tmotor__msg__MotorDebug__fini(&data[i - 1]);
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
tmotor__msg__MotorDebug__Sequence__fini(tmotor__msg__MotorDebug__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tmotor__msg__MotorDebug__fini(&array->data[i]);
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

tmotor__msg__MotorDebug__Sequence *
tmotor__msg__MotorDebug__Sequence__create(size_t size)
{
  tmotor__msg__MotorDebug__Sequence * array = (tmotor__msg__MotorDebug__Sequence *)malloc(sizeof(tmotor__msg__MotorDebug__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tmotor__msg__MotorDebug__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tmotor__msg__MotorDebug__Sequence__destroy(tmotor__msg__MotorDebug__Sequence * array)
{
  if (array) {
    tmotor__msg__MotorDebug__Sequence__fini(array);
  }
  free(array);
}
