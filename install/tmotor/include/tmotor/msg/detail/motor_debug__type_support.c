// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tmotor:msg/MotorDebug.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tmotor/msg/detail/motor_debug__rosidl_typesupport_introspection_c.h"
#include "tmotor/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tmotor/msg/detail/motor_debug__functions.h"
#include "tmotor/msg/detail/motor_debug__struct.h"


// Include directives for member types
// Member `pos1`
// Member `vel1`
// Member `torq1`
// Member `pos2`
// Member `vel2`
// Member `torq2`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tmotor__msg__MotorDebug__init(message_memory);
}

void MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_fini_function(void * message_memory)
{
  tmotor__msg__MotorDebug__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_member_array[6] = {
  {
    "pos1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, pos1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, vel1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "torq1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, torq1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, pos2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, vel2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "torq2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorDebug, torq2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_members = {
  "tmotor__msg",  // message namespace
  "MotorDebug",  // message name
  6,  // number of fields
  sizeof(tmotor__msg__MotorDebug),
  MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_member_array,  // message members
  MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_type_support_handle = {
  0,
  &MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tmotor
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tmotor, msg, MotorDebug)() {
  if (!MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_type_support_handle.typesupport_identifier) {
    MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MotorDebug__rosidl_typesupport_introspection_c__MotorDebug_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
