// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tmotor:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_

#include "tmotor/msg/detail/motor_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tmotor
{

namespace msg
{

namespace builder
{

class Init_MotorOutput_torq2
{
public:
  explicit Init_MotorOutput_torq2(::tmotor::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  ::tmotor::msg::MotorOutput torq2(::tmotor::msg::MotorOutput::_torq2_type arg)
  {
    msg_.torq2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

class Init_MotorOutput_vel2
{
public:
  explicit Init_MotorOutput_vel2(::tmotor::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  Init_MotorOutput_torq2 vel2(::tmotor::msg::MotorOutput::_vel2_type arg)
  {
    msg_.vel2 = std::move(arg);
    return Init_MotorOutput_torq2(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

class Init_MotorOutput_pos2
{
public:
  explicit Init_MotorOutput_pos2(::tmotor::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  Init_MotorOutput_vel2 pos2(::tmotor::msg::MotorOutput::_pos2_type arg)
  {
    msg_.pos2 = std::move(arg);
    return Init_MotorOutput_vel2(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

class Init_MotorOutput_torq1
{
public:
  explicit Init_MotorOutput_torq1(::tmotor::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  Init_MotorOutput_pos2 torq1(::tmotor::msg::MotorOutput::_torq1_type arg)
  {
    msg_.torq1 = std::move(arg);
    return Init_MotorOutput_pos2(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

class Init_MotorOutput_vel1
{
public:
  explicit Init_MotorOutput_vel1(::tmotor::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  Init_MotorOutput_torq1 vel1(::tmotor::msg::MotorOutput::_vel1_type arg)
  {
    msg_.vel1 = std::move(arg);
    return Init_MotorOutput_torq1(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

class Init_MotorOutput_pos1
{
public:
  Init_MotorOutput_pos1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorOutput_vel1 pos1(::tmotor::msg::MotorOutput::_pos1_type arg)
  {
    msg_.pos1 = std::move(arg);
    return Init_MotorOutput_vel1(msg_);
  }

private:
  ::tmotor::msg::MotorOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tmotor::msg::MotorOutput>()
{
  return tmotor::msg::builder::Init_MotorOutput_pos1();
}

}  // namespace tmotor

#endif  // TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_
