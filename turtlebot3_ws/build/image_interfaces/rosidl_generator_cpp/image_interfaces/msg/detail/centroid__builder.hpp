// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__MSG__DETAIL__CENTROID__BUILDER_HPP_
#define IMAGE_INTERFACES__MSG__DETAIL__CENTROID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "image_interfaces/msg/detail/centroid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace image_interfaces
{

namespace msg
{

namespace builder
{

class Init_Centroid_y
{
public:
  explicit Init_Centroid_y(::image_interfaces::msg::Centroid & msg)
  : msg_(msg)
  {}
  ::image_interfaces::msg::Centroid y(::image_interfaces::msg::Centroid::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::image_interfaces::msg::Centroid msg_;
};

class Init_Centroid_x
{
public:
  Init_Centroid_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Centroid_y x(::image_interfaces::msg::Centroid::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Centroid_y(msg_);
  }

private:
  ::image_interfaces::msg::Centroid msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::image_interfaces::msg::Centroid>()
{
  return image_interfaces::msg::builder::Init_Centroid_x();
}

}  // namespace image_interfaces

#endif  // IMAGE_INTERFACES__MSG__DETAIL__CENTROID__BUILDER_HPP_
