/*
** in_msg.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Aug 28 00:10:30 2015 Florian SABOURIN
** Last update Fri Aug 28 00:10:31 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>
#include <string.h>

/*
** When receiving "/msg" on standard input
** SYNTAX: /msg <server> <destination> <message>
** Messages are sent using PRIVMSG (not NOTICE)
*/
int in_msg(t_bot* bot, t_luneth* luneth)
{
  t_ircconnection* co;
  size_t i;
  char* destination;
  char* server;
  char* message;

  (void)(luneth);
  server = strtok(NULL, " ");
  destination = strtok(NULL, " ");
  message = strtok(NULL, "");
  if (message)
    message += strspn(message, " \t");
  if (!destination || !server || !message || !*message)
  {
    fprintf(stderr, "Usage : /msg <server> <destination> <message>\n");
    return (0);
  }
  i = 0;
  while (i < vector_size(&bot->conns))
  {
    co = vector_at(&bot->conns, i);
    if (!strcmp(str_str(&co->servername), server))
      return (irc_msg(co, destination, message));
    ++i;
  }
  fprintf(stderr, "Unknown server %s\n", server);
  return (0);
}
