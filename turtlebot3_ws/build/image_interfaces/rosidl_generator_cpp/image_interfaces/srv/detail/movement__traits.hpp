// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from image_interfaces:srv/Movement.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__TRAITS_HPP_
#define IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "image_interfaces/srv/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace image_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Movement_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movement_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movement_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace image_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use image_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const image_interfaces::srv::Movement_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  image_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use image_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const image_interfaces::srv::Movement_Request & msg)
{
  return image_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<image_interfaces::srv::Movement_Request>()
{
  return "image_interfaces::srv::Movement_Request";
}

template<>
inline const char * name<image_interfaces::srv::Movement_Request>()
{
  return "image_interfaces/srv/Movement_Request";
}

template<>
struct has_fixed_size<image_interfaces::srv::Movement_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<image_interfaces::srv::Movement_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<image_interfaces::srv::Movement_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace image_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Movement_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: relative_centroid
  {
    out << "relative_centroid: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_centroid, out);
    out << ", ";
  }

  // member: intersection
  {
    out << "intersection: ";
    rosidl_generator_traits::value_to_yaml(msg.intersection, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movement_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: relative_centroid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_centroid: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_centroid, out);
    out << "\n";
  }

  // member: intersection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intersection: ";
    rosidl_generator_traits::value_to_yaml(msg.intersection, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movement_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace image_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use image_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const image_interfaces::srv::Movement_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  image_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use image_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const image_interfaces::srv::Movement_Response & msg)
{
  return image_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<image_interfaces::srv::Movement_Response>()
{
  return "image_interfaces::srv::Movement_Response";
}

template<>
inline const char * name<image_interfaces::srv::Movement_Response>()
{
  return "image_interfaces/srv/Movement_Response";
}

template<>
struct has_fixed_size<image_interfaces::srv::Movement_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<image_interfaces::srv::Movement_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<image_interfaces::srv::Movement_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<image_interfaces::srv::Movement>()
{
  return "image_interfaces::srv::Movement";
}

template<>
inline const char * name<image_interfaces::srv::Movement>()
{
  return "image_interfaces/srv/Movement";
}

template<>
struct has_fixed_size<image_interfaces::srv::Movement>
  : std::integral_constant<
    bool,
    has_fixed_size<image_interfaces::srv::Movement_Request>::value &&
    has_fixed_size<image_interfaces::srv::Movement_Response>::value
  >
{
};

template<>
struct has_bounded_size<image_interfaces::srv::Movement>
  : std::integral_constant<
    bool,
    has_bounded_size<image_interfaces::srv::Movement_Request>::value &&
    has_bounded_size<image_interfaces::srv::Movement_Response>::value
  >
{
};

template<>
struct is_service<image_interfaces::srv::Movement>
  : std::true_type
{
};

template<>
struct is_service_request<image_interfaces::srv::Movement_Request>
  : std::true_type
{
};

template<>
struct is_service_response<image_interfaces::srv::Movement_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__TRAITS_HPP_
