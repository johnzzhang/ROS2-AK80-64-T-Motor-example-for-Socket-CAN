// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tmotor/msg/detail/motor_cmd__rosidl_typesupport_introspection_c.h"
#include "tmotor/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tmotor/msg/detail/motor_cmd__functions.h"
#include "tmotor/msg/detail/motor_cmd__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tmotor__msg__MotorCmd__init(message_memory);
}

void MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_fini_function(void * message_memory)
{
  tmotor__msg__MotorCmd__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_member_array[6] = {
  {
    "ref1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, ref1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, kp1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, kd1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ref2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, ref2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, kp2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tmotor__msg__MotorCmd, kd2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_members = {
  "tmotor__msg",  // message namespace
  "MotorCmd",  // message name
  6,  // number of fields
  sizeof(tmotor__msg__MotorCmd),
  MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_member_array,  // message members
  MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle = {
  0,
  &MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tmotor
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tmotor, msg, MotorCmd)() {
  if (!MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle.typesupport_identifier) {
    MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
