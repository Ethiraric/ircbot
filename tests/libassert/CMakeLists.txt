cmake_minimum_required(VERSION 2.6)

#configuration
project("libIRC")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif (NOT DEFINED CMAKE_BUILD_TYPE)

add_definitions(-D_GNU_SOURCE)

#dependencies

#includes directories
include_directories(include/)

#sources files
set(SRCS
  myassert.c
)

#library
add_library(assert STATIC ${SRCS})

#linking
target_link_libraries(assert)

set_property(TARGET assert PROPERTY C_STANDARD 99)
set_property(TARGET assert PROPERTY C_STANDARD_REQUIRED ON)

