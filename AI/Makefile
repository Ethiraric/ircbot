##
## Makefile for  in /home/sabour_f/rendu/ircbot/AI
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Tue Apr 28 09:26:50 2015 Florian SABOURIN
## Last update Tue Apr 28 09:53:12 2015 Florian SABOURIN
##

NAME		=	../AI.so
CC		=	gcc
override CFLAGS	+=	-W -Wall -fpic -Iinclude -I../main/include
override CFLAGS	+=	-I../libIRC/include -D_GNU_SOURCE
LDFLAGS		=	-shared -lsqlite3
RM		=	@rm -vf

SRC		=	src/luneth.c
SRC		+=	src/input.c
SRC		+=	src/in_list.c
SRC		+=	src/in_connect.c


OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
