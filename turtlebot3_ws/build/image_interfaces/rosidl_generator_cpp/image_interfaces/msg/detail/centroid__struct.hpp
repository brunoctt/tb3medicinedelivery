// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_HPP_
#define IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__image_interfaces__msg__Centroid __attribute__((deprecated))
#else
# define DEPRECATED__image_interfaces__msg__Centroid __declspec(deprecated)
#endif

namespace image_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Centroid_
{
  using Type = Centroid_<ContainerAllocator>;

  explicit Centroid_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
    }
  }

  explicit Centroid_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
    }
  }

  // field types and members
  using _x_type =
    int64_t;
  _x_type x;
  using _y_type =
    int64_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const int64_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int64_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    image_interfaces::msg::Centroid_<ContainerAllocator> *;
  using ConstRawPtr =
    const image_interfaces::msg::Centroid_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<image_interfaces::msg::Centroid_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<image_interfaces::msg::Centroid_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      image_interfaces::msg::Centroid_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::msg::Centroid_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      image_interfaces::msg::Centroid_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::msg::Centroid_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<image_interfaces::msg::Centroid_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<image_interfaces::msg::Centroid_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__image_interfaces__msg__Centroid
    std::shared_ptr<image_interfaces::msg::Centroid_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__image_interfaces__msg__Centroid
    std::shared_ptr<image_interfaces::msg::Centroid_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Centroid_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Centroid_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Centroid_

// alias to use template instance with default allocator
using Centroid =
  image_interfaces::msg::Centroid_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace image_interfaces

#endif  // IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_HPP_
