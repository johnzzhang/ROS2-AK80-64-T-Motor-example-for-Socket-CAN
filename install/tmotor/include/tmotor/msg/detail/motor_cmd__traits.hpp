// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_

#include "tmotor/msg/detail/motor_cmd__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tmotor::msg::MotorCmd>()
{
  return "tmotor::msg::MotorCmd";
}

template<>
inline const char * name<tmotor::msg::MotorCmd>()
{
  return "tmotor/msg/MotorCmd";
}

template<>
struct has_fixed_size<tmotor::msg::MotorCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tmotor::msg::MotorCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tmotor::msg::MotorCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TMOTOR__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_
