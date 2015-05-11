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

# include "database.h"
# include "ircbot.h"

typedef struct	s_luneth
{
  t_db		*db;
}		t_luneth;

  /* stdin handling */
int		in_list(t_bot *bot, t_luneth *luneth);
int		in_connect(t_bot *bot, t_luneth *luneth);
int		in_disconnect(t_bot *bot, t_luneth *luneth);
int		handle_input(t_bot *bot, char *cmd, t_luneth *luneth);

  /* irc messages handling */
int		mess_join(t_bot *bot, t_ircconnection *co, t_luneth *luneth);
int		mess_privmsg(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		handle_message(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);

  /* commands through PRIVMSG handling */
int		command_ping(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);
int		command_action(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);
int		command_songid(t_bot *bot, t_ircconnection *co,
			       t_luneth *luneth);
int		command_song(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth);

#endif /* !LUNETH_H_ */
