/*
** luneth.h for  in /home/sabour_f/rendu/ircbot/AI/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 09:25:24 2015 Florian SABOURIN
** Last update Tue Apr 28 09:25:24 2015 Florian SABOURIN
*/

#ifndef LUNETH_H_
# define LUNETH_H_

# include <time.h>
# include "Pokemon.h"
# include "database.h"
# include "ircbot.h"
# include "config.h"

// Time between two hint reveal
# define HINT_DELAY		15

/*
** Contains informations needed for the pokemon quizz
*/
typedef struct	s_pokequizz
{
  t_ircconnection *co;     // The connection to the server where the quizz is
  time_t	next_hint; // When the next hint will be revealed
  char		*ans;      // The correct answer
  char		*ans2;     // Another correct answer (may be NULL)
  char		*question; // The question that was asked
  char		*hint;     // The hint
  char		*chan;     // The chan on which the quizz is
  bool		on;        // Whether the pokemon quizz is on or not
}		t_pokequizz;

/*
** The bot's main structure
*/
typedef struct	s_luneth
{
  t_pokequizz	pk;        // Pokemon quizz informations
  t_db		*db;       // Handle to the database
  t_config	config;    // Various configuration options (c.f. config.h)
  bool		speaks;    // Controls whether the bot is allowed to speak
  t_mapstring	*cmds;     // Bot commands. Automatic responses.
}		t_luneth;

  /* Miscellaneous useful commands */
char	*youtube_title(const char *code);
int	luneth_msg(t_ircconnection *co, t_luneth *luneth,
		   const char *dst, const char *msg);
int	luneth_msgf(t_ircconnection *co, t_luneth *luneth,
		    const char *dst, const char *fmt, ...);
int	luneth_respond_msg(t_ircconnection *co, t_luneth *luneth,
			   const char *msg);
int	luneth_respond_msgf(t_ircconnection *co, t_luneth *luneth,
			    const char *fmt, ...);

  /* stdin handling */
int		in_list(t_bot *bot, t_luneth *luneth);
int		in_connect(t_bot *bot, t_luneth *luneth);
int		in_disconnect(t_bot *bot, t_luneth *luneth);
int		in_reload(t_bot *bot, t_luneth *luneth);
int		in_join(t_bot *bot, t_luneth *luneth);
int		in_msg(t_bot *bot, t_luneth *luneth);
int		in_raw(t_bot *bot, t_luneth *luneth);
int		handle_input(t_bot *bot, char *cmd, t_luneth *luneth);

  /* irc messages handling */
int		mess_join(t_bot *bot, t_ircconnection *co, t_luneth *luneth);
int		mess_privmsg(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		handle_message(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);

  /* commands through PRIVMSG handling */
int		hl_all(t_ircconnection *co, t_luneth *luneth);
int		command_ping(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		command_action(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);
int		command_songid(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);
int		command_song(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		command_pokemon(t_bot *bot, t_ircconnection *co,
				t_luneth *luneth);
int		command_cmd(t_bot *bot, t_ircconnection *co,
			    t_luneth *luneth);
int		command_say(t_bot *bot, t_ircconnection *co,
			    t_luneth *luneth);
int		command_shifumi(t_bot *bot, t_ircconnection *co,
				t_luneth *luneth);
int		command_calc(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		command_self_command(t_bot *bot, t_ircconnection *co,
				     t_luneth *luneth);

  /* pokemon quizz */
void		pkq_terminate(t_luneth *luneth);
int		pkq_check_hint(t_luneth *luneth);
int		pkq_check_ans(t_luneth *luneth, t_ircconnection *co);
  /* question getters */
int		pkq_pfrname(t_luneth *luneth);
int		pkq_penname(t_luneth *luneth);
int		pkq_ptype(t_luneth *luneth);
int		pkq_afrname(t_luneth *luneth);
int		pkq_aenname(t_luneth *luneth);
int		pkq_atype(t_luneth *luneth);
int		pkq_frnum(t_luneth *luneth);

#endif /* !LUNETH_H_ */
