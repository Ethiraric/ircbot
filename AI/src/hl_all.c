/*
** hl_all.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 14:27:57 2015 Florian SABOURIN
** Last update Thu Apr 30 14:27:57 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include "luneth.h"

#define AVG_NICK_LEN	16

int		hl_all(t_ircconnection *co)
{
  t_channel	*chan;
  t_user	*user;
  size_t	nb_users;
  size_t	i;
  char		*resp;
  char		*tail;
  int		ret;

  chan = mapstring_findcstr(&co->chanlist, co->cmd.args[0]);
  if (!chan)
    {
      fprintf(stderr, "[hl_all] Unknown chan %s\n", co->cmd.args[0]);
      return (0);
    }
  i = mapstring_size(&chan->users);
  i *= AVG_NICK_LEN + 2;
  resp = malloc(i + 1);
  tail = resp;
  *tail = '\0';
  i = 0;
  while (i < nb_users)
    {
      user = mapstring_at(&chan->users, i);
      tail = stpcpy(tail, str_safestr(&user->nick));
      if (++i < nb_users)
	{
	  *(tail++) = ' ';
	  *tail = '\0';
	}
    }
  ret = irc_msg(co, co->cmd.args[0], resp);
  free(resp);
  return (ret);
}
