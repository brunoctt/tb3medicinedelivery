// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from image_interfaces:msg/Centroid.idl
// generated code does not contain a copyright notice
#include "image_interfaces/msg/detail/centroid__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
image_interfaces__msg__Centroid__init(image_interfaces__msg__Centroid * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
image_interfaces__msg__Centroid__fini(image_interfaces__msg__Centroid * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
image_interfaces__msg__Centroid__are_equal(const image_interfaces__msg__Centroid * lhs, const image_interfaces__msg__Centroid * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
image_interfaces__msg__Centroid__copy(
  const image_interfaces__msg__Centroid * input,
  image_interfaces__msg__Centroid * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

image_interfaces__msg__Centroid *
image_interfaces__msg__Centroid__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__msg__Centroid * msg = (image_interfaces__msg__Centroid *)allocator.allocate(sizeof(image_interfaces__msg__Centroid), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(image_interfaces__msg__Centroid));
  bool success = image_interfaces__msg__Centroid__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
image_interfaces__msg__Centroid__destroy(image_interfaces__msg__Centroid * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    image_interfaces__msg__Centroid__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
image_interfaces__msg__Centroid__Sequence__init(image_interfaces__msg__Centroid__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__msg__Centroid * data = NULL;

  if (size) {
    data = (image_interfaces__msg__Centroid *)allocator.zero_allocate(size, sizeof(image_interfaces__msg__Centroid), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = image_interfaces__msg__Centroid__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        image_interfaces__msg__Centroid__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
image_interfaces__msg__Centroid__Sequence__fini(image_interfaces__msg__Centroid__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      image_interfaces__msg__Centroid__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

image_interfaces__msg__Centroid__Sequence *
image_interfaces__msg__Centroid__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__msg__Centroid__Sequence * array = (image_interfaces__msg__Centroid__Sequence *)allocator.allocate(sizeof(image_interfaces__msg__Centroid__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = image_interfaces__msg__Centroid__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
image_interfaces__msg__Centroid__Sequence__destroy(image_interfaces__msg__Centroid__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    image_interfaces__msg__Centroid__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
image_interfaces__msg__Centroid__Sequence__are_equal(const image_interfaces__msg__Centroid__Sequence * lhs, const image_interfaces__msg__Centroid__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!image_interfaces__msg__Centroid__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
image_interfaces__msg__Centroid__Sequence__copy(
  const image_interfaces__msg__Centroid__Sequence * input,
  image_interfaces__msg__Centroid__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(image_interfaces__msg__Centroid);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    image_interfaces__msg__Centroid * data =
      (image_interfaces__msg__Centroid *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!image_interfaces__msg__Centroid__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          image_interfaces__msg__Centroid__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!image_interfaces__msg__Centroid__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
