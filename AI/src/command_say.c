/*
** command_say.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon May 18 18:48:56 2015 Florian SABOURIN
** Last update Mon May 18 18:48:56 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdlib.h>

static int say_add(t_ircconnection* co, t_luneth* luneth)
{
  char* dest;
  char* msg;
  t_id auth;
  t_id dst;

  dest = strtok(NULL, " ");
  msg = strtok(NULL, "");
  if (!dest || !msg)
    return (0);
  msg += strspn(msg, " ");
  if (!*msg)
    return (0);
  auth = database_pplid(luneth->db,
                        co->cmd.prefixnick,
                        str_str(&co->servername),
                        co->cmd.args[0]);
  if (!auth)
    return (luneth_respond_msg(co, luneth, "Failed to find auth"));
  dst = database_pplid(
      luneth->db, dest, str_str(&co->servername), co->cmd.args[0]);
  if (!dst)
    return (luneth_respond_msg(co, luneth, "Failed to find dest"));
  auth = database_insert_say(luneth->db, auth, dst, msg);
  if (!auth)
    return (luneth_respond_msg(co, luneth, "Failed to insert say"));
  return (luneth_respond_msgf(co, luneth, "Say #%u added to database", auth));
}

static int say_rm(t_ircconnection* co, t_luneth* luneth)
{
  char* strid;
  t_say* say;
  t_id id;
  t_id pplid;

  strid = strtok(NULL, " ");
  if (!strid || strtok(NULL, " "))
    return (0);
  pplid = database_pplid(luneth->db,
                         co->cmd.prefixnick,
                         str_str(&co->servername),
                         co->cmd.args[0]);
  if (!pplid)
    return (1);
  id = atoi(strid);
  say = database_say_fromid(luneth->db, id);
  if (!say)
    return (luneth_respond_msgf(co, luneth, "#%u No such say", id));
  if (pplid != say->auth && pplid != say->dest)
  {
    say_delete(say, true);
    return (luneth_respond_msgf(co, luneth, "#%u Not your say", id));
  }
  say_delete(say, true);
  if (database_rm_say(luneth->db, id))
    return (luneth_respond_msgf(co, luneth, "Failed to rm say #%u", id));
  return (luneth_respond_msgf(co, luneth, "Say #%u removed", id));
}

int command_say(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  char* cmd;

  (void)(bot);
  cmd = strtok(NULL, " ");
  if (!cmd)
    return (0);
  if (!strcasecmp(cmd, "add"))
    return (say_add(co, luneth));
  if (!strcasecmp(cmd, "rm"))
    return (say_rm(co, luneth));
  return (0);
}
