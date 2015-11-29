##
## Makefile for  in /home/sabour_f/rendu/ircbot/main
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Sun Nov 29 03:54:56 2015 Florian SABOURIN
## Last update Sun Nov 29 03:54:56 2015 Florian SABOURIN
##

# Executables
CC		=	gcc
CXX		=	g++
AR		=	ar rcs
RM		=	@rm -vf
MAKE		+=	--no-print-directory

# Names
NAME		=	../IRCBot

# Flags
CFLAGS		=	-W -Wall -Wshadow -fno-diagnostics-show-caret -rdynamic -D_GNU_SOURCE -Iinclude -I../libIRC/include 
CXXFLAGS	=	-W -Wall -Wshadow -fno-diagnostics-show-caret -rdynamic -D_GNU_SOURCE -Iinclude -I../libIRC/include 
LDFLAGS		=	-ldl -L../libIRC -rdynamic -Wl,--whole-archive -lIRC -Wl,--no-whole-archive 

# Files
CSRC		=	src/vector.c
CSRC		+=	src/botutils.c
CSRC		+=	src/AI.c
CSRC		+=	src/main.c
CSRC		+=	src/select.c


# Objects
OBJ		=	$(CSRC:.c=.o) $(CXXSRC:.cpp=.o)

# Rules
$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: 	all clean fclean re

src/vector.o: src/vector.c include/vector.h
	$(CC) $(CFLAGS) -c -o src/vector.o src/vector.c

src/botutils.o: src/botutils.c include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../libIRC/include/buffer.h include/vector.h
	$(CC) $(CFLAGS) -c -o src/botutils.o src/botutils.c

src/AI.o: src/AI.c include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../libIRC/include/buffer.h include/vector.h
	$(CC) $(CFLAGS) -c -o src/AI.o src/AI.c

src/main.o: src/main.c include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../libIRC/include/buffer.h include/vector.h
	$(CC) $(CFLAGS) -c -o src/main.o src/main.c

src/select.o: src/select.c include/ircbot.h ../libIRC/include/irc.h ../libIRC/include/t_mapstring.h ../libIRC/include/t_string.h ../libIRC/include/buffer.h include/vector.h
	$(CC) $(CFLAGS) -c -o src/select.o src/select.c

