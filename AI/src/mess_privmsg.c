/*
** mess_privmsg.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 14:27:57 2015 Florian SABOURIN
** Last update Thu Apr 30 14:27:57 2015 Florian SABOURIN
*/

#include "luneth.h"

const char	*cmds[] =
{
  "ping", "action", "songid", "song", "pokemon", NULL
};

int	(* const fcttab[])(t_bot *, t_ircconnection *, t_luneth *) =
{
  &command_ping, &command_action, &command_songid, &command_song,
    &command_pokemon, NULL
};

int		mess_privmsg(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  size_t	i;
  char		*cmd;

  if (co->cmd.argc < 2)
    return (0);
  i = 0;
  if (pkq_check_ans(luneth, co))
    return (1);
  cmd = strtok(co->cmd.args[co->cmd.argc - 1], " ");
  while (cmds[i])
    {
      if (!strcasecmp(cmds[i], cmd))
	return (fcttab[i](bot, co, luneth));
      ++i;
    }
  return (0);
}
