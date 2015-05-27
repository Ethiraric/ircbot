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
      input = NULL;
      if (getline(&input, &len, stdin) == -1)
	{
	  free(input);
	  return (1);
	}
      if (*input)
	{
	  *((char *)rawmemchr(input, '\n')) = '\0';
	  len = bot->handler_input_fct(bot, input, bot->handler_data);
	}
      else
	len = 0;
      free(input);
      return (len);
    }
  return (0);
}

static int	handle_co_write(t_bot *bot, t_ircconnection *co)
{
  /* If there is an error, the connection will be closed in handle_co_read */
  if (irc_send_buff_len(co) && FD_ISSET(irc_get_socket(co), &bot->net.wfds))
    irc_send(co);
  return (0);
}

static int	handle_co_read(t_bot *bot, t_ircconnection *co, size_t *i)
{
  int		ret;

  if (FD_ISSET(irc_get_socket(co), &bot->net.rfds))
    {
      ret = irc_recv(co);
      /* If connection has been closed, delete it */
      if (ret == -1)
	{
	  irc_co_delete(co);
	  vector_erase(&bot->conns, *i);
	}
      else if (ret == 1)
	return (1);
      else
	{
	  do
	    {
	      if (irc_parse_command(co))
		return (1);
	      if (irc_get_command(co))
		{
		  if (irc_eval_cmd(co) || irc_handle_cmd(co, false) ||
		      bot->handler_fct(bot, co,bot->handler_data))
		    return (1);
		}
	    } while (irc_get_command(co));
	  ++(*i);
	}
    }
  else
    ++(*i);
  return (0);
}

static int	handle_conns(t_bot *bot)
{
  t_ircconnection	*co;
  size_t	i;

  i = 0;
  while (i < vector_size(&bot->conns))
    {
      co = vector_at(&bot->conns, i);
      if (handle_co_write(bot, co) ||
	  handle_co_read(bot, co, &i))
	return (1);
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
  bot->timeout = bot->timeref;
  ret = select(bot->net.fdmax, &bot->net.rfds, &bot->net.wfds, NULL,
	       bot->timeptr);
  if (ret == -1 || handle_select(bot) ||
      bot->handler_nothing_fct(bot, bot->handler_data))
    return (1);
  if (bot->so_name)
    {
      loadAI(bot, bot->so_name);
      free(bot->so_name);
      bot->so_name = NULL;
    }
  return (0);
}
