// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tmotor:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_
#define TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tmotor__msg__MotorOutput __attribute__((deprecated))
#else
# define DEPRECATED__tmotor__msg__MotorOutput __declspec(deprecated)
#endif

namespace tmotor
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorOutput_
{
  using Type = MotorOutput_<ContainerAllocator>;

  explicit MotorOutput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos1 = 0.0f;
      this->vel1 = 0.0f;
      this->torq1 = 0.0f;
      this->pos2 = 0.0f;
      this->vel2 = 0.0f;
      this->torq2 = 0.0f;
    }
  }

  explicit MotorOutput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos1 = 0.0f;
      this->vel1 = 0.0f;
      this->torq1 = 0.0f;
      this->pos2 = 0.0f;
      this->vel2 = 0.0f;
      this->torq2 = 0.0f;
    }
  }

  // field types and members
  using _pos1_type =
    float;
  _pos1_type pos1;
  using _vel1_type =
    float;
  _vel1_type vel1;
  using _torq1_type =
    float;
  _torq1_type torq1;
  using _pos2_type =
    float;
  _pos2_type pos2;
  using _vel2_type =
    float;
  _vel2_type vel2;
  using _torq2_type =
    float;
  _torq2_type torq2;

  // setters for named parameter idiom
  Type & set__pos1(
    const float & _arg)
  {
    this->pos1 = _arg;
    return *this;
  }
  Type & set__vel1(
    const float & _arg)
  {
    this->vel1 = _arg;
    return *this;
  }
  Type & set__torq1(
    const float & _arg)
  {
    this->torq1 = _arg;
    return *this;
  }
  Type & set__pos2(
    const float & _arg)
  {
    this->pos2 = _arg;
    return *this;
  }
  Type & set__vel2(
    const float & _arg)
  {
    this->vel2 = _arg;
    return *this;
  }
  Type & set__torq2(
    const float & _arg)
  {
    this->torq2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tmotor::msg::MotorOutput_<ContainerAllocator> *;
  using ConstRawPtr =
    const tmotor::msg::MotorOutput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tmotor::msg::MotorOutput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tmotor::msg::MotorOutput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tmotor::msg::MotorOutput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tmotor::msg::MotorOutput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tmotor::msg::MotorOutput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tmotor::msg::MotorOutput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tmotor::msg::MotorOutput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tmotor::msg::MotorOutput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tmotor__msg__MotorOutput
    std::shared_ptr<tmotor::msg::MotorOutput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tmotor__msg__MotorOutput
    std::shared_ptr<tmotor::msg::MotorOutput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorOutput_ & other) const
  {
    if (this->pos1 != other.pos1) {
      return false;
    }
    if (this->vel1 != other.vel1) {
      return false;
    }
    if (this->torq1 != other.torq1) {
      return false;
    }
    if (this->pos2 != other.pos2) {
      return false;
    }
    if (this->vel2 != other.vel2) {
      return false;
    }
    if (this->torq2 != other.torq2) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorOutput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorOutput_

// alias to use template instance with default allocator
using MotorOutput =
  tmotor::msg::MotorOutput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tmotor

#endif  // TMOTOR__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_
