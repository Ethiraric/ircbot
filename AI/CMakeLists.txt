cmake_minimum_required(VERSION 2.6)

#configuration
project("AI")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

add_definitions(-D_GNU_SOURCE)

#dependencies

#includes directories
include_directories(include/)
include_directories(../libIRC/include/)
include_directories(../main/include/)

#sources files
set(SRCS
  src/chan.c
  src/cmd.c
  src/command_action.c
  src/command_calc.c
  src/command_cmd.c
  src/command_ping.c
  src/command_pokemon.c
  src/command_pokemon_questions.c
  src/command_say.c
  src/command_self_command.c
  src/command_shifumi.c
  src/command_song.c
  src/command_songid.c
  src/config.c
  src/config_key_server.c
  src/config_modules.c
  src/database/channels.c
  src/database/commands.c
  src/database/database.c
  src/database/helper.c
  src/database/message.c
  src/database/people.c
  src/database/say.c
  src/database/songs.c
  src/database/sqlite.c
  src/hl_all.c
  src/in_connect.c
  src/in_disconnect.c
  src/in_join.c
  src/in_list.c
  src/in_msg.c
  src/input.c
  src/in_raw.c
  src/in_reload.c
  src/irc_utils.c
  src/luneth.c
  src/message.c
  src/mess_join.c
  src/mess_privmsg.c
  src/people.c
  src/PokemonDB.c
  src/say.c
  src/song.c
  src/youtube_title.c
)

#library
add_library(AI SHARED ${SRCS})

#linking
target_link_libraries(AI sqlite3 curl z crypto ssl)

set_property(TARGET AI PROPERTY C_STANDARD 99)
set_property(TARGET AI PROPERTY C_STANDARD_REQUIRED ON)

