/*
** main.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 23 23:25:11 2015 Florian SABOURIN
** Last update Thu Apr 23 23:25:30 2015 Florian SABOURIN
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ircbot.h"

static int	init(t_bot *bot)
{
  memset(bot, 0, sizeof(t_bot));
  bot->timeref.tv_sec = 0;
  bot->timeref.tv_usec = 100000; // 0.1sec
  bot->timeptr = &(bot->timeout);
  vector_new(&bot->conns);
  bot->net.fdmax = 1;
  bot->handler_fct = &handler_fct_none;
  bot->handler_input_fct = &handler_input_fct_none;
  return (0);
}

static int	exec(t_bot *bot)
{
  bot->running = true;
  while (bot->running)
    {
      if (bot_select(bot))
	return (1);
    }
  return (0);
}

static int	terminate(t_bot *bot)
{
  size_t	i;

  unloadAI(bot);
  i = 0;
  while (i < vector_size(&bot->conns))
    {
      irc_co_delete(vector_at(&bot->conns, i));
      free(vector_at(&bot->conns, i));
      ++i;
    }
  vector_delete(&bot->conns, false);
  return (0);
}


static void	usage()
{
  static const char	*fmt =
      "Usage : %s [lib]\n"
      "\tlib: a shared library containing particular symbols to interact "
      "with irc\n";

  fprintf(stderr, fmt, program_invocation_name);
}

int		main(int argc, char **argv)
{
  t_bot		bot;
  int		ret;

  if (argc > 2)
    {
      usage();
      return (1);
    }
  if (init(&bot) || (argc == 2 && loadAI(&bot, argv[1])))
    return (1);
  ret = exec(&bot);
  ret |= terminate(&bot);
  return (ret);
}
