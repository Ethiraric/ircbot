#include "luneth.h"

static int self_tg(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  (void)(bot);
  (void)(co);
  luneth->speaks = false;
  return (0);
}

static int self_speak(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  (void)(bot);
  (void)(co);
  luneth->speaks = true;
  return (0);
}

static const char* cmds[] = {"tg", "stfu", "shutup", "speak", NULL};

static int (*const fcttab[])(t_bot*, t_ircconnection*, t_luneth*) = {
    &self_tg, &self_tg, &self_tg, &self_speak, NULL};

int command_self_command(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  char* cmd;

  cmd = strtok(NULL, " ");
  if (!cmd)
    return (0);
  for (unsigned int i = 0; cmds[i]; ++i)
  {
    if (!strcasecmp(cmds[i], cmd))
      return (fcttab[i](bot, co, luneth));
  }
  return (0);
}
