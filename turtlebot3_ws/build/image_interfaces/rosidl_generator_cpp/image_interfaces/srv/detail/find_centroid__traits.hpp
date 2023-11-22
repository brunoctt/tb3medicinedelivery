// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from image_interfaces:srv/FindCentroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__TRAITS_HPP_
#define IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "image_interfaces/srv/detail/find_centroid__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace image_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindCentroid_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindCentroid_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindCentroid_Request & msg, bool use_flow_style = false)
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
  const image_interfaces::srv::FindCentroid_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  image_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use image_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const image_interfaces::srv::FindCentroid_Request & msg)
{
  return image_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<image_interfaces::srv::FindCentroid_Request>()
{
  return "image_interfaces::srv::FindCentroid_Request";
}

template<>
inline const char * name<image_interfaces::srv::FindCentroid_Request>()
{
  return "image_interfaces/srv/FindCentroid_Request";
}

template<>
struct has_fixed_size<image_interfaces::srv::FindCentroid_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<image_interfaces::srv::FindCentroid_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<image_interfaces::srv::FindCentroid_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace image_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindCentroid_Response & msg,
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
  const FindCentroid_Response & msg,
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

inline std::string to_yaml(const FindCentroid_Response & msg, bool use_flow_style = false)
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
  const image_interfaces::srv::FindCentroid_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  image_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use image_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const image_interfaces::srv::FindCentroid_Response & msg)
{
  return image_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<image_interfaces::srv::FindCentroid_Response>()
{
  return "image_interfaces::srv::FindCentroid_Response";
}

template<>
inline const char * name<image_interfaces::srv::FindCentroid_Response>()
{
  return "image_interfaces/srv/FindCentroid_Response";
}

template<>
struct has_fixed_size<image_interfaces::srv::FindCentroid_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<image_interfaces::srv::FindCentroid_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<image_interfaces::srv::FindCentroid_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<image_interfaces::srv::FindCentroid>()
{
  return "image_interfaces::srv::FindCentroid";
}

template<>
inline const char * name<image_interfaces::srv::FindCentroid>()
{
  return "image_interfaces/srv/FindCentroid";
}

template<>
struct has_fixed_size<image_interfaces::srv::FindCentroid>
  : std::integral_constant<
    bool,
    has_fixed_size<image_interfaces::srv::FindCentroid_Request>::value &&
    has_fixed_size<image_interfaces::srv::FindCentroid_Response>::value
  >
{
};

template<>
struct has_bounded_size<image_interfaces::srv::FindCentroid>
  : std::integral_constant<
    bool,
    has_bounded_size<image_interfaces::srv::FindCentroid_Request>::value &&
    has_bounded_size<image_interfaces::srv::FindCentroid_Response>::value
  >
{
};

template<>
struct is_service<image_interfaces::srv::FindCentroid>
  : std::true_type
{
};

template<>
struct is_service_request<image_interfaces::srv::FindCentroid_Request>
  : std::true_type
{
};

template<>
struct is_service_response<image_interfaces::srv::FindCentroid_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__TRAITS_HPP_
