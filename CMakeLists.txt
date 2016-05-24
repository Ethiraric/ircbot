cmake_minimum_required(VERSION 2.6)

#configuration
project("IRCBot")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif (NOT DEFINED CMAKE_BUILD_TYPE)

#subdirectories
add_subdirectory(libIRC)
add_subdirectory(AI)
add_subdirectory(main)
