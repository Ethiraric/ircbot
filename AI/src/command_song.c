/*
** command_song.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  9 15:39:25 2015 Florian SABOURIN
** Last update Sat May  9 15:39:25 2015 Florian SABOURIN
*/

#include <errno.h>
#include <stdlib.h>
#include "luneth.h"

int		command_song(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth)
{
  t_song	*song;
  char		*category;

  (void)(bot);
  category = strtok(NULL, " ");
  song = database_select_random_songcateg(luneth->db, category);
  if (song)
    {
      irc_msgf(co, co->cmd.args[0],
	  "%s -> https://www.youtube.com/watch?v=%s [%s] : %s",
	  co->cmd.prefixnick, song->code,
	  song->category ? song->category : "",
	  song->title ? song->title : "");
      song_delete(song, true);
    }
  else if (errno == ENOMEM)
    return (1);
  else if (irc_msgf(co, co->cmd.args[0], "Failed to find the song"))
    return (1);
  return (0);
}
