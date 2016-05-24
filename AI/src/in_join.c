/*
** in_join.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu May 28 13:37:42 2015 Florian SABOURIN
** Last update Thu May 28 13:37:42 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>

int in_join(t_bot* bot, t_luneth* luneth)
{
  t_ircconnection* co;
  size_t i;
  char* chan;
  char* server;

  (void)(luneth);
  server = strtok(NULL, " ");
  chan = strtok(NULL, " ");
  if (!chan || !server || strtok(NULL, " "))
  {
    fprintf(stderr, "Usage : /join <server> <chan>\n");
    return (0);
  }
  i = 0;
  while (i < vector_size(&bot->conns))
  {
    co = vector_at(&bot->conns, i);
    if (!strcmp(str_str(&co->servername), server))
      return (irc_join(co, chan));
    ++i;
  }
  fprintf(stderr, "Unknown server %s\n", server);
  return (0);
}
