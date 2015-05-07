/*
** database.h for  in /home/sabour_f/rendu/ircbot/AI/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri May  1 23:16:37 2015 Florian SABOURIN
** Last update Fri May  1 23:16:38 2015 Florian SABOURIN
*/

#ifndef DATABASE_H_
# define DATABASE_H_

# include <stdbool.h>
# include <sqlite3.h>
# include "t_mapstring.h"
# include "vector.h"

typedef unsigned int t_id;

typedef struct	s_song
{
  t_id		id;
  t_id		author;
  char		*title;
  char		*code;
  char		*category;
}		t_song;

t_song		*song_from_db(t_mapstring *res, unsigned int it);
int		song_delete(t_song *song, bool free_struct);

typedef struct	s_db
{
  sqlite3	*handler;
}		t_db;

t_db		*database_new(const char *filename);
void		database_delete(t_db *db);
t_song		*database_get_song_fromcode(t_db *db, unsigned int id);

#endif /* DATABASE_H_ */
