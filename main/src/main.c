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
#include <string.h>
#include "ircbot.h"

static int	init(t_bot *bot)
{
  memset(bot, 0, sizeof(t_bot));
  bot->timeout.tv_sec = 0;
  bot->timeout.tv_usec = 100000000; // 0.1sec
  bot->timeptr = &bot->timeout;
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

static void	usage()
{
  fprintf(stderr,
	  "Usage : %s [lib]\n"
	  "\tlib: a shared library containing particular symbols to interact "
	  "with irc\n",
	  program_invocation_name);
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
  return (ret);
}
