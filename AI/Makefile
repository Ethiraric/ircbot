##
## Makefile for  in /home/sabour_f/rendu/ircbot/AI
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Mon Dec 14 15:49:29 2015 Florian SABOURIN
## Last update Mon Dec 14 15:49:29 2015 Florian SABOURIN
##

# Executables
CC		=	gcc
CXX		=	g++
AR		=	ar rcs
RM		=	@rm -vf
MAKE		+=	--no-print-directory

# Names
SONAME		=       ../AI.so

# Flags
CFLAGS		=	-W -Wall -Wshadow -fno-diagnostics-show-caret -fPIC -D_GNU_SOURCE -Iinclude -I../libIRC/include -I../main/include 
CXXFLAGS	=	-W -Wall -Wshadow -fno-diagnostics-show-caret -fPIC -D_GNU_SOURCE -Iinclude -I../libIRC/include -I../main/include 
LDFLAGS		=	-shared -lsqlite3 -lcurl -lz -lcrypto -lssl 

# Files
CSRC		=	src/database.c
CSRC		+=	src/mess_privmsg.c
CSRC		+=	src/in_raw.c
CSRC		+=	src/config.c
CSRC		+=	src/command_pokemon_questions.c
CSRC		+=	src/in_list.c
CSRC		+=	src/in_reload.c
CSRC		+=	src/command_pokemon.c
CSRC		+=	src/PokemonDB.c
CSRC		+=	src/luneth.c
CSRC		+=	src/song.c
CSRC		+=	src/command_song.c
CSRC		+=	src/cmd.c
CSRC		+=	src/mess_join.c
CSRC		+=	src/hl_all.c
CSRC		+=	src/message.c
CSRC		+=	src/command_calc.c
CSRC		+=	src/in_msg.c
CSRC		+=	src/people.c
CSRC		+=	src/command_cmd.c
CSRC		+=	src/in_join.c
CSRC		+=	src/command_action.c
CSRC		+=	src/command_songid.c
CSRC		+=	src/youtube_title.c
CSRC		+=	src/config_modules.c
CSRC		+=	src/command_shifumi.c
CSRC		+=	src/config_key_server.c
CSRC		+=	src/in_disconnect.c
CSRC		+=	src/in_connect.c
CSRC		+=	src/command_ping.c
CSRC		+=	src/say.c
CSRC		+=	src/command_say.c
CSRC		+=	src/chan.c
CSRC		+=	src/input.c


# Objects
OBJ		=	$(CSRC:.c=.o) $(CXXSRC:.cpp=.o)

# Rules
$(SONAME): $(OBJ)
	$(CC) -o $(SONAME) $(filter-out main.o, $(OBJ)) $(LDFLAGS) -shared

all: $(SONAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(SONAME)

re: fclean all

.PHONY: 	all clean fclean re

src/database.o: src/database.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/database.o src/database.c

src/mess_privmsg.o: src/mess_privmsg.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/mess_privmsg.o src/mess_privmsg.c

src/in_raw.o: src/in_raw.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_raw.o src/in_raw.c

src/config.o: src/config.c include/config.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h
	$(CC) $(CFLAGS) -c -o src/config.o src/config.c

src/command_pokemon_questions.o: src/command_pokemon_questions.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_pokemon_questions.o src/command_pokemon_questions.c

src/in_list.o: src/in_list.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_list.o src/in_list.c

src/in_reload.o: src/in_reload.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_reload.o src/in_reload.c

src/command_pokemon.o: src/command_pokemon.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_pokemon.o src/command_pokemon.c

src/PokemonDB.o: src/PokemonDB.c include/Pokemon.h
	$(CC) $(CFLAGS) -c -o src/PokemonDB.o src/PokemonDB.c

src/luneth.o: src/luneth.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/luneth.o src/luneth.c

src/song.o: src/song.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/song.o src/song.c

src/command_song.o: src/command_song.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_song.o src/command_song.c

src/cmd.o: src/cmd.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/cmd.o src/cmd.c

src/mess_join.o: src/mess_join.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/mess_join.o src/mess_join.c

src/hl_all.o: src/hl_all.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/hl_all.o src/hl_all.c

src/message.o: src/message.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/message.o src/message.c

src/command_calc.o: src/command_calc.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_calc.o src/command_calc.c

src/in_msg.o: src/in_msg.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_msg.o src/in_msg.c

src/people.o: src/people.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/people.o src/people.c

src/command_cmd.o: src/command_cmd.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_cmd.o src/command_cmd.c

src/in_join.o: src/in_join.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_join.o src/in_join.c

src/command_action.o: src/command_action.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_action.o src/command_action.c

src/command_songid.o: src/command_songid.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_songid.o src/command_songid.c

src/youtube_title.o: src/youtube_title.c include/dev_key.h include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/youtube_title.o src/youtube_title.c

src/config_modules.o: src/config_modules.c include/config.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h
	$(CC) $(CFLAGS) -c -o src/config_modules.o src/config_modules.c

src/command_shifumi.o: src/command_shifumi.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_shifumi.o src/command_shifumi.c

src/config_key_server.o: src/config_key_server.c include/config.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h
	$(CC) $(CFLAGS) -c -o src/config_key_server.o src/config_key_server.c

src/in_disconnect.o: src/in_disconnect.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_disconnect.o src/in_disconnect.c

src/in_connect.o: src/in_connect.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/in_connect.o src/in_connect.c

src/command_ping.o: src/command_ping.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_ping.o src/command_ping.c

src/say.o: src/say.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/say.o src/say.c

src/command_say.o: src/command_say.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/command_say.o src/command_say.c

src/chan.o: src/chan.c include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h
	$(CC) $(CFLAGS) -c -o src/chan.o src/chan.c

src/input.o: src/input.c include/luneth.h include/Pokemon.h include/database.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../main/include/vector.h ../main/include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/buffer.h include/config.h
	$(CC) $(CFLAGS) -c -o src/input.o src/input.c

