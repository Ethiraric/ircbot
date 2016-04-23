#include "database.h"

t_id		database_pplid(t_db *db, const char *nick, const char *serv,
			       const char *chan)
{
  t_people	*ppl;
  t_id	chanid;
  t_id		ret;

  chanid = database_chanid(db, serv, chan);
  if (!chanid)
    return (0);
  ppl = database_get_ppl_fromnickchan(db, nick, chanid);
  if (!ppl && errno == ENOMEM)
    return (0);
  if (ppl)
    {
      ret = ppl->id;
      ppl_delete(ppl, true);
      return (ret);
    }
  return (database_insert_ppl(db, nick, chanid));
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

t_id		database_add_song(t_db *db, const char *code,
				  const char *categ, t_id auth)
{
  t_song	*song;

  song = database_get_song_fromcode(db, code);
  if (song)
    {
      song_delete(song, true);
      return (0);
    }
  return (database_insert_song(db, code, categ, auth));
}

t_people	*database_get_song_auth(t_db *db, const char *code)
{
  // TODO: CAN BE DONE WITH ONE REQUEST
  t_song	*song;
  t_people	*ret;

  song = database_get_song_fromcode(db, code);
  if (!song)
    return (NULL);
  ret = database_ppl_fromid(db, song->authid);
  song_delete(song, true);
  return (ret);
}

t_vector	*database_list_categories(t_db *db)
{
  t_mapstring	*res;
  t_vector	*categories;
  char		*req;
  int		ret;

  ret = asprintf(&req, "SELECT DISTINCT category FROM " TABLE_SONGS
		 " WHERE category NOT NULL ORDER BY category ASC;");
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  categories = mapstring_at(res, 0);
  free(res);
  return (categories);
}

int	database_add_score(t_db *db, const char *nickname, const char *channel,
			   const char *server, int modif)
{
  char	*err;
  char	*req;
  int	ret;

  ret = asprintf(&req, "UPDATE " TABLE_PEOPLE " SET score=score+%d WHERE "
		 "nick='%s' AND channel IN (SELECT id FROM " TABLE_CHANS
		 " WHERE server='%s' AND channel='%s');", modif, nickname,
		 server, channel);
  if (ret == -1)
    return (1);
  printf("Query: %s\n", req);
  ret = sqlite3_exec(db->handler, req, &callback_nothing, NULL, &err);
  if (ret != SQLITE_OK)
    return (1);
  free(req);
  return (0);
}
