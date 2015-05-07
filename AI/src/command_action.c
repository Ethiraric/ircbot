/*
** command_action.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri May  1 13:09:42 2015 Florian SABOURIN
** Last update Fri May  1 13:09:43 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include "luneth.h"

static char	*get_target(t_channel *chan)
{
  unsigned long	pos;
  t_user	*user;

  pos = (unsigned long)random();
  pos %= mapstring_size(&chan->users);
  user = mapstring_at(&chan->users, pos);
  if (!user)
    return (NULL);
  return (str_str(&user->nick));
}

int		command_action(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth)
{
  t_channel	*chan;
  char		*act;
  char		*target;

  (void)(luneth);
  (void)(bot);
  chan = mapstring_findcstr(&co->chanlist, co->cmd.args[0]);
  act = strtok(NULL, "");
  if (act && chan)
    {
      act += strspn(act, " ");
      target = get_target(chan);
      if (*act && target)
	{
	  if (!strcmp(target, co->cmd.prefixnick))
	    {
	      if (strchr("aeiouy", *act))
		return (irc_msgf(co, co->cmd.args[0],
			"%s s'%s", co->cmd.prefixnick, act));
	      return (irc_msgf(co, co->cmd.args[0],
		      "%s se %s", co->cmd.prefixnick, act));
	    }
	  return (irc_msgf(co, co->cmd.args[0],
		  "%s %s %s", co->cmd.prefixnick, act, target));
	}
    }
  return (0);
}
