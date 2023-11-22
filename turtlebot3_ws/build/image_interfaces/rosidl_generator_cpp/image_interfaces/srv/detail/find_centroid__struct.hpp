// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from image_interfaces:srv/FindCentroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_HPP_
#define IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__image_interfaces__srv__FindCentroid_Request __attribute__((deprecated))
#else
# define DEPRECATED__image_interfaces__srv__FindCentroid_Request __declspec(deprecated)
#endif

namespace image_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindCentroid_Request_
{
  using Type = FindCentroid_Request_<ContainerAllocator>;

  explicit FindCentroid_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FindCentroid_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__image_interfaces__srv__FindCentroid_Request
    std::shared_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__image_interfaces__srv__FindCentroid_Request
    std::shared_ptr<image_interfaces::srv::FindCentroid_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindCentroid_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindCentroid_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindCentroid_Request_

// alias to use template instance with default allocator
using FindCentroid_Request =
  image_interfaces::srv::FindCentroid_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace image_interfaces


#ifndef _WIN32
# define DEPRECATED__image_interfaces__srv__FindCentroid_Response __attribute__((deprecated))
#else
# define DEPRECATED__image_interfaces__srv__FindCentroid_Response __declspec(deprecated)
#endif

namespace image_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindCentroid_Response_
{
  using Type = FindCentroid_Response_<ContainerAllocator>;

  explicit FindCentroid_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
    }
  }

  explicit FindCentroid_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__image_interfaces__srv__FindCentroid_Response
    std::shared_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__image_interfaces__srv__FindCentroid_Response
    std::shared_ptr<image_interfaces::srv::FindCentroid_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindCentroid_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindCentroid_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindCentroid_Response_

// alias to use template instance with default allocator
using FindCentroid_Response =
  image_interfaces::srv::FindCentroid_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace image_interfaces

namespace image_interfaces
{

namespace srv
{

struct FindCentroid
{
  using Request = image_interfaces::srv::FindCentroid_Request;
  using Response = image_interfaces::srv::FindCentroid_Response;
};

}  // namespace srv

}  // namespace image_interfaces

#endif  // IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_HPP_
