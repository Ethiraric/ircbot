/*
** mess_join.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 03:07:43 2015 Florian SABOURIN
** Last update Thu Apr 30 03:07:44 2015 Florian SABOURIN
*/

#include "luneth.h"

int		mess_join(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  (void)(bot);
  (void)(luneth);
  if (co->cmd.argc == 0 || !co->cmd.prefix)
    return (0);
  return (irc_msg(co, co->cmd.args[0], co->cmd.prefixnick));
}
