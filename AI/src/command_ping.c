/*
** command_ping.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 14:40:41 2015 Florian SABOURIN
** Last update Thu Apr 30 14:40:41 2015 Florian SABOURIN
*/

#include "luneth.h"

int		command_ping(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  char		*msg;

  (void)(bot);
  (void)(luneth);
  msg = strtok(NULL, "");
  if (msg)
    {
      msg += strspn(msg, " ");
      if (*msg)
	return (irc_msgf(co, co->cmd.args[0], "%s %s",
		co->cmd.prefixnick, msg));
    }
  return (irc_msgf(co, co->cmd.args[0], "%s", co->cmd.prefixnick));
}
