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

static const char	*cmds[] =
{
  "list", "connect", "disconnect", "reload", "join", NULL
};

static int	(* const fcts[])(t_bot *, t_luneth *) =
{
  &in_list, &in_connect, &in_disconnect, &in_reload, &in_join, NULL
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
