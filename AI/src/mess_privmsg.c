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

static int	log_message(t_ircconnection *co, t_luneth *luneth)
{
  int		ret;

  ret = database_insert_msg(luneth->db, co->cmd.prefixnick, co->cmd.args[0],
      str_str(&co->servername), co->cmd.args[co->cmd.argc - 1]);
  return (!ret);
}

const char	*cmds[] =
{
  "ping", "action", "songid", "song", "pokemon", "cmd", "say", NULL
};

int	(* const fcttab[])(t_bot *, t_ircconnection *, t_luneth *) =
{
  &command_ping, &command_action, &command_songid, &command_song,
    &command_pokemon, &command_cmd, &command_say, NULL
};

static int	check_cmd(t_ircconnection *co, t_luneth *luneth, char *cmd)
{
  t_cmd		*dbcmd;
  int		ret;

  if (strtok(NULL, " "))
    return (0);
  dbcmd = database_get_cmd(luneth->db, cmd);
  if (!dbcmd)
    return (0);
  ret = irc_msg(co, co->cmd.args[0], dbcmd->text);
  cmd_delete(dbcmd, true);
  return (ret);
}

int		mess_privmsg(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  size_t	i;
  char		*cmd;

  if (co->cmd.argc < 2)
    return (0);
  if (log_message(co, luneth))
    return (1);
  i = 0;
  if (pkq_check_ans(luneth, co))
    return (1);
  if (!strcmp(co->cmd.args[co->cmd.argc - 1], "\\o\\"))
    return (hl_all(co));
  cmd = strtok(co->cmd.args[co->cmd.argc - 1], " ");
  while (cmds[i])
    {
      if (!strcasecmp(cmds[i], cmd))
	return (fcttab[i](bot, co, luneth));
      ++i;
    }
  return (check_cmd(co, luneth, cmd));
}
