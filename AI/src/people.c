/*
** people.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu May  7 18:41:40 2015 Florian SABOURIN
** Last update Thu May  7 18:41:41 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "database.h"

t_people	*ppl_from_db(t_mapstring *res, unsigned int it)
{
  t_vector	*curr;
  t_people	*ret;

  ret = malloc(sizeof(t_people));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_people));
  if ((curr = mapstring_findcstr(res, "id")))
    ret->id = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "score")))
    ret->score = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "channel")) && vector_at(curr, it))
    ret->channel = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "nick")) && vector_at(curr, it))
    if (!(ret->nick = strdup(vector_at(curr, it))))
      return (NULL + ppl_delete(ret, true));
  return (ret);
}

int		ppl_delete(t_people *ppl, bool free_struct)
{
  free(ppl->nick);
  ppl->nick = 0;
  ppl->channel = 0;
  ppl->id = 0;
  ppl->score = 0;
  if (free_struct)
    free(ppl);
  return (0);
}
