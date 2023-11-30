// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from image_interfaces:srv/Movement.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "image_interfaces/srv/detail/movement__struct.h"
#include "image_interfaces/srv/detail/movement__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool image_interfaces__srv__movement__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("image_interfaces.srv._movement.Movement_Request", full_classname_dest, 47) == 0);
  }
  image_interfaces__srv__Movement_Request * ros_message = _ros_message;
  ros_message->structure_needs_at_least_one_member = 0;

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * image_interfaces__srv__movement__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Movement_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("image_interfaces.srv._movement");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Movement_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  (void)raw_ros_message;

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "image_interfaces/srv/detail/movement__struct.h"
// already included above
// #include "image_interfaces/srv/detail/movement__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool image_interfaces__srv__movement__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("image_interfaces.srv._movement.Movement_Response", full_classname_dest, 48) == 0);
  }
  image_interfaces__srv__Movement_Response * ros_message = _ros_message;
  {  // relative_centroid
    PyObject * field = PyObject_GetAttrString(_pymsg, "relative_centroid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->relative_centroid = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // intersection
    PyObject * field = PyObject_GetAttrString(_pymsg, "intersection");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->intersection = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * image_interfaces__srv__movement__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Movement_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("image_interfaces.srv._movement");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Movement_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  image_interfaces__srv__Movement_Response * ros_message = (image_interfaces__srv__Movement_Response *)raw_ros_message;
  {  // relative_centroid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->relative_centroid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "relative_centroid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // intersection
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->intersection ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "intersection", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
