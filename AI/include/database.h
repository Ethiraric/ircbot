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

typedef struct	s_chan
{
  t_id		id;
  char		*channel;
  char		*server;
}		t_chan;

int		chan_delete(t_chan *chan, bool free_struct);
t_chan		*chan_from_db(t_mapstring *res, unsigned int it);

typedef struct	s_song
{
  t_id		id;
  t_id		authid;
  char		*title;
  char		*code;
  char		*category;
}		t_song;

t_song		*song_from_db(t_mapstring *res, unsigned int it);
int		song_delete(t_song *song, bool free_struct);

typedef struct	s_people
{
  t_id		id;
  char		*nick;
  char		*channel;
  unsigned int	score;
}		t_people;

t_people	*ppl_from_db(t_mapstring *res, unsigned int it);
int		ppl_delete(t_people *ppl, bool free_struct);

typedef struct	s_db
{
  sqlite3	*handler;
}		t_db;

t_db		*database_new(const char *filename);
void		database_delete(t_db *db);

  // People
t_song		*database_get_song_fromid(t_db *db, unsigned int id);
t_id		database_insert_ppl(t_db *db, const char *nick,
				     const char *chan);

  // Channel
t_chan		*database_get_chan_fromchanserv(t_db *db, const char *serv,
						const char *chan);
t_id		database_insert_chan(t_db *db, const char *serv,
				     const char *chan);

  // Song
t_song		*database_get_song_fromid(t_db *db, unsigned int id);
t_song		*database_select_random_song(t_db *db);

  // DB helpers
t_id		database_pplid(t_db *db, const char *nick, const char *chan);
t_id		database_chanid(t_db *db, const char *serv, const char *chan);

#endif /* DATABASE_H_ */
