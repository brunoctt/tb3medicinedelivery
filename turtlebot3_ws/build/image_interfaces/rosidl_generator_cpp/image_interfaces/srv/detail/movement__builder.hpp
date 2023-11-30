// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from image_interfaces:srv/Movement.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__BUILDER_HPP_
#define IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "image_interfaces/srv/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace image_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::image_interfaces::srv::Movement_Request>()
{
  return ::image_interfaces::srv::Movement_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace image_interfaces


namespace image_interfaces
{

namespace srv
{

namespace builder
{

class Init_Movement_Response_intersection
{
public:
  explicit Init_Movement_Response_intersection(::image_interfaces::srv::Movement_Response & msg)
  : msg_(msg)
  {}
  ::image_interfaces::srv::Movement_Response intersection(::image_interfaces::srv::Movement_Response::_intersection_type arg)
  {
    msg_.intersection = std::move(arg);
    return std::move(msg_);
  }

private:
  ::image_interfaces::srv::Movement_Response msg_;
};

class Init_Movement_Response_relative_centroid
{
public:
  Init_Movement_Response_relative_centroid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movement_Response_intersection relative_centroid(::image_interfaces::srv::Movement_Response::_relative_centroid_type arg)
  {
    msg_.relative_centroid = std::move(arg);
    return Init_Movement_Response_intersection(msg_);
  }

private:
  ::image_interfaces::srv::Movement_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::image_interfaces::srv::Movement_Response>()
{
  return image_interfaces::srv::builder::Init_Movement_Response_relative_centroid();
}

}  // namespace image_interfaces

#endif  // IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__BUILDER_HPP_
