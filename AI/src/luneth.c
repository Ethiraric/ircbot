/*
** luneth.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 09:25:14 2015 Florian SABOURIN
** Last update Tue Apr 28 09:25:14 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include "luneth.h"

void		*irc_data_get()
{
  t_luneth	*ret;

  ret = malloc(sizeof(t_luneth));
  ret->foo = 0;
  return (ret);
}

int		irc_on_mess(t_bot *bot, t_ircconnection *co, void *luneth)
{
  (void)(bot);
  (void)(co);
  (void)(luneth);
  return (0);
}

int		irc_stdin(t_bot *bot, char *input, void *luneth)
{
  printf("You said : %s\n", input);
  return (handle_input(bot, input, luneth));
}

void		irc_data_delete(void *luneth)
{
  free(luneth);
}
