##
## Makefile for  in /home/sabour_f/rendu/ircbot/main
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Thu Apr 23 23:22:50 2015 Florian SABOURIN
## Last update Thu Apr 23 23:28:06 2015 Florian SABOURIN
##

NAME		=	../IRCBot
CC		=	gcc
override CFLAGS	+=	-Iinclude -I../libIRC/include -D_GNU_SOURCE
export CFLAGS
LDFLAGS		=	-ldl -L../libIRC -rdynamic
LDFLAGS		+=	-Wl,--whole-archive -lIRC -Wl,--no-whole-archive
RM		=	@rm -vf
MAKE		+=	--no-print-directory
LIBIRC		=	../libIRC/libIRC.a

SRC		=	src/main.c
SRC		+=	src/vector.c
SRC		+=	src/select.c
SRC		+=	src/AI.c
SRC		+=	src/botutils.c

OBJ		=	$(SRC:.c=.o)

%.o:	%.c
	$(CC) -c $(CFLAGS)            -o $@ $^

$(NAME):	$(LIBIRC) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

$(LIBIRC):
	@$(MAKE) -C ../libIRC

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re $(LIBIRC)
