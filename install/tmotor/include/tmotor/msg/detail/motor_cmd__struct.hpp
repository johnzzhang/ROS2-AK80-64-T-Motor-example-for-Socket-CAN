// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tmotor:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tmotor__msg__MotorCmd __attribute__((deprecated))
#else
# define DEPRECATED__tmotor__msg__MotorCmd __declspec(deprecated)
#endif

namespace tmotor
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCmd_
{
  using Type = MotorCmd_<ContainerAllocator>;

  explicit MotorCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ref1 = 0.0f;
      this->kp1 = 0.0f;
      this->kd1 = 0.0f;
      this->ref2 = 0.0f;
      this->kp2 = 0.0f;
      this->kd2 = 0.0f;
    }
  }

  explicit MotorCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ref1 = 0.0f;
      this->kp1 = 0.0f;
      this->kd1 = 0.0f;
      this->ref2 = 0.0f;
      this->kp2 = 0.0f;
      this->kd2 = 0.0f;
    }
  }

  // field types and members
  using _ref1_type =
    float;
  _ref1_type ref1;
  using _kp1_type =
    float;
  _kp1_type kp1;
  using _kd1_type =
    float;
  _kd1_type kd1;
  using _ref2_type =
    float;
  _ref2_type ref2;
  using _kp2_type =
    float;
  _kp2_type kp2;
  using _kd2_type =
    float;
  _kd2_type kd2;

  // setters for named parameter idiom
  Type & set__ref1(
    const float & _arg)
  {
    this->ref1 = _arg;
    return *this;
  }
  Type & set__kp1(
    const float & _arg)
  {
    this->kp1 = _arg;
    return *this;
  }
  Type & set__kd1(
    const float & _arg)
  {
    this->kd1 = _arg;
    return *this;
  }
  Type & set__ref2(
    const float & _arg)
  {
    this->ref2 = _arg;
    return *this;
  }
  Type & set__kp2(
    const float & _arg)
  {
    this->kp2 = _arg;
    return *this;
  }
  Type & set__kd2(
    const float & _arg)
  {
    this->kd2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tmotor::msg::MotorCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const tmotor::msg::MotorCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tmotor::msg::MotorCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tmotor::msg::MotorCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tmotor::msg::MotorCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tmotor::msg::MotorCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tmotor::msg::MotorCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tmotor::msg::MotorCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tmotor::msg::MotorCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tmotor::msg::MotorCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tmotor__msg__MotorCmd
    std::shared_ptr<tmotor::msg::MotorCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tmotor__msg__MotorCmd
    std::shared_ptr<tmotor::msg::MotorCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCmd_ & other) const
  {
    if (this->ref1 != other.ref1) {
      return false;
    }
    if (this->kp1 != other.kp1) {
      return false;
    }
    if (this->kd1 != other.kd1) {
      return false;
    }
    if (this->ref2 != other.ref2) {
      return false;
    }
    if (this->kp2 != other.kp2) {
      return false;
    }
    if (this->kd2 != other.kd2) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCmd_

// alias to use template instance with default allocator
using MotorCmd =
  tmotor::msg::MotorCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tmotor

#endif  // TMOTOR__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_
