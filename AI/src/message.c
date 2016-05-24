/*
** message.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 03:03:23 2015 Florian SABOURIN
** Last update Thu Apr 30 03:03:23 2015 Florian SABOURIN
*/

#include "luneth.h"

static const char* cmdtab[] = {"JOIN", NULL};

static int (*const fcttab[])(t_bot* bot,
                             t_ircconnection* co,
                             t_luneth* luneth) = {&mess_join, NULL};

int handle_message(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  unsigned int i;

  if (!strcasecmp(co->cmd.cmd, "PRIVMSG"))
    return (mess_privmsg(bot, co, luneth));
  i = 0;
  while (cmdtab[i])
  {
    if (!strcasecmp(co->cmd.cmd, cmdtab[i]))
      return (fcttab[i](bot, co, luneth));
    ++i;
  }
  return (0);
}
