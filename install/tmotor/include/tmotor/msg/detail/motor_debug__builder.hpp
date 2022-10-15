// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tmotor:msg/MotorDebug.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_DEBUG__BUILDER_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_DEBUG__BUILDER_HPP_

#include "tmotor/msg/detail/motor_debug__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tmotor
{

namespace msg
{

namespace builder
{

class Init_MotorDebug_torq2
{
public:
  explicit Init_MotorDebug_torq2(::tmotor::msg::MotorDebug & msg)
  : msg_(msg)
  {}
  ::tmotor::msg::MotorDebug torq2(::tmotor::msg::MotorDebug::_torq2_type arg)
  {
    msg_.torq2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

class Init_MotorDebug_vel2
{
public:
  explicit Init_MotorDebug_vel2(::tmotor::msg::MotorDebug & msg)
  : msg_(msg)
  {}
  Init_MotorDebug_torq2 vel2(::tmotor::msg::MotorDebug::_vel2_type arg)
  {
    msg_.vel2 = std::move(arg);
    return Init_MotorDebug_torq2(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

class Init_MotorDebug_pos2
{
public:
  explicit Init_MotorDebug_pos2(::tmotor::msg::MotorDebug & msg)
  : msg_(msg)
  {}
  Init_MotorDebug_vel2 pos2(::tmotor::msg::MotorDebug::_pos2_type arg)
  {
    msg_.pos2 = std::move(arg);
    return Init_MotorDebug_vel2(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

class Init_MotorDebug_torq1
{
public:
  explicit Init_MotorDebug_torq1(::tmotor::msg::MotorDebug & msg)
  : msg_(msg)
  {}
  Init_MotorDebug_pos2 torq1(::tmotor::msg::MotorDebug::_torq1_type arg)
  {
    msg_.torq1 = std::move(arg);
    return Init_MotorDebug_pos2(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

class Init_MotorDebug_vel1
{
public:
  explicit Init_MotorDebug_vel1(::tmotor::msg::MotorDebug & msg)
  : msg_(msg)
  {}
  Init_MotorDebug_torq1 vel1(::tmotor::msg::MotorDebug::_vel1_type arg)
  {
    msg_.vel1 = std::move(arg);
    return Init_MotorDebug_torq1(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

class Init_MotorDebug_pos1
{
public:
  Init_MotorDebug_pos1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorDebug_vel1 pos1(::tmotor::msg::MotorDebug::_pos1_type arg)
  {
    msg_.pos1 = std::move(arg);
    return Init_MotorDebug_vel1(msg_);
  }

private:
  ::tmotor::msg::MotorDebug msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tmotor::msg::MotorDebug>()
{
  return tmotor::msg::builder::Init_MotorDebug_pos1();
}

}  // namespace tmotor

#endif  // TMOTOR__MSG__DETAIL__MOTOR_DEBUG__BUILDER_HPP_
