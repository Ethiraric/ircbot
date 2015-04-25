/*
** main.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 23 23:25:11 2015 Florian SABOURIN
** Last update Thu Apr 23 23:25:30 2015 Florian SABOURIN
*/

#include <string.h>
#include "ircbot.h"

int	init(t_bot *bot)
{
  memset(bot, 0, sizeof(t_bot));
  bot->timeout.tv_sec = 0;
  bot->timeout.tv_usec = 100000000; // 0.1sec
  bot->timeptr = &bot->timeout;
  vector_new(&bot->conns);
  bot->net.fdmax = 1;
  return (0);
}

int		exec(t_bot *bot)
{
  bot->running = true;
  while (bot->running)
    {
      if (bot_select(bot))
	return (1);
    }
  return (0);
}

int		main()
{
  t_bot		bot;

  if (init(&bot))
    return (1);
  return (exec(&bot));
}
