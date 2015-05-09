/*
** database.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  2 00:03:49 2015 Florian SABOURIN
** Last update Sat May  2 00:03:49 2015 Florian SABOURIN
*/

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "database.h"

#define TABLE_MESSAGES		"messages"
#define TABLE_SONGS		"musics"
#define TABLE_PEOPLE		"authors"
#define TABLE_CHANS		"chans"

/*
** sqlite3 helpers
*/

static int	callback_nothing(__attribute__((unused))void *param,
				 __attribute__((unused))int argc,
				 __attribute__((unused))char **argv,
				 __attribute__((unused))char **column_names)
{
  return (0);
}

static char	*escape_quotes(const char *in)
{
  size_t	len;
  const char	*curr;
  char		*ret;
  char		*it;
  char		*res;

  len = 0;
  curr = in;
  /* Count chars to escape, one char will be added for each one of them */
  while (*(curr = strchrnul(curr, '\'')))
    {
      ++len;
      ++curr;
    }
  /* Add size of the string (including '\0') */
  len += curr - in;
  ret = malloc(len);
  if (!ret)
    return (NULL);
  it = ret;
  curr = in;
  while (*(res = strchrnul(curr, '\'')))
    {
      /* Copy chars until a quote is met, then escape */
      it = stpncpy(it, curr, res - curr);
      it = stpcpy(it, "''");
      curr = res + 1;
    }
  /* Copy the rest of the string */
  strcpy(it, curr);
  return (ret);
}

int		select_free_res(t_mapstring *map)
{
  unsigned int	i;
  unsigned int	j;
  t_vector	*vec;

  i = 0;
  while (i < mapstring_size(map))
    {
      vec = mapstring_at(map, i);
      if (vec)
	{
	  j = 0;
	  while (j < vector_size(vec))
	    {
	      free(vector_at(vec, j));
	      ++j;
	    }
	  vector_delete(vec, true);
	}
      ++i;
    }
  mapstring_delete(map);
  free(map);
  return (0);
}

static int	select_exec_init_cols(t_mapstring *map,
				      sqlite3_stmt *stmt,
				      int cols)
{
  t_vector	*vec;
  int		i;

  i = 0;
  while (i < cols)
    {
      vec = malloc(sizeof(t_vector));
      if (!vec)
	return (select_free_res(map) | 1);
      vector_new(vec);
      if (mapstring_insertcstr(map, sqlite3_column_name(stmt, i), vec))
	return (select_free_res(map) | 1);
      ++i;
    }
  return (0);
}

static int	select_add_row(t_vector **tab, sqlite3_stmt *stmt, int cols)
{
  const char	*name;
  char		*dup;
  int		i;

  i = 0;
  while (i < cols)
    {
      name = (const char *)sqlite3_column_text(stmt, i);
      if (name)
	{
	  if (!(dup = strdup(name)))
	    return (1);
	}
      else
	dup = NULL;
      if (vector_push_back(tab[i], dup))
	{
	  free(dup);
	  return (1);
	}
      ++i;
    }
  return (0);
}

static int	select_build_results(t_mapstring *map, sqlite3_stmt *stmt,
				     int cols, int ret)
{
  t_vector	*tab[20] = { 0 };
  int		i;

  i = 0;
  while (i < cols)
    {
      tab[i] = mapstring_findcstr(map, sqlite3_column_name(stmt, i));
      ++i;
    }
  while (ret == SQLITE_ROW)
    {
      if (select_add_row(tab, stmt, cols))
	return (1);
      ret = sqlite3_step(stmt);
    }
  return (0);
}

static t_mapstring	*select_exec(t_db *db, const char *statement)
{
  sqlite3_stmt		*stmt;
  t_mapstring		*map;
  int			ret;
  int			cols;

  if (sqlite3_prepare(db->handler, statement, -1, &stmt, NULL) != SQLITE_OK)
    return (NULL);
  map = malloc(sizeof(t_mapstring));
  if (map)
    {
      mapstring_new(map);
      cols = sqlite3_column_count(stmt);
      if ((ret = sqlite3_step(stmt)) == SQLITE_ROW &&
	  (select_exec_init_cols(map, stmt, cols) ||
	   select_build_results(map, stmt, cols, ret)))
	{
	  free(map);
	  sqlite3_finalize(stmt);
	  return (NULL);
	}
    }
  sqlite3_finalize(stmt);
  return (map);
}

/*
** ctor / dtor
*/

