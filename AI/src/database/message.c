#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

t_id		database_insert_msg(t_db *db, const char *nick,
				    const char *chan, const char *serv,
				    const char *msg)
{
  t_id		pplid;
  char		*emsg;
  char		*req;
  int		ret;

  pplid = database_pplid(db, nick, serv, chan);
  if (!pplid)
    return (0);
  emsg = database_escape_quotes(msg);
  if (!emsg)
    return (0);
  ret = asprintf(&req, "INSERT INTO " TABLE_MESSAGES " (author, "
		 "message, date) VALUES (%u, '%s', DATETIME());",
		 pplid, emsg);
  free(emsg);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL, &emsg);
  free(req);
  if (ret != SQLITE_OK)
    return (0);
  return (sqlite3_last_insert_rowid(db->handler));
}
