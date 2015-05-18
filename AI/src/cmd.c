/*
** cmd.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon May 18 17:03:31 2015 Florian SABOURIN
** Last update Mon May 18 17:03:31 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include "database.h"


t_cmd		*cmd_from_db(t_mapstring *res, unsigned int it)
{
  t_vector	*curr;
  t_cmd		*ret;

  ret = malloc(sizeof(t_cmd));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_cmd));
  if ((curr = mapstring_findcstr(res, "id")))
    ret->id = atoi(vector_at(curr, it));
  if ((curr = mapstring_findcstr(res, "cmd")) && vector_at(curr, it))
    if (!(ret->cmd = strdup(vector_at(curr, it))))
      return (NULL + cmd_delete(ret, true));
  if ((curr = mapstring_findcstr(res, "text")) && vector_at(curr, it))
    if (!(ret->text = strdup(vector_at(curr, it))))
      return (NULL + cmd_delete(ret, true));
  return (ret);
}

int		cmd_delete(t_cmd *cmd, bool free_struct)
{
  free(cmd->text);
  cmd->text = 0;
  free(cmd->cmd);
  cmd->cmd = 0;
  cmd->id = 0;
  if (free_struct)
    free(cmd);
  return (0);
}
