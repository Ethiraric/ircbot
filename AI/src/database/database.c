/*
** database.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  2 00:03:49 2015 Florian SABOURIN
** Last update Sat May  2 00:03:49 2015 Florian SABOURIN
*/

#include "database.h"
#include <stdlib.h>

/*
** ctor / dtor
*/

t_db* database_new(const char* filename)
{
  t_db* ret;

  ret = malloc(sizeof(t_db));
  if (!ret)
    return (NULL);
  ret->handler = NULL;
  if (sqlite3_open(filename, &ret->handler))
  {
    free(ret);
    return (NULL);
  }
  return (ret);
}

void database_delete(t_db* db)
{
  if (db->handler)
  {
    sqlite3_close(db->handler);
    free(db);
  }
}
