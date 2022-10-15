// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tmotor:msg/MotorDebug.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_DEBUG__TRAITS_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_DEBUG__TRAITS_HPP_

#include "tmotor/msg/detail/motor_debug__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tmotor::msg::MotorDebug>()
{
  return "tmotor::msg::MotorDebug";
}

template<>
inline const char * name<tmotor::msg::MotorDebug>()
{
  return "tmotor/msg/MotorDebug";
}

template<>
struct has_fixed_size<tmotor::msg::MotorDebug>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tmotor::msg::MotorDebug>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tmotor::msg::MotorDebug>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TMOTOR__MSG__DETAIL__MOTOR_DEBUG__TRAITS_HPP_
