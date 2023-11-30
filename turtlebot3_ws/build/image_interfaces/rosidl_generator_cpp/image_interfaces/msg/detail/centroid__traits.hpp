// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__MSG__DETAIL__CENTROID__TRAITS_HPP_
#define IMAGE_INTERFACES__MSG__DETAIL__CENTROID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "image_interfaces/msg/detail/centroid__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace image_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Centroid & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Centroid & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Centroid & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace image_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use image_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const image_interfaces::msg::Centroid & msg,
  std::ostream & out, size_t indentation = 0)
{
  image_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use image_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const image_interfaces::msg::Centroid & msg)
{
  return image_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<image_interfaces::msg::Centroid>()
{
  return "image_interfaces::msg::Centroid";
}

template<>
inline const char * name<image_interfaces::msg::Centroid>()
{
  return "image_interfaces/msg/Centroid";
}

template<>
struct has_fixed_size<image_interfaces::msg::Centroid>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<image_interfaces::msg::Centroid>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<image_interfaces::msg::Centroid>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IMAGE_INTERFACES__MSG__DETAIL__CENTROID__TRAITS_HPP_
