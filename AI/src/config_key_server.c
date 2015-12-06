/*
** config_key_server.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sun Dec 06 06:34:36 2015 Florian SABOURIN
** Last update Sun Dec 06 06:34:36 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"

/*
** When we meet the server.<servername>.nick configuration
** We must change the server's default nickname when connecting
*/
static int	server_nick(t_cfg_server *server, char *value)
{
  char		*newnick;

  if (*value)
    {
      newnick = strdup(value);
      if (!newnick)
	{
	  perror("strdup");
	  return (1);
	}
    }
  else
    newnick = NULL;
  free(server->nick);
  server->nick = newnick;
  return (0);
}

/*
** When we meet the server.<servername>.hostname configuration
** We must change the server's default hostname when connecting
*/
static int	server_hostname(t_cfg_server *server, char *value)
{
  char		*newhost;

  if (*value)
    {
      newhost = strdup(value);
      if (!newhost)
	{
	  perror("strdup");
	  return (1);
	}
    }
  else
    newhost = NULL;
  free(server->hostname);
  server->hostname = newhost;
  return (0);
}

/*
** When we meet the server.<servername>.username configuration
** We must change the server's default username when connecting
*/
static int	server_username(t_cfg_server *server, char *value)
{
  char		*newuser;

  if (*value)
    {
      newuser = strdup(value);
      if (!newuser)
	{
	  perror("strdup");
	  return (1);
	}
    }
  else
    newuser = NULL;
  free(server->username);
  server->username = newuser;
  return (0);
}

/*
** When we meet the server.<servername>.realname configuration
** We must change the server's default realname when connecting
*/
static int	server_realname(t_cfg_server *server, char *value)
{
  char		*newreal;

  if (*value)
    {
      newreal = strdup(value);
      if (!newreal)
	{
	  perror("strdup");
	  return (1);
	}
    }
  else
    newreal = NULL;
  free(server->realname);
  server->realname = newreal;
  return (0);
}

/*
** When we meet the server.<servername>.password configuration
** We must change the server's default password when connecting
*/
static int	server_password(t_cfg_server *server, char *value)
{
  char		*newpass;

  if (*value)
    {
      newpass = strdup(value);
      if (!newpass)
	{
	  perror("strdup");
	  return (1);
	}
    }
  else
    newpass = NULL;
  free(server->password);
  server->password = newpass;
  return (0);
}

/*
** When we meet the server.<servername>.port configuration
** We must change the server's default port when connecting
*/
static int	server_port(t_cfg_server *server, char *value)
{
  unsigned short newport;

  if (*value)
    newport = atoi(value);
  else
    newport = 6667;
  server->port = newport;
  return (0);
}

/*
** When we meet the server.<servername>.onlog configuration
** If *value is not '\0', we append contents to the string to send.
** Otherwise we reset it to ""
*/
static int	server_onlog(t_cfg_server *server, char *value)
{
  if (*value)
    {
      if (str_appendcstr(&server->send_onlog, value) ||
	  str_appendcstr(&server->send_onlog, "\r\n"))
	return (1);
    }
  else
    {
      str_delete(&server->send_onlog);
      str_new(&server->send_onlog);
    }
  return (0);
}

/*
** When we meet the key "server"
** The format is as follows
** server.<servername>.<option>=<value>
*/
int		key_server(t_config *config, char *key, char *value,
			   const char *filename, unsigned int lineno)
{
  // Contains, for each key, the appropriate handler
  static const struct
  {
    const char *key;
    int (*handler)(t_cfg_server *, char *);
  } handlers[] =
  {
    { "nick", &server_nick },
    { "host", &server_hostname },
    { "user", &server_username },
    { "real", &server_realname },
    { "pass", &server_password },
    { "port", &server_port },
    { "onlog", &server_onlog },
    { NULL, NULL }
  };

  unsigned int	i;
  t_cfg_server	*server;
  char		*servername;

  // Keep servername and prepare subkey
  servername = key;
  key = strchr(key, '.');
  if (!*key)
    {
      fprintf(stderr, "%s:%u: warning: No subkey in server.\n",
	      filename, lineno);
      return (0);
    }
  *key = '\0';
  ++key;

  // Retreive server structure
  server = mapstring_findcstr(&config->servers, servername);
  if (!server)
    {
      fprintf(stderr, "%s:%u: warning: Unknown server `%s`.\n",
	      filename, lineno, servername);
      return (0);
    }

  // Look through all handlers which one matches
  for (i = 0 ; handlers[i].key ; ++i)
    if (!strcmp(key, handlers[i].key))
      return (handlers[i].handler(server, value));

  // Print an error if we couldn't handle the key
  fprintf(stderr, "%s:%u: warning: Unknown server attribute `%s`.\n",
	  filename, lineno, key);
  return (0);
}
