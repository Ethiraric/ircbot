/*
** command_songid.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Wed May  6 12:05:23 2015 Florian SABOURIN
** Last update Wed May  6 12:05:23 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <errno.h>
#include <stdlib.h>

int command_songid(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  unsigned int val;
  t_song* song;
  char* nb;

  (void)(bot);
  nb = strtok(NULL, " ");
  if (nb && !strtok(NULL, " "))
  {
    val = atoi(nb);
    song = database_get_song_fromid(luneth->db, val);
    if (song)
    {
      luneth_respond_msgf(
          co,
          luneth,
          "song #%i -> https://www.youtube.com/watch?v=%s [%s] : %s",
          val,
          song->code,
          song->category ? song->category : "",
          song->title ? song->title : "");
      song_delete(song, true);
    }
    else if (errno == ENOMEM)
      return (1);
    else if (luneth_respond_msgf(co, luneth, "No song with id #%i", val))
      return (1);
  }
  return (0);
}
