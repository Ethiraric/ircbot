/*
** select.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Apr 24 22:50:35 2015 Florian SABOURIN
** Last update Fri Apr 24 22:50:36 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include "ircbot.h"

static int	handle_stdin(t_bot *bot)
{
  char		*input;
  size_t	len;

  if (FD_ISSET(0, &bot->net.rfds))
    {
      if (getline(&input, &len, stdin) == (ssize_t)(-1))
	return (1);
      len = 0;
      if (bot->handler_input_fct)
	len = bot->handler_input_fct(bot, bot->handler_data);
      free(input);
      return (len);
    }
  return (0);
}

static int	handle_conns(t_bot *bot)
{
  t_ircconnection	*co;
  unsigned int	i;
  int		ret;

  i = 0;
  while (i < vector_size(&bot->conns))
    {
      co = vector_at(&bot->conns, i);
      ret = irc_recv(co);
      /* If connection has been closed, delete it */
      if (ret == -1)
	{
	  irc_co_delete(co);
	  vector_erase(&bot->conns, i);
	}
      else if (ret == 1)
	return (1);
      else
	{
	  if (irc_parse_command(co))
	    return (1);
	  if (irc_get_command(co))
	    {
	      if (irc_eval_cmd(co) ||
		  (bot->handler_fct &&
		   bot->handler_fct(bot, co,bot->handler_data)) ||
		  irc_handle_cmd(co, false))
		return (1);
	    }
	  ++i;
	}
    }
  return (0);
}

static int	handle_select(t_bot *bot)
{
  if (handle_stdin(bot) || handle_conns(bot))
    return (1);
  return (0);
}

static void	set_fds(t_bot *bot)
{
  t_ircconnection	*curr;
  size_t	i;

  FD_ZERO(&bot->net.rfds);
  FD_ZERO(&bot->net.wfds);
  FD_SET(0, &bot->net.rfds);
  i = 0;
  while (i < vector_size(&bot->conns))
    {
      curr = vector_at(&bot->conns, i);
      if (irc_send_buff_len(curr))
	FD_SET(irc_get_socket(curr), &bot->net.wfds);
      FD_SET(irc_get_socket(curr), &bot->net.rfds);
      ++i;
    }
}

int		bot_select(t_bot *bot)
{
  int		ret;

  set_fds(bot);
  ret = select(bot->net.fdmax, &bot->net.rfds, &bot->net.wfds, NULL,
	       bot->timeptr);
  if (ret == -1)
    return (-1);
  return (handle_select(bot));
}