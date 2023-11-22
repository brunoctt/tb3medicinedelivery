// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from image_interfaces:srv/Movement.idl
// generated code does not contain a copyright notice
#include "image_interfaces/srv/detail/movement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
image_interfaces__srv__Movement_Request__init(image_interfaces__srv__Movement_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
image_interfaces__srv__Movement_Request__fini(image_interfaces__srv__Movement_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
image_interfaces__srv__Movement_Request__are_equal(const image_interfaces__srv__Movement_Request * lhs, const image_interfaces__srv__Movement_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
image_interfaces__srv__Movement_Request__copy(
  const image_interfaces__srv__Movement_Request * input,
  image_interfaces__srv__Movement_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

image_interfaces__srv__Movement_Request *
image_interfaces__srv__Movement_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Request * msg = (image_interfaces__srv__Movement_Request *)allocator.allocate(sizeof(image_interfaces__srv__Movement_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(image_interfaces__srv__Movement_Request));
  bool success = image_interfaces__srv__Movement_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
image_interfaces__srv__Movement_Request__destroy(image_interfaces__srv__Movement_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    image_interfaces__srv__Movement_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
image_interfaces__srv__Movement_Request__Sequence__init(image_interfaces__srv__Movement_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Request * data = NULL;

  if (size) {
    data = (image_interfaces__srv__Movement_Request *)allocator.zero_allocate(size, sizeof(image_interfaces__srv__Movement_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = image_interfaces__srv__Movement_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        image_interfaces__srv__Movement_Request__fini(&data[i - 1]);
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
image_interfaces__srv__Movement_Request__Sequence__fini(image_interfaces__srv__Movement_Request__Sequence * array)
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
      image_interfaces__srv__Movement_Request__fini(&array->data[i]);
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

image_interfaces__srv__Movement_Request__Sequence *
image_interfaces__srv__Movement_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Request__Sequence * array = (image_interfaces__srv__Movement_Request__Sequence *)allocator.allocate(sizeof(image_interfaces__srv__Movement_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = image_interfaces__srv__Movement_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
image_interfaces__srv__Movement_Request__Sequence__destroy(image_interfaces__srv__Movement_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    image_interfaces__srv__Movement_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
image_interfaces__srv__Movement_Request__Sequence__are_equal(const image_interfaces__srv__Movement_Request__Sequence * lhs, const image_interfaces__srv__Movement_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!image_interfaces__srv__Movement_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
image_interfaces__srv__Movement_Request__Sequence__copy(
  const image_interfaces__srv__Movement_Request__Sequence * input,
  image_interfaces__srv__Movement_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(image_interfaces__srv__Movement_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    image_interfaces__srv__Movement_Request * data =
      (image_interfaces__srv__Movement_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!image_interfaces__srv__Movement_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          image_interfaces__srv__Movement_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!image_interfaces__srv__Movement_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
image_interfaces__srv__Movement_Response__init(image_interfaces__srv__Movement_Response * msg)
{
  if (!msg) {
    return false;
  }
  // relative_centroid
  // intersection
  return true;
}

void
image_interfaces__srv__Movement_Response__fini(image_interfaces__srv__Movement_Response * msg)
{
  if (!msg) {
    return;
  }
  // relative_centroid
  // intersection
}

bool
image_interfaces__srv__Movement_Response__are_equal(const image_interfaces__srv__Movement_Response * lhs, const image_interfaces__srv__Movement_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // relative_centroid
  if (lhs->relative_centroid != rhs->relative_centroid) {
    return false;
  }
  // intersection
  if (lhs->intersection != rhs->intersection) {
    return false;
  }
  return true;
}

bool
image_interfaces__srv__Movement_Response__copy(
  const image_interfaces__srv__Movement_Response * input,
  image_interfaces__srv__Movement_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // relative_centroid
  output->relative_centroid = input->relative_centroid;
  // intersection
  output->intersection = input->intersection;
  return true;
}

image_interfaces__srv__Movement_Response *
image_interfaces__srv__Movement_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Response * msg = (image_interfaces__srv__Movement_Response *)allocator.allocate(sizeof(image_interfaces__srv__Movement_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(image_interfaces__srv__Movement_Response));
  bool success = image_interfaces__srv__Movement_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
image_interfaces__srv__Movement_Response__destroy(image_interfaces__srv__Movement_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    image_interfaces__srv__Movement_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
image_interfaces__srv__Movement_Response__Sequence__init(image_interfaces__srv__Movement_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Response * data = NULL;

  if (size) {
    data = (image_interfaces__srv__Movement_Response *)allocator.zero_allocate(size, sizeof(image_interfaces__srv__Movement_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = image_interfaces__srv__Movement_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        image_interfaces__srv__Movement_Response__fini(&data[i - 1]);
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
image_interfaces__srv__Movement_Response__Sequence__fini(image_interfaces__srv__Movement_Response__Sequence * array)
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
      image_interfaces__srv__Movement_Response__fini(&array->data[i]);
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

image_interfaces__srv__Movement_Response__Sequence *
image_interfaces__srv__Movement_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  image_interfaces__srv__Movement_Response__Sequence * array = (image_interfaces__srv__Movement_Response__Sequence *)allocator.allocate(sizeof(image_interfaces__srv__Movement_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = image_interfaces__srv__Movement_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
image_interfaces__srv__Movement_Response__Sequence__destroy(image_interfaces__srv__Movement_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    image_interfaces__srv__Movement_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
image_interfaces__srv__Movement_Response__Sequence__are_equal(const image_interfaces__srv__Movement_Response__Sequence * lhs, const image_interfaces__srv__Movement_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!image_interfaces__srv__Movement_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
image_interfaces__srv__Movement_Response__Sequence__copy(
  const image_interfaces__srv__Movement_Response__Sequence * input,
  image_interfaces__srv__Movement_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(image_interfaces__srv__Movement_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    image_interfaces__srv__Movement_Response * data =
      (image_interfaces__srv__Movement_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!image_interfaces__srv__Movement_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          image_interfaces__srv__Movement_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!image_interfaces__srv__Movement_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
