/*
** say.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon May 18 18:50:45 2015 Florian SABOURIN
** Last update Mon May 18 18:50:46 2015 Florian SABOURIN
*/

#include "database.h"
#include <stdlib.h>
#include <string.h>

t_say* say_from_db(t_mapstring* res, unsigned int it)
{
  t_vector* curr;
  t_say* ret;

  ret = malloc(sizeof(t_say));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_say));
  if ((curr = mapstring_findcstr(res, "id")))
    ret->id = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "auth")))
    ret->auth = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "dest")))
    ret->dest = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "text")) && vector_at(curr, it))
    if (!(ret->text = strdup(vector_at(curr, it))))
      return (NULL + say_delete(ret, true));
  return (ret);
}

int say_delete(t_say* say, bool free_struct)
{
  free(say->text);
  say->text = 0;
  say->id = 0;
  say->auth = 0;
  say->dest = 0;
  if (free_struct)
    free(say);
  return (0);
}

t_vector* say_tab_from_db(t_mapstring* res)
{
  t_vector* ret;
  t_say* say;
  size_t len;
  size_t it;

  len = vector_size(mapstring_findcstr(res, "id"));
  ret = malloc(sizeof(t_vector));
  if (!ret)
    return (NULL);
  it = 0;
  vector_new(ret);
  while (it < len)
  {
    say = say_from_db(res, it);
    if (!say)
    {
      vector_foreach(ret, &free);
      vector_delete(ret, true);
      return (NULL);
    }
    if (vector_push_back(ret, say))
    {
      say_delete(say, true);
      vector_foreach(ret, &free);
      vector_delete(ret, true);
      return (NULL);
    }
    ++it;
  }
  return (ret);
}
