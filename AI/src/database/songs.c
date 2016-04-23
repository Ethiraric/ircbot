#include "database.h"

t_song		*database_get_song_fromcode(t_db *db, const char *code)
{
  t_mapstring	*res;
  t_song	*song;
  char		*req;
  char		*ecode;
  int		ret;

  ecode = database_escape_quotes(code);
  if (!ecode)
    return (NULL);
  ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " WHERE code='%s';", ecode);
  free(ecode);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
}

t_id		database_insert_song(t_db *db, const char *code,
				     const char *categ, t_id auth)
{
  char		*ecode;
  char		*ecateg;
  char		*req;
  int		ret;

  ecode = database_escape_quotes(code);
  if (categ && !(ecateg = database_escape_quotes(categ)))
    {
      free(ecode);
      return (0);
    }
  if (categ)
    {
      ret = asprintf(&req, "INSERT INTO " TABLE_SONGS
		     " (code, author, category) VALUES ('%s', %u, '%s');",
		     ecode, auth, ecateg);
      free(ecateg);
    }
  else
    ret = asprintf(&req, "INSERT INTO " TABLE_SONGS
		   " (code, author) VALUES ('%s', %u);", ecode, auth);
  free(ecode);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &ecode);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(ecode);
      return (0);
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
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
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
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
}

t_song		*database_select_random_songcateg(t_db *db, const char *categ)
{
  t_mapstring	*res;
  t_song	*song;
  char		*req;
  char		*ecateg;
  int		ret;

  if (!categ)
    return (database_select_random_song(db));
  ecateg = database_escape_quotes(categ);
  if (!ecateg)
    return (NULL);
  ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " WHERE category='%s' "
		 " ORDER BY RANDOM() LIMIT 1;", ecateg);
  free(ecateg);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  song = song_from_db(res, 0);
  select_free_res(res);
  return (song);
}

int		database_edit_category(t_db *db, const char *code,
				       const char *categ)
{
  char		*ecateg;
  char		*req;
  int		ret;

  ecateg = database_escape_quotes(categ);
  if (!ecateg)
    return (0);
  ret = asprintf(&req, "UPDATE " TABLE_SONGS " SET category='%s' WHERE "
		 "code='%s';", ecateg, code);
  free(ecateg);
  if (ret == -1)
    return (1);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &ecateg);
  free(req);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(ecateg);
      return (1);
    }
  return (0);
}

int		database_edit_title(t_db *db, const char *code,
				    const char *title)
{
  char		*etitle;
  char		*req;
  int		ret;

  etitle = database_escape_quotes(title);
  if (!etitle)
    return (0);
  ret = asprintf(&req, "UPDATE " TABLE_SONGS " SET title='%s' WHERE "
		 "code='%s';", etitle, code);
  free(etitle);
  if (ret == -1)
    return (1);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &etitle);
  free(req);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(etitle);
      return (1);
    }
  return (0);
}

t_vector	*database_search_song(t_db *db, const char *pattern)
{
  t_mapstring	*res;
  t_vector	*songs;
  char		*req;
  char		*patt;
  int		ret;

  patt = NULL;
  if (pattern)
    if (!(patt = database_escape_quotes(pattern)))
      return (NULL);
  ret = 0;
  if (patt)
    ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " WHERE title"
		   " LIKE('%%%s%%');", patt);
  else
    ret = asprintf(&req, "SELECT * FROM " TABLE_SONGS " WHERE title"
		   " IS NULL;");
  free(patt);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  songs = song_tab_from_db(res);
  select_free_res(res);
  return (songs);
}
