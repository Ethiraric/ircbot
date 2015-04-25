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

typedef struct	s_net
{
  fd_set	rfds;
  fd_set	wfds;
  int		fdmax;
}		t_net;

typedef struct	s_bot t_bot;
struct	s_bot
{
  struct timeval	timeout;
  struct timeval	*timeptr;
  t_vector	conns;
  t_net		net;
  bool		running;
  void		*dlhandle;
  void		*handler_data;
  int		(*handler_fct)(t_bot *, t_ircconnection *, void *);
  int		(*handler_input_fct)(t_bot *, void *);
};

int		bot_select(t_bot *bot);

#endif /* !IRCBOT_H_ */