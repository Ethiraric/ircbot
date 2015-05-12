/*
** song.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Wed May  6 18:18:18 2015 Florian SABOURIN
** Last update Wed May  6 18:18:18 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "database.h"

t_song		*song_from_db(t_mapstring *res, unsigned int it)
{
  t_vector	*curr;
  t_song	*ret;

  ret = malloc(sizeof(t_song));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_song));
  if ((curr = mapstring_findcstr(res, "id")))
    ret->id = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "author")) && vector_at(curr, it))
    ret->authid = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "code")) && vector_at(curr, it))
    if (!(ret->code = strdup(vector_at(curr, it))))
      return (NULL + song_delete(ret, true));
  if ((curr = mapstring_findcstr(res, "title")) && vector_at(curr, it))
    if (!(ret->title = strdup(vector_at(curr, it))))
      return (NULL + song_delete(ret, true));
  if ((curr = mapstring_findcstr(res, "category")) && vector_at(curr, it))
    if (!(ret->category = strdup(vector_at(curr, it))))
      return (NULL + song_delete(ret, true));
  return (ret);
}

int		song_delete(t_song *song, bool free_struct)
{
  free(song->title);
  song->title = 0;
  free(song->code);
  song->code = 0;
  free(song->category);
  song->category = 0;
  song->id = 0;
  song->authid = 0;
  if (free_struct)
    free(song);
  return (0);
}

t_vector	*song_tab_from_db(t_mapstring *res)
{
  t_vector	*ret;
  t_song	*song;
  size_t	len;
  size_t	it;

  len = vector_size(mapstring_findcstr(res, "id"));
  ret = malloc(sizeof(t_vector));
  if (!ret)
    return (NULL);
  it = 0;
  vector_new(ret);
  while (it < len)
    {
      song = song_from_db(res, it);
      if (!song)
	{
	  vector_foreach(ret, &free);
	  vector_delete(ret, true);
	  return (NULL);
	}
      if (vector_push_back(ret, song))
	{
	  song_delete(song, true);
	  vector_foreach(ret, &free);
	  vector_delete(ret, true);
	  return (NULL);
	}
      ++it;
    }
  return (ret);
}
