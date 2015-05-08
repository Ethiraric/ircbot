/*
** in_connect.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 12:26:18 2015 Florian SABOURIN
** Last update Tue Apr 28 12:26:19 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <stdio.h>
#include "luneth.h"

int		in_connect(t_bot *bot, t_luneth *luneth)
{
  char		*hostname, *sport, *nick, *user, *realname, *pass;

  (void)luneth;
  if (!(hostname = strtok(NULL, " ")) || !(sport = strtok(NULL, " ")) ||
      !(nick = strtok(NULL, " ")) || !(user = strtok(NULL, " ")) ||
      !(realname = strtok(NULL, " ")))
    {
      fprintf(stderr, "/connect <host> <port> <nick> <user> <realname> "
		      "[<pass>]\n");
      return (0);
    }
  pass = strtok(NULL, " ");
  if (bot_connect(bot, hostname, atoi(sport), nick, user, realname, pass))
    fprintf(stderr, "Failed to connect to %s\n", hostname);
  return (0);
}
