#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

t_people	*database_get_ppl_fromnickchan(t_db *db, const char *nick,
					       t_id chan)
{
  t_mapstring	*res;
  t_people	*ppl;
  char		*enick;
  char		*req;
  int		ret;

  enick = database_escape_quotes(nick);
  if (!enick)
    return (NULL);
  ret = asprintf(&req, "SELECT * FROM " TABLE_PEOPLE " WHERE "
		 "nick='%s' AND channel=%u;", enick, chan);
  free(enick);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  ppl = ppl_from_db(res, 0);
  database_select_free_res(res);
  return (ppl);
}

t_id		database_insert_ppl(t_db *db, const char *nick, t_id chan)
{
  char		*enick;
  char		*req;
  int		ret;

  enick = database_escape_quotes(nick);
  if (!enick)
      return (0);
  ret = asprintf(&req, "INSERT INTO " TABLE_PEOPLE " (nick, channel) VALUES "
		 "('%s', %u);", enick, chan);
  free(enick);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL,
		     &enick);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(enick);
      ret = 1;
    }
  free(req);
  return (sqlite3_last_insert_rowid(db->handler));
}

t_people	*database_ppl_fromid(t_db *db, t_id id)
{
  t_mapstring	*res;
  t_people	*ppl;
  char		*req;
  int		ret;

  ret = asprintf(&req, "SELECT * FROM " TABLE_PEOPLE " WHERE id=%u;", id);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  ppl = ppl_from_db(res, 0);
  database_select_free_res(res);
  return (ppl);
}
