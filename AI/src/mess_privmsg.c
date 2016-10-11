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

static int log_message(t_ircconnection* co, t_luneth* luneth)
{
  int ret;

  ret = database_insert_msg(luneth->db,
                            co->cmd.prefixnick,
                            co->cmd.args[0],
                            str_str(&co->servername),
                            co->cmd.args[co->cmd.argc - 1]);
  return (!ret);
}

static const char* cmds[] = {"ping",
                             "action",
                             "songid",
                             "song",
                             "pokemon",
                             "cmd",
                             "say",
                             "shifumi",
                             "calc",
                             ">",
                             NULL};

static int (*const fcttab[])(t_bot*, t_ircconnection*, t_luneth*) = {
    &command_ping,
    &command_action,
    &command_songid,
    &command_song,
    &command_pokemon,
    &command_cmd,
    &command_say,
    &command_shifumi,
    &command_calc,
    &command_calc,
    NULL};

static int check_cmd(t_ircconnection* co, t_luneth* luneth, char* cmd)
{
  t_cmd* dbcmd;
  int ret;

  if (strtok(NULL, " "))
    return (0);
  dbcmd = (t_cmd*)mapstring_findcstr(luneth->cmds, cmd);
  if (!dbcmd)
    return (0);
  ret = luneth_respond_msg(co, luneth, dbcmd->text);
  return (ret);
}

int mess_privmsg(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  size_t i;
  char* cmd;

  if (co->cmd.argc < 2)
    return (0);
  if (log_message(co, luneth))
    return (1);
  i = 0;
  if (pkq_check_ans(bot, luneth, co))
    return (1);
  if (!strcmp(co->cmd.args[co->cmd.argc - 1], "\\o\\"))
    return (hl_all(co, luneth));
  cmd = strtok(co->cmd.args[co->cmd.argc - 1], " ");
  if (!strcmp(cmd, str_str(&co->nick)))
    return (command_self_command(bot, co, luneth));
  while (cmds[i])
  {
    if (!strcasecmp(cmds[i], cmd))
      return (fcttab[i](bot, co, luneth));
    ++i;
  }
  return (check_cmd(co, luneth, cmd));
}
