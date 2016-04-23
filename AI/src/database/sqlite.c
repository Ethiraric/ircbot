#include <stdlib.h>
#include "database.h"

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

char	*database_escape_quotes(const char *in)
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
  len += curr - in + 1;
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

// Returns a pointer to a mapstring.
// The mapstring maps the columns. Each of the columns contains a vector,
// where each of the indexes is the row.
// For example, if there is a column named "id", you can get the number of rows
// with vector_size(mapstring_findcstr(map, "id")).
t_mapstring	*database_select_exec(t_db *db, const char *statement)
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
