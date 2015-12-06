/*
** config_modules.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Dec 04 01:32:26 2015 Florian SABOURIN
** Last update Fri Dec 04 01:32:26 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "config.h"

/*
** Create a new server entry in the configuration
*/
t_cfg_server	*cfg_server_new(const char *name)
{
  t_cfg_server	*ret;

  ret = malloc(sizeof(t_cfg_server));
  if (!ret)
    return (NULL);
  ret->name = strdup(name);
  if (!ret->name)
    {
      free(ret);
      return (NULL);
    }
  str_newfromcstr(&ret->send_onlog, "");
  ret->hostname = NULL;
  ret->nick = NULL;
  ret->port = 6667; // Default IRC port
  ret->username = NULL;
  ret->realname = NULL;
  ret->password = NULL;
  return (ret);
}

/*
** Deallocates a server entry in the configuration
*/
void		cfg_server_delete(t_cfg_server *server)
{
  free(server->name);
  str_delete(&server->send_onlog);
  free(server->hostname);
  free(server->nick);
  free(server->username);
  free(server->realname);
  free(server->password);
  free(server);
}
