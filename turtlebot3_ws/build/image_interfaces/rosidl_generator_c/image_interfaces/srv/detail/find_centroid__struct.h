// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from image_interfaces:srv/FindCentroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_H_
#define IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/FindCentroid in the package image_interfaces.
typedef struct image_interfaces__srv__FindCentroid_Request
{
  uint8_t structure_needs_at_least_one_member;
} image_interfaces__srv__FindCentroid_Request;

// Struct for a sequence of image_interfaces__srv__FindCentroid_Request.
typedef struct image_interfaces__srv__FindCentroid_Request__Sequence
{
  image_interfaces__srv__FindCentroid_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_interfaces__srv__FindCentroid_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FindCentroid in the package image_interfaces.
typedef struct image_interfaces__srv__FindCentroid_Response
{
  int64_t x;
  int64_t y;
} image_interfaces__srv__FindCentroid_Response;

// Struct for a sequence of image_interfaces__srv__FindCentroid_Response.
typedef struct image_interfaces__srv__FindCentroid_Response__Sequence
{
  image_interfaces__srv__FindCentroid_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_interfaces__srv__FindCentroid_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IMAGE_INTERFACES__SRV__DETAIL__FIND_CENTROID__STRUCT_H_
