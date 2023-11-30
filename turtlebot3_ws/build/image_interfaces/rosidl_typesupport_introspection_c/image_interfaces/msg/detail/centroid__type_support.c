// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "image_interfaces/msg/detail/centroid__rosidl_typesupport_introspection_c.h"
#include "image_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "image_interfaces/msg/detail/centroid__functions.h"
#include "image_interfaces/msg/detail/centroid__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  image_interfaces__msg__Centroid__init(message_memory);
}

void image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_fini_function(void * message_memory)
{
  image_interfaces__msg__Centroid__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_interfaces__msg__Centroid, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_interfaces__msg__Centroid, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_members = {
  "image_interfaces__msg",  // message namespace
  "Centroid",  // message name
  2,  // number of fields
  sizeof(image_interfaces__msg__Centroid),
  image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_member_array,  // message members
  image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_init_function,  // function to initialize message memory (memory has to be allocated)
  image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_type_support_handle = {
  0,
  &image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_image_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, image_interfaces, msg, Centroid)() {
  if (!image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_type_support_handle.typesupport_identifier) {
    image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &image_interfaces__msg__Centroid__rosidl_typesupport_introspection_c__Centroid_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
