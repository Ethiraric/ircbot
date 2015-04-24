/*
** ircbot.h for  in /home/sabour_f/rendu/ircbot/main/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 23 23:46:24 2015 Florian SABOURIN
** Last update Thu Apr 23 23:46:24 2015 Florian SABOURIN
*/

#ifndef IRCBOT_H_
# define IRCBOT_H_

# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include "irc.h"
# include "vector.h"

typedef struct	s_bot
{
  struct timeval	timeout;
  struct timeval	*timeptr;
  t_vector	conns;
  void		*dlhandle;
  void		*handler_data;
  int		(*handler_fct)(t_ircconnection *, void *);
}		t_bot;

#endif /* !IRCBOT_H_ */
