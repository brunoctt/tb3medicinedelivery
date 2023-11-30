// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_H_
#define IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Centroid in the package image_interfaces.
typedef struct image_interfaces__msg__Centroid
{
  int64_t x;
  int64_t y;
} image_interfaces__msg__Centroid;

// Struct for a sequence of image_interfaces__msg__Centroid.
typedef struct image_interfaces__msg__Centroid__Sequence
{
  image_interfaces__msg__Centroid * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_interfaces__msg__Centroid__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IMAGE_INTERFACES__MSG__DETAIL__CENTROID__STRUCT_H_
