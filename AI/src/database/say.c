#include "database.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

t_id database_insert_say(t_db* db, t_id auth, t_id dest, const char* text)
{
  char* etext;
  char* req;
  int ret;

  etext = database_escape_quotes(text);
  if (!etext)
    return (0);
  ret = asprintf(&req,
                 "INSERT INTO " TABLE_SAY
                 " (auth, dest, text) "
                 "VALUES (%u, %u, '%s');",
                 auth,
                 dest,
                 etext);
  free(etext);
  if (ret == -1)
    return (0);
  ret =
      sqlite3_exec(db->handler, req, &database_callback_nothing, NULL, &etext);
  free(req);
  if (ret != SQLITE_OK)
    return (0);
  return (sqlite3_last_insert_rowid(db->handler));
}

t_vector* database_get_say(t_db* db, t_id dest)
{
  t_mapstring* res;
  t_vector* says;
  char* req;
  int ret;

  ret = asprintf(&req, "SELECT * FROM " TABLE_SAY " WHERE dest=%u;", dest);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
  {
    free(res);
    return (NULL);
  }
  says = say_tab_from_db(res);
  database_select_free_res(res);
  return (says);
}

t_say* database_say_fromid(t_db* db, t_id id)
{
  t_mapstring* res;
  t_say* say;
  char* req;
  int ret;

  ret = asprintf(&req, "SELECT * FROM " TABLE_SAY " WHERE id=%u;", id);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
  {
    free(res);
    return (NULL);
  }
  say = say_from_db(res, 0);
  database_select_free_res(res);
  return (say);
}

int database_rm_say(t_db* db, t_id id)
{
  char* err;
  char* req;
  int ret;

  ret = asprintf(&req, "DELETE FROM " TABLE_SAY " WHERE id=%u;", id);
  if (ret == -1)
    return (1);
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL, &err);
  free(req);
  if (ret != SQLITE_OK)
    return (1);
  return (0);
}
