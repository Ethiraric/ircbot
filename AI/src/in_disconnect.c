/*
** in_disconnect.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 21:28:58 2015 Florian SABOURIN
** Last update Tue Apr 28 21:28:59 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>

int in_disconnect(t_bot* bot, t_luneth* luneth)
{
  t_ircconnection* co;
  size_t i;
  char* server;

  (void)(luneth);
  while ((server = strtok(NULL, " ")))
  {
    i = 0;
    while (i < vector_size(&bot->conns))
    {
      co = vector_at(&bot->conns, i);
      if (!strcmp(str_str(&co->servername), server))
      {
        bot_disconnect(bot, i);
        printf("Disconnected from %s\n", server);
        break;
      }
      ++i;
    }
  }
  return (0);
}
