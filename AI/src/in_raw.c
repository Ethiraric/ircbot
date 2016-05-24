/*
** in_raw.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Dec 14 15:33:35 2015 Florian SABOURIN
** Last update Mon Dec 14 15:33:35 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>

int in_raw(t_bot* bot, t_luneth* luneth)
{
  t_ircconnection* co;
  size_t i;
  char* server;
  char* rawdat;

  (void)(luneth);
  server = strtok(NULL, " ");
  rawdat = strtok(NULL, "\n");
  if (!server)
  {
    fprintf(stderr, "Usage: /raw <server> <message>\n");
    return (0);
  }
  i = 0;
  while (i < vector_size(&bot->conns))
  {
    co = vector_at(&bot->conns, i);
    if (!strcmp(str_str(&co->servername), server))
      return (irc_send_formatted(co, "%s\r\n", rawdat));
    ++i;
  }

  fprintf(stderr, "Unknown server %s\n", server);
  return (0);
}
