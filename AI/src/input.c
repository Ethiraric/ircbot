/*
** input.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 10:49:26 2015 Florian SABOURIN
** Last update Tue Apr 28 10:49:26 2015 Florian SABOURIN
*/

#include "luneth.h"

// WARNING: Remove (debugging)
#include <stdio.h>
int		in_config(t_bot *bot, t_luneth *luneth)
{
  unsigned int	i;

  (void)(bot);
  printf("Servers [%zu]\n", luneth->config.servers.len);
  for (i = 0 ; i < luneth->config.servers.len ; ++i)
    {
      t_cfg_server	*server = luneth->config.servers.tab[i].value;
      printf("%s\n", server->name);
      printf("  onlog: %s.\n", str_safestr(&server->send_onlog));
      printf("  host:  %s.\n", server->hostname);
      printf("  nick:  %s.\n", server->nick);
      printf("  port:  %hu.\n", server->port);
      printf("  user:  %s.\n", server->username);
      printf("  real:  %s.\n", server->realname);
      printf("  pass:  %s.\n", server->password);
    }
  return (0);
}

static const char	*cmds[] =
{
  "list", "connect", "disconnect", "reload", "join", "msg", "config", NULL
};

static int	(* const fcts[])(t_bot *, t_luneth *) =
{
  &in_list, &in_connect, &in_disconnect, &in_reload, &in_join, &in_msg,
    &in_config, NULL
};

int		handle_input(t_bot *bot, char *cmd, t_luneth *luneth)
{
  unsigned int	i;
  char		*cmdname;

  i = 0;
  if (*(cmd++) == '/')
    {
      cmdname = strtok(cmd, " ");
      if (!*cmd)
	return (0);
      while (cmds[i])
	{
	  if (!strcasecmp(cmdname, cmds[i]))
	    return (fcts[i](bot, luneth));
	  ++i;
	}
    }
  return (0);
}
