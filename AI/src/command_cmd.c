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

static int cmd_add(t_ircconnection* co, t_luneth* luneth)
{
  t_cmd* command;
  char* cmd;
  char* text;
  t_id id;

  cmd = strtok(NULL, " ");
  text = strtok(NULL, "");
  if (!cmd || !text)
    return (0);
  text += strspn(text, " ");
  if (!*text)
    return (0);
  if (!mapstring_findcstr(luneth->cmds, cmd))
    return (luneth_respond_msgf(co, luneth, "%s is already a command", cmd));
  if ((id = database_insert_command(luneth->db, cmd, text)))
  {
    command = cmd_new(id, cmd, text);
    if (!command)
      return (1);
    if (mapstring_insertcstr(luneth->cmds, cmd, command))
    {
      cmd_delete(command, true);
      return (1);
    }
    return (luneth_respond_msgf(co, luneth, "%s added to the commands", cmd));
  }
  return (luneth_respond_msgf(co, luneth, "Failed to add command %s", cmd));
}

static int cmd_rm(t_ircconnection* co, t_luneth* luneth)
{
  unsigned int cmd_pos;
  char* cmd;

  cmd = strtok(NULL, " ");
  if (!cmd || strtok(NULL, ""))
    return (0);
  cmd_pos = mapstring_findpos(luneth->cmds, cmd);
  if (cmd_pos == (unsigned int)(-1))
    return (luneth_respond_msgf(co, luneth, "Unknown command %s", cmd));
  if (database_rm_cmd(luneth->db, cmd))
    return (
        luneth_respond_msgf(co, luneth, "Failed to remove command %s", cmd));
  cmd_delete(mapstring_at(luneth->cmds, cmd_pos), true);
  mapstring_erase_idx(luneth->cmds, cmd_pos);
  return (luneth_respond_msgf(co, luneth, "Removed command %s", cmd));
}

int command_cmd(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  char* cmd;

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
