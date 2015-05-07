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
  if (!ret)
    return (NULL);
  ret->db = database_new("db");
  if (!ret->db)
    {
      free(ret);
      return (NULL);
    }
  ret->foo = 0;
  return (ret);
}

int		irc_on_mess(t_bot *bot, t_ircconnection *co, void *luneth)
{
  printf("%s said: %s\n", str_str(&co->servername), irc_get_command(co));
  return (handle_message(bot, co, luneth));
}

int		irc_stdin(t_bot *bot, char *input, void *luneth)
{
  printf("You said : %s\n", input);
  return (handle_input(bot, input, luneth));
}

void		irc_data_delete(void *luneth)
{
  database_delete(((t_luneth *)luneth)->db);
  free(luneth);
}
