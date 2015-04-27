##
## Makefile for  in /home/sabour_f/rendu/ircbot
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Thu Apr 23 23:30:26 2015 Florian SABOURIN
## Last update Thu Apr 23 23:34:43 2015 Florian SABOURIN
##

MAKE		+=	--no-print-directory


all:	libIRC AI IRCBot

libIRC:
	@$(MAKE) -C libIRC

AI:
#	@$(MAKE) -C AI

IRCBot:
	@$(MAKE) -C main

clean:
	@$(MAKE) -C libIRC clean
#	@$(MAKE) -C AI clean
	@$(MAKE) -C main clean

fclean:
	@$(MAKE) -C libIRC fclean
#	@$(MAKE) -C AI fclean
	@$(MAKE) -C main fclean

re:	fclean all

.PHONY: all clean fclean re libIRC AI IRCBot
