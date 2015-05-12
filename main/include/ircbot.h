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

# ifndef SYM_GET
#  define SYM_GET	"irc_data_get"
# endif
# ifndef SYM_IRC
#  define SYM_IRC	"irc_on_mess"
# endif
# ifndef SYM_PING
#  define SYM_PING	"irc_nothing"
# endif
# ifndef SYM_STDIN
#  define SYM_STDIN	"irc_stdin"
# endif
# ifndef SYM_DEL
#  define SYM_DEL	"irc_data_delete"
# endif

typedef struct	s_net
{
  fd_set	rfds;
  fd_set	wfds;
  int		fdmax;
}		t_net;

typedef struct	s_bot t_bot;
struct		s_bot
{
  struct timeval	timeref;
  struct timeval	timeout;
  struct timeval	*timeptr;
  t_vector	conns;
  t_net		net;
  bool		running;
  void		*dlhandle;
  void		*handler_data;
  int		(*handler_fct)(t_bot *, t_ircconnection *, void *);
  int		(*handler_input_fct)(t_bot *, char *, void *);
  int		(*handler_nothing_fct)(t_bot *, void *);
};

int		bot_select(t_bot *bot);
int	bot_connect(t_bot *bot, const char *hostname, unsigned short port,
		    const char *nick, const char *user, const char *realname,
		    const char *pass);
int		bot_disconnect(t_bot *bot, size_t pos);

  /* AI handling */
int		loadAI(t_bot *bot, char *filename);
void		unloadAI(t_bot *bot);
int		handler_fct_none(t_bot *bot, t_ircconnection *co, void *dat);
int		handler_input_fct_none(t_bot *bot, char *input, void *dat);

#endif /* !IRCBOT_H_ */
