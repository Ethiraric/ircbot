/*
** command_cmd.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon May 18 16:38:43 2015 Florian SABOURIN
** Last update Mon May 18 16:38:43 2015 Florian SABOURIN
*/

#include "luneth.h"

static int	cmd_add(t_ircconnection *co, t_luneth *luneth)
{
  char		*cmd;
  char		*text;

  cmd = strtok(NULL, " ");
  text = strtok(NULL, "");
  if (!cmd || !text)
    return (0);
  text += strspn(text, " ");
  if (!*text)
    return (0);
  if (database_is_command(luneth->db, cmd))
    return (irc_msgf(co, co->cmd.args[0], "%s is already a command", cmd));
  if (database_insert_command(luneth->db, cmd, text))
    return (irc_msgf(co, co->cmd.args[0], "%s added to the commands", cmd));
  return (irc_msgf(co, co->cmd.args[0], "Failed to add command %s", cmd));
}

static int	cmd_rm(t_ircconnection *co, t_luneth *luneth)
{
  char		*cmd;

  cmd = strtok(NULL, " ");
  if (!cmd || strtok(NULL, ""))
    return (0);
  if (!database_rm_cmd(luneth->db, cmd))
    return (irc_msgf(co, co->cmd.args[0], "Removed command %s", cmd));
  return (irc_msgf(co, co->cmd.args[0], "Failed to remove command %s", cmd));
}

int		command_cmd(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  char		*cmd;

  (void)(bot);
  cmd = strtok(NULL, " ");
  if (!cmd)
    return (0);
  if (!(strcasecmp(cmd, "add")))
    return (cmd_add(co, luneth));
  if (!(strcasecmp(cmd, "rm")))
    return (cmd_rm(co, luneth));
  return (0);
}
