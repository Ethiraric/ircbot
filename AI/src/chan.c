/*
** chan.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  9 12:15:15 2015 Florian SABOURIN
** Last update Sat May  9 12:15:15 2015 Florian SABOURIN
*/

#include "database.h"
#include <stdlib.h>
#include <string.h>

t_chan* chan_from_db(t_mapstring* res, unsigned int it)
{
  t_vector* curr;
  t_chan* ret;

  ret = malloc(sizeof(t_chan));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_chan));
  if ((curr = mapstring_findcstr(res, "id")))
    ret->id = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "channel")) && vector_at(curr, it))
    if (!(ret->channel = strdup(vector_at(curr, it))))
      return (NULL + chan_delete(ret, true));
  if ((curr = mapstring_findcstr(res, "server")) && vector_at(curr, it))
    if (!(ret->server = strdup(vector_at(curr, it))))
      return (NULL + chan_delete(ret, true));
  return (ret);
}

int chan_delete(t_chan* chan, bool free_struct)
{
  free(chan->channel);
  chan->channel = 0;
  free(chan->server);
  chan->server = 0;
  chan->id = 0;
  if (free_struct)
    free(chan);
  return (0);
}
