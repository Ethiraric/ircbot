cmake_minimum_required(VERSION 2.6)

#configuration
project("IRCBot")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

if (NOT DEFINED CMAKE_BUILD_TYPE OR
    CMAKE_BUILD_TYPE STREQUAL "" OR
    CMAKE_BUILD_TYPE EQUAL Debug)
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ggdb3")
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wshadow")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-diagnostics-show-caret")

#subdirectories
add_subdirectory(libIRC)
add_subdirectory(AI)
add_subdirectory(main)
