#include <stdlib.h>
#include <stdio.h>
#include "database.h"

t_chan		*database_get_chan_fromchanserv(t_db *db, const char *serv,
						const char *chan)
{
  t_mapstring	*res;
  t_chan	*tchan;
  char		*echan;
  char		*eserv;
  char		*req;
  int		ret;

  eserv = database_escape_quotes(serv);
  echan = database_escape_quotes(chan);
  if (!eserv || !echan)
    {
      free(eserv);
      return (NULL);
    }
  ret = asprintf(&req, "SELECT * FROM " TABLE_CHANS " WHERE "
		 "channel='%s' AND server='%s';", echan, eserv);
  free(eserv);
  free(echan);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  tchan = chan_from_db(res, 0);
  database_select_free_res(res);
  return (tchan);
}

t_id		database_insert_chan(t_db *db, const char *serv,
				     const char *chan)
{
  char		*echan;
  char		*eserv;
  char		*req;
  int		ret;

  eserv = database_escape_quotes(serv);
  echan = database_escape_quotes(chan);
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
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL,
		     &echan);
  if (ret != SQLITE_OK)
    {
      sqlite3_free(echan);
      return (0);
    }
  free(req);
  return (sqlite3_last_insert_rowid(db->handler));
}
