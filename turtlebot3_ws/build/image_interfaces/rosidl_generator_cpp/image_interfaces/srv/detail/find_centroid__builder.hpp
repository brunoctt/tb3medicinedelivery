// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from image_interfaces:srv/FindCentroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__BUILDER_HPP_
#define IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "image_interfaces/srv/detail/find_centroid__struct.hpp"
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
auto build<::image_interfaces::srv::FindCentroid_Request>()
{
  return ::image_interfaces::srv::FindCentroid_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace image_interfaces


namespace image_interfaces
{

namespace srv
{

namespace builder
{

class Init_FindCentroid_Response_y
{
public:
  explicit Init_FindCentroid_Response_y(::image_interfaces::srv::FindCentroid_Response & msg)
  : msg_(msg)
  {}
  ::image_interfaces::srv::FindCentroid_Response y(::image_interfaces::srv::FindCentroid_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::image_interfaces::srv::FindCentroid_Response msg_;
};

class Init_FindCentroid_Response_x
{
public:
  Init_FindCentroid_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FindCentroid_Response_y x(::image_interfaces::srv::FindCentroid_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_FindCentroid_Response_y(msg_);
  }

private:
  ::image_interfaces::srv::FindCentroid_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::image_interfaces::srv::FindCentroid_Response>()
{
  return image_interfaces::srv::builder::Init_FindCentroid_Response_x();
}

}  // namespace image_interfaces

#endif  // IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__BUILDER_HPP_
