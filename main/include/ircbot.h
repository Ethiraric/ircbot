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

// These are symbols to look for in the shared library

// Returns a pointer that will be passed to all other functions
# ifndef SYM_GET
#  define SYM_GET	"irc_data_get"
# endif
// Upon receiving an IRC message
# ifndef SYM_IRC
#  define SYM_IRC	"irc_on_mess"
# endif
// Called periodically
# ifndef SYM_PING
#  define SYM_PING	"irc_nothing"
# endif
// Upon receiving something in standard input
# ifndef SYM_STDIN
#  define SYM_STDIN	"irc_stdin"
# endif
// Deallocate what SYM_GET allocated
# ifndef SYM_DEL
#  define SYM_DEL	"irc_data_delete"
# endif

// Convenience structure managing read/write file descriptors for select()
typedef struct	s_net
{
  fd_set	rfds;	// readfds
  fd_set	wfds;	// writefds
  int		fdmax;	// nfds
}		t_net;

// The main bot structure (not the AI)
typedef struct	s_bot t_bot;
struct		s_bot
{
  struct timeval	timeref;  // select()'s timeout reference
  struct timeval	timeout;  // select()'s actual timeout
  struct timeval	*timeptr; // pointer to timeout (may be null)
  t_vector	conns;          // array of connections
  t_net		net;            // select()'s basic informations
  char		*so_name;       // If nonnull, the next loop, the AI will be
				// reloaded from this file
  bool		running;        // true if running, false otherwise
  void		*dlhandle;      // dlopen()'s handle
  void		*handler_data;  // The data of the AI
  int		argc;           // The program's argc
  char		**argv;         // The program's argv
  // The SYM_GET pointer
  int		(*handler_fct)(t_bot *, t_ircconnection *, void *);
  // The SYM_STDIN pointer
  int		(*handler_input_fct)(t_bot *, char *, void *);
  // The SYM_PING pointer
  int		(*handler_nothing_fct)(t_bot *, void *);
};

// Bot main functions
int	bot_select(t_bot *bot);
int	bot_connect(t_bot *bot, const char *hostname, unsigned short port,
		    const char *nick, const char *user, const char *realname,
		    const char *pass);
int	bot_disconnect(t_bot *bot, size_t pos);

// AI handling
int	loadAI(t_bot *bot, char *filename);
void	unloadAI(t_bot *bot);
int	handler_fct_none(t_bot *bot, t_ircconnection *co, void *dat);
int	handler_input_fct_none(t_bot *bot, char *input, void *dat);
int	handler_nothing_none(t_bot *bot, void *dat);

#endif /* !IRCBOT_H_ */
