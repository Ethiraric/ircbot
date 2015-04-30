/*
** botutils.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 11:41:42 2015 Florian SABOURIN
** Last update Tue Apr 28 11:41:42 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include "ircbot.h"

int	bot_connect(t_bot *bot, const char *hostname, unsigned short port,
		    const char *nick, const char *user, const char *realname,
		    const char *pass)
{
  t_ircconnection	*co;

  co = malloc(sizeof(t_ircconnection));
  if (!co)
    return (1);
  irc_co_new(co);
  if (irc_set_infos(co, nick, user, realname, pass) ||
      irc_connect(co, hostname, port))
    {
      irc_co_delete(co);
      free(co);
      return (1);
    }
  if (irc_send_infos(co) ||
      vector_push_back(&bot->conns, co))
    {
      irc_disconnect(co);
      irc_co_delete(co);
      free(co);
      return (1);
    }
  if (irc_get_socket(co) >= bot->net.fdmax)
    bot->net.fdmax = irc_get_socket(co) + 1;
  return (0);
}

int		bot_disconnect(t_bot *bot, size_t pos)
{
  t_ircconnection	*co;
  size_t	i;
  int		ret;

  co = vector_at(&bot->conns, pos);
  if (co)
    {
      ret = irc_disconnect(co);
      irc_co_delete(co);
      free(co);
      vector_erase(&bot->conns, pos);
      bot->net.fdmax = 1;
      while (i < vector_size(&bot->conns))
	{
	  if (irc_get_socket(vector_at(&bot->conns, i)) >= bot->net.fdmax)
	    bot->net.fdmax = irc_get_socket(vector_at(&bot->conns, i));
	  ++i;
	}
      return (ret);
    }
  return (0);
}
