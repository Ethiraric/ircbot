cmake_minimum_required(VERSION 2.6)

#configuration
project("IRCBot")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

#subdirectories
add_subdirectory(libassert)

include_directories(../libIRC/include/)
include_directories(../main/include/)
include_directories(../AI/include/)
include_directories(./libassert/)

# Test binary
set(SRCS
  src/main.c
  src/test_cmd_ping.c
  src/test_common.c
)

add_executable(bottests ${SRCS})

target_link_libraries(bottests AI IRCBotlib IRC dl assert)

set_property(TARGET bottests PROPERTY C_STANDARD 99)
set_property(TARGET bottests PROPERTY C_STANDARD_REQUIRED ON)
