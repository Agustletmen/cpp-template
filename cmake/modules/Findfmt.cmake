# - Try to find the fmt library
# Once done, this will define
#  fmt_FOUND - System has fmt
#  fmt_INCLUDE_DIRS - The fmt include directories
#  fmt_LIBRARIES - The libraries needed to use fmt
#  fmt_DEFINITIONS - Compiler switches required for using fmt

# Search for the include directory containing fmt/core.h
find_path(fmt_INCLUDE_DIR
  NAMES fmt/core.h
  PATHS
    ${CMAKE_CURRENT_LIST_DIR}/../include
    ${CMAKE_CURRENT_LIST_DIR}/../../include
    D:/SDK/3rd/fmt/include
)

# Search for the fmt library (dll or lib)
find_library(fmt_LIBRARY
  NAMES fmt
  PATH_SUFFIXES lib
  PATHS
    ${CMAKE_CURRENT_LIST_DIR}/../lib
    ${CMAKE_CURRENT_LIST_DIR}/../../lib
    D:/SDK/3rd/fmt/lib
)

# Handle the QUIETLY and REQUIRED arguments and set fmt_FOUND to TRUE if all components are found
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(fmt DEFAULT_MSG
  fmt_LIBRARY fmt_INCLUDE_DIR)

if(fmt_FOUND)
  set(fmt_LIBRARIES ${fmt_LIBRARY})
  set(fmt_INCLUDE_DIRS ${fmt_INCLUDE_DIR})
else()
  set(fmt_LIBRARIES)
  set(fmt_INCLUDE_DIRS)
endif()

mark_as_advanced(fmt_INCLUDE_DIR fmt_LIBRARY)
