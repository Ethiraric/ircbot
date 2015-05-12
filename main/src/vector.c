/*
** vector.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Apr 24 17:55:52 2015 Florian SABOURIN
** Last update Fri Apr 24 17:55:53 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include "vector.h"

void		vector_delete(t_vector *vec, bool free_struct)
{
  free(vec->tab);
  vec->allocd = 0;
  vec->len = 0;
  if (free_struct)
    free(vec);
}

int		vector_erase(t_vector *vec, unsigned int pos)
{
  unsigned int	i;

  if (pos >= vec->len)
    return (1);
  i = pos;
  --(vec->len);
  while (i < vec->len)
    {
      vec->tab[i] = vec->tab[i + 1];
      ++i;
    }
  if (vec->allocd - vec->len > 2 * vec->alloc_step)
    if (vector_realloc(vec, vec->allocd - vec->alloc_step))
      return (1);
  return (0);
}

unsigned int	vector_find(t_vector *vec, void *elem)
{
  unsigned int	it;

  it = 0;
  while (it < vec->len)
    {
      if (vec->tab[it] == elem)
	return (it);
      ++it;
    }
  return ((unsigned int)(-1));
}

int		vector_insert(t_vector *v, unsigned int pos, void *elem)
{
  if (pos > v->len)
    return (1);
  if (v->len + 1 > v->allocd &&
      vector_realloc(v, v->allocd + v->alloc_step))
    return (1);
  memmove(&v->tab[pos + 1], &v->tab[pos], (v->len - pos) * sizeof(void *));
  v->tab[pos] = elem;
  ++(v->len);
  return (0);
}

void		vector_new(t_vector *vec)
{
  static const t_vector	ret = { 0, 0, 10, NULL };

  *vec = ret;
}

void		vector_pop_back(t_vector *vec)
{
  if (vec->len)
    --(vec->len);
}

int		vector_push_back(t_vector *vec, void *elem)
{
  if (vec->len + 1 > vec->allocd &&
      vector_realloc(vec, vec->allocd + vec->alloc_step))
    return (1);
  vec->tab[vec->len] = elem;
  ++(vec->len);
  return (0);
}

int		vector_realloc(t_vector *v, size_t size)
{
  void		*newptr;

  if ((newptr = realloc(v->tab, size * sizeof(void *))) == NULL)
    return (1);
  v->tab = newptr;
  v->allocd = size;
  if (v->allocd < v->len)
    v->len = v->allocd;
  return (0);
}

size_t		vector_size(const t_vector *v)
{
  return (v->len);
}

void		*vector_at(t_vector *v, size_t pos)
{
  return (v->tab[pos]);
}

void		vector_foreach(t_vector *v, void (*fct)(void *))
{
  size_t	it;

  it = 0;
  while (it < v->len)
    {
      fct(v->tab[it]);
      ++it;
    }
}
