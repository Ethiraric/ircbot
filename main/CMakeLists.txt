cmake_minimum_required(VERSION 2.6)

#configuration
project("IRC Bot")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

add_definitions(-D_GNU_SOURCE)

#dependencies

#includes directories
include_directories(include/)
include_directories(../libIRC/include)

#sources files
set(SRCS
  src/AI.c
  src/botutils.c
  src/scheduler.c
  src/select.c
  src/vector.c
)

#binary
add_library(IRCBotlib STATIC ${SRCS})
add_executable(IRCBot src/main.c)

#linking
target_link_libraries(IRCBot IRCBotlib IRC dl)

set_property(TARGET IRCBot PROPERTY C_STANDARD 99)
set_property(TARGET IRCBot PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET IRCBotlib PROPERTY C_STANDARD 99)
set_property(TARGET IRCBotlib PROPERTY C_STANDARD_REQUIRED ON)
