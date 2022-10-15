// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_

#include "tmotor/msg/detail/motor_cmd__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tmotor
{

namespace msg
{

namespace builder
{

class Init_MotorCmd_kd2
{
public:
  explicit Init_MotorCmd_kd2(::tmotor::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  ::tmotor::msg::MotorCmd kd2(::tmotor::msg::MotorCmd::_kd2_type arg)
  {
    msg_.kd2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

class Init_MotorCmd_kp2
{
public:
  explicit Init_MotorCmd_kp2(::tmotor::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_kd2 kp2(::tmotor::msg::MotorCmd::_kp2_type arg)
  {
    msg_.kp2 = std::move(arg);
    return Init_MotorCmd_kd2(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

class Init_MotorCmd_ref2
{
public:
  explicit Init_MotorCmd_ref2(::tmotor::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_kp2 ref2(::tmotor::msg::MotorCmd::_ref2_type arg)
  {
    msg_.ref2 = std::move(arg);
    return Init_MotorCmd_kp2(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

class Init_MotorCmd_kd1
{
public:
  explicit Init_MotorCmd_kd1(::tmotor::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_ref2 kd1(::tmotor::msg::MotorCmd::_kd1_type arg)
  {
    msg_.kd1 = std::move(arg);
    return Init_MotorCmd_ref2(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

class Init_MotorCmd_kp1
{
public:
  explicit Init_MotorCmd_kp1(::tmotor::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_kd1 kp1(::tmotor::msg::MotorCmd::_kp1_type arg)
  {
    msg_.kp1 = std::move(arg);
    return Init_MotorCmd_kd1(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

class Init_MotorCmd_ref1
{
public:
  Init_MotorCmd_ref1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCmd_kp1 ref1(::tmotor::msg::MotorCmd::_ref1_type arg)
  {
    msg_.ref1 = std::move(arg);
    return Init_MotorCmd_kp1(msg_);
  }

private:
  ::tmotor::msg::MotorCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tmotor::msg::MotorCmd>()
{
  return tmotor::msg::builder::Init_MotorCmd_ref1();
}

}  // namespace tmotor

#endif  // TMOTOR__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_
