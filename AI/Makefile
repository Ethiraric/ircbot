##
## Makefile for  in /home/sabour_f/rendu/ircbot/AI
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Tue Apr 28 09:26:50 2015 Florian SABOURIN
## Last update Sat May 23 13:49:44 2015 Florian SABOURIN
##

NAME		=	../AI.so
CC		=	gcc
override CFLAGS	+=	-fpic -Iinclude -I../main/include
override CFLAGS	+=	-I../libIRC/include -D_GNU_SOURCE
LDFLAGS		=	-shared -lsqlite3 -lcurl -lz -lcrypto -lssl
RM		=	@rm -vf

SRC		=	src/luneth.c
SRC		+=	src/input.c
SRC		+=	src/in_list.c
SRC		+=	src/in_join.c
SRC		+=	src/in_connect.c
SRC		+=	src/in_disconnect.c
SRC		+=	src/in_reload.c
SRC		+=	src/message.c
SRC		+=	src/mess_join.c
SRC		+=	src/mess_privmsg.c
SRC		+=	src/command_ping.c
SRC		+=	src/command_action.c
SRC		+=	src/command_songid.c
SRC		+=	src/command_song.c
SRC		+=	src/command_pokemon.c
SRC		+=	src/command_pokemon_questions.c
SRC		+=	src/command_cmd.c
SRC		+=	src/command_say.c
SRC		+=	src/database.c
SRC		+=	src/song.c
SRC		+=	src/people.c
SRC		+=	src/chan.c
SRC		+=	src/cmd.c
SRC		+=	src/say.c
SRC		+=	src/youtube_title.c
SRC		+=	src/PokemonDB.c
SRC		+=	src/hl_all.c

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
