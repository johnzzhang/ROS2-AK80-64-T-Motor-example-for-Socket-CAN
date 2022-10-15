// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef TMOTOR__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define TMOTOR__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_tmotor __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_tmotor __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_tmotor __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_tmotor __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_tmotor
    #define ROSIDL_GENERATOR_C_PUBLIC_tmotor ROSIDL_GENERATOR_C_EXPORT_tmotor
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_tmotor ROSIDL_GENERATOR_C_IMPORT_tmotor
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_tmotor __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_tmotor
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_tmotor __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_tmotor
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // TMOTOR__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
