# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tmotor_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tmotor_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tmotor_FOUND FALSE)
  elseif(NOT tmotor_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tmotor_FOUND FALSE)
  endif()
  return()
endif()
set(_tmotor_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tmotor_FIND_QUIETLY)
  message(STATUS "Found tmotor: 0.0.0 (${tmotor_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tmotor' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tmotor_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tmotor_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;ament_cmake_export_include_directories-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${tmotor_DIR}/${_extra}")
endforeach()
