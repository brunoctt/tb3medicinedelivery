// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from image_interfaces:srv/Movement.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__STRUCT_H_
#define IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Movement in the package image_interfaces.
typedef struct image_interfaces__srv__Movement_Request
{
  uint8_t structure_needs_at_least_one_member;
} image_interfaces__srv__Movement_Request;

// Struct for a sequence of image_interfaces__srv__Movement_Request.
typedef struct image_interfaces__srv__Movement_Request__Sequence
{
  image_interfaces__srv__Movement_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_interfaces__srv__Movement_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Movement in the package image_interfaces.
typedef struct image_interfaces__srv__Movement_Response
{
  double relative_centroid;
  bool intersection;
} image_interfaces__srv__Movement_Response;

// Struct for a sequence of image_interfaces__srv__Movement_Response.
typedef struct image_interfaces__srv__Movement_Response__Sequence
{
  image_interfaces__srv__Movement_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_interfaces__srv__Movement_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IMAGE_INTERFACES__SRV__DETAIL__MOVEMENT__STRUCT_H_
