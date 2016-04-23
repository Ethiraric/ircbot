#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

static int callback_mapstring_delete_cmd(const t_string *key, void *value)
{
  (void)(key);
  cmd_delete((t_cmd *)(value), true);
  return (0);
}

bool		database_is_command(t_db *db, const char *cmd)
{
  t_mapstring	*res;
  char		*req;
  char		*ecmd;
  int		ret;

  ecmd = database_escape_quotes(cmd);
  if (!ecmd)
    return (false);
  ret = asprintf(&req, "SELECT id FROM " TABLE_CMD " WHERE cmd='%s';",
		 ecmd);
  free(ecmd);
  if (ret == -1)
    return (false);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (false);
    }
  database_select_free_res(res);
  return (true);
}

t_id		database_insert_command(t_db *db, const char *cmd,
					const char *text)
{
  char		*ecmd;
  char		*etext;
  char		*req;
  int		ret;

  if (!(ecmd = database_escape_quotes(cmd)) ||
      !(etext = database_escape_quotes(text)))
    {
      free(ecmd);
      return (0);
    }
  ret = asprintf(&req,"INSERT INTO " TABLE_CMD " (cmd, text) "
		 "VALUES ('%s', '%s');", ecmd, etext);
  free(ecmd);
  free(etext);
  if (ret == -1)
    return (0);
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL, &ecmd);
  free(req);
  if (ret != SQLITE_OK)
    return (0);
  return (sqlite3_last_insert_rowid(db->handler));
}

t_cmd		*database_get_cmd(t_db *db, const char *cmd)
{
  t_mapstring	*res;
  t_cmd		*cmdr;
  char		*req;
  char		*ecmd;
  int		ret;

  ecmd = database_escape_quotes(cmd);
  if (!ecmd)
    return (NULL);
  ret = asprintf(&req, "SELECT * FROM " TABLE_CMD " WHERE cmd='%s';",
		 ecmd);
  free(ecmd);
  if (ret == -1)
    return (NULL);
  res = database_select_exec(db, req);
  free(req);
  if (!res || !mapstring_size(res))
    {
      free(res);
      return (NULL);
    }
  cmdr = cmd_from_db(res, 0);
  database_select_free_res(res);
  return (cmdr);
}

int		database_rm_cmd(t_db *db, const char *cmd)
{
  char		*ecmd;
  char		*req;
  int		ret;

  errno = 0;
  ecmd = database_escape_quotes(cmd);
  if (!ecmd)
    return (1);
  ret = asprintf(&req,"DELETE FROM " TABLE_CMD " WHERE cmd='%s';", ecmd);
  free(ecmd);
  if (ret == -1)
    return (1);
  ret = sqlite3_exec(db->handler, req, &database_callback_nothing, NULL, &ecmd);
  free(req);
  if (ret != SQLITE_OK)
    return (1);
  return (0);
}

t_mapstring	*database_load_all_cmds(t_db *db)
{
  t_mapstring	*res;
  t_mapstring	*cmds;
  t_vector	*ids;
  t_cmd		*cmdr;

  cmds = malloc(sizeof(t_mapstring));
  if (!cmds)
    return (NULL);
  mapstring_new(cmds);
  res = database_select_exec(db, "SELECT * FROM " TABLE_CMD ";");
  if (!res)
    {
      free(cmds);
      return (NULL);
    }
  if (!mapstring_size(res))
    return (cmds);
  ids = mapstring_findcstr(res, "id");
  if (!ids)
    {
      free(cmds);
      database_select_free_res(res);
      return (NULL);
    }
  for (unsigned int i = 0 ; i < vector_size(ids) ; ++i)
    {
      cmdr = cmd_from_db(res, i);
      if (!cmdr || mapstring_insertcstr(cmds, cmdr->cmd, cmdr))
	{
	  if (cmdr)
	    cmd_delete(cmdr, true);
	  mapstring_foreach(cmds, &callback_mapstring_delete_cmd);
	  mapstring_delete(cmds);
	  free(cmds);
	  database_select_free_res(res);
	  return (NULL);
	}
    }
  database_select_free_res(res);
  return (cmds);
}
