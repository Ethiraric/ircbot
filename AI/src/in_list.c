/*
** in_list.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 11:06:13 2015 Florian SABOURIN
** Last update Tue Apr 28 11:06:13 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>

static void dump_channel(t_channel* chan)
{
  size_t i;

  printf("=== %s\n", str_str(&chan->name));
  i = 0;
  while (i < mapstring_size(&chan->users))
  {
    t_user* user = mapstring_at(&chan->users, i);
    printf("\t-> %s\n", str_str(&user->nick));
    ++i;
  }
}

static void dump_co(t_ircconnection* co)
{
  size_t i;

  printf("%s\n", str_str(&co->servername));
  i = 0;
  while (i < mapstring_size(&co->chanlist))
  {
    dump_channel(mapstring_at(&co->chanlist, i));
    ++i;
  }
}

int in_list(t_bot* bot, t_luneth* luneth)
{
  size_t i;

  (void)(luneth);
  printf("This is a list\n");
  i = 0;
  while (i < vector_size(&bot->conns))
  {
    dump_co(vector_at(&bot->conns, i));
    ++i;
  }
  return (0);
}