t_db		*database_new(const char *filename)
{
  t_db		*ret;

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

void		database_delete(t_db *db)
{
  if (db->handler)
    {
      sqlite3_close(db->handler);
      free(db);
    }
}

/*
** General operations
*/

t_people	*database_get_ppl_fromnickchan(t_db *db, const char *nick,
					       const char *chan)
{
  t_mapstring	*res;
  t_people	*ppl;
  char		*enick;
  char		*echan;
  char		*req;
  int		ret;

  enick = escape_quotes(nick);
  echan = escape_quotes(chan);
  if (!enick || !echan)
    {
      free(enick);
      return (NULL);
    }
  ret = asprintf(&req, "SELECT * FROM " TABLE_PEOPLE " WHERE "
		 "nick='%s' AND channel='%s';", enick, echan);
  free(enick);
  free(echan);
  if (ret == -1)
    return (NULL);
  res = select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    return (NULL);
  ppl = ppl_from_db(res, 0);
  select_free_res(res);
  return (ppl);
}

t_id		database_insert_ppl(t_db *db, const char *nick,
				     const char *chan)
{
  char		*enick;
  char		*echan;
  char		*req;
  int		ret;

  enick = escape_quotes(nick);
  echan = escape_quotes(chan);
  if (!enick || !echan)
    {
      free(echan);
      return (0);
    }
  ret = asprintf(&req, "INSERT INTO " TABLE_PEOPLE " (nick, channel) VALUES "
		 "('%s', '%s');", enick, echan);
  free(enick);
  free(echan);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &enick);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(enick);
      ret = 1;
    }
  free(req);
  return (sqlite3_last_insert_rowid(db->handler));
}

t_song		*database_get_song_fromid(t_db *db, unsigned int id)
{
  t_mapstring	*res;
  t_song	*song;
  char		*req;
  int		ret;

  ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " WHERE id=%u;", id);
  if (ret == -1)
    return (NULL);
  res = select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    return (NULL);
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
}

t_chan		*database_get_chan_fromchanserv(t_db *db, const char *serv,
						const char *chan)
{
  t_mapstring	*res;
  t_chan	*tchan;
  char		*echan;
  char		*eserv;
  char		*req;
  int		ret;

  eserv = escape_quotes(serv);
  echan = escape_quotes(chan);
  if (!eserv || !echan)
    {
      free(eserv);
      return (NULL);
    }
  ret = asprintf(&req, "SELECT * FROM " TABLE_CHANS " WHERE "
		 "chan='%s' AND serv='%s';", echan, eserv);
  free(eserv);
  free(echan);
  if (ret == -1)
    return (NULL);
  res = select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    return (NULL);
  tchan = chan_from_db(res, 0);
  select_free_res(res);
  return (tchan);
}

t_id		database_insert_chan(t_db *db, const char *serv,
				     const char *chan)
{
  char		*echan;
  char		*eserv;
  char		*req;
  int		ret;

  eserv = escape_quotes(serv);
  echan = escape_quotes(chan);
  if (!eserv || !echan)
    {
      free(echan);
      return (0);
    }
  ret = asprintf(&req, "INSERT INTO " TABLE_CHANS " (channel, server) VALUES "
		 "('%s', '%s');", echan, eserv);
  free(eserv);
  free(echan);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &echan);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(echan);
      return (0);
    }
  free(req);
  return (sqlite3_last_insert_rowid(db->handler));
}

t_song		*database_select_random_song(t_db *db)
{
  t_mapstring	*res;
  t_song	*song;
  char		*req;
  int		ret;

  ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " ORDER BY RANDOM() "
		 "LIMIT 1;");
  if (ret == -1)
    return (NULL);
  res = select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    return (NULL);
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
}

/*
** DB helpers
*/

t_id		database_pplid(t_db *db, const char *nick, const char *chan)
{
  t_people	*ppl;
  t_id		ret;

  ppl = database_get_ppl_fromnickchan(db, nick, chan);
  if (!ppl && errno == ENOMEM)
    return (0);
  if (ppl)
    {
      ret = ppl->id;
      ppl_delete(ppl, true);
      return (ret);
    }
  return (database_insert_ppl(db, nick, chan));
}

t_id		database_chanid(t_db *db, const char *serv, const char *chan)
{
  t_chan	*tchan;
  t_id		ret;

  tchan = database_get_chan_fromchanserv(db, serv, chan);
  if (!tchan && errno == ENOMEM)
    return (0);
  if (tchan)
    {
      ret = tchan->id;
      chan_delete(tchan, true);
      return (ret);
    }
  return (database_insert_chan(db, serv, chan));
}

t_id		database_insert_msg(t_db *db, const char *nick,
				    const char *chan, const char *serv,
				    const char *msg)
{
  t_id		pplid;
  t_id		chanid;
  char		*emsg;
  char		*req;
  int		ret;

  pplid = database_pplid(db, nick, chan);
  if (!pplid)
    return (0);
  chanid = database_chanid(db, serv, chan);
  if (!chanid)
    return (0);
  emsg = escape_quotes(msg);
  if (!emsg)
    return (0);
  ret = asprintf(&req, "INSERT INTO " TABLE_MESSAGES " (author, channel, "
		 "message, date) VALUES ('%u', '%u', '%s', DATETIME());",
		 pplid, chanid, emsg);
  free(emsg);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &emsg);
  if (ret != SQLITE_OK)
    {
      free(req);
      return (0);
    }
  return (sqlite3_last_insert_rowid(db->handler));
}