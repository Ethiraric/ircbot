/*
** command_shifumi.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Sep  3 12:09:11 2015 Florian SABOURIN
** Last update Thu Sep  3 12:09:11 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include "luneth.h"

static char *names[] =
{
  "rock", "paper", "scissors"
};

int		command_shifumi(t_bot *bot, t_ircconnection *co,
				t_luneth *luneth)
{
  unsigned int	playeridx;
  unsigned int	botidx;
  char		*playerstr;

  (void)(luneth);
  (void)(bot);
  playerstr = strtok(NULL, " ");
  if (playerstr && !strtok(NULL, " "))
    {
      if (!strcmp(playerstr, names[0]))
	playeridx = 0;
      else if (!strcmp(playerstr, names[1]))
	playeridx = 1;
      else if (!strcmp(playerstr, names[2]))
	playeridx = 2;
      else
	return (0);
      botidx = rand() % 3;
      if (botidx == playeridx)
	return (irc_msgf(co, co->cmd.args[0], "%s - %s : Draw !\n",
		names[playeridx], names[botidx]));
      if ((botidx + 1) % 3 == playeridx)
	return (irc_msgf(co, co->cmd.args[0], "%s - %s : You win !\n",
		names[playeridx], names[botidx]));
      return (irc_msgf(co, co->cmd.args[0], "%s - %s : You lose !\n",
	      names[playeridx], names[botidx]));
    }
  return (0);
}
