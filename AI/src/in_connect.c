/*
** in_connect.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 12:26:18 2015 Florian SABOURIN
** Last update Tue Apr 28 12:26:19 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <stdio.h>
#include "luneth.h"

static int	connect_cfg_server(t_bot *bot, t_luneth *luneth,
				   const char *servername)
{
  t_cfg_server	*server;

  server = mapstring_findcstr(&luneth->config.servers, servername);
  if (!server)
    {
      fprintf(stderr, "Unknown server `%s`\n", servername);
      return (1);
    }
  if (bot_connect(bot, server->hostname, server->port, server->nick,
		  server->username, server->realname, server->password))
    {
      fprintf(stderr, "Failed to connect to `%s`\n", servername);
      return (1);
    }
  if (str_size(&server->send_onlog))
    if (irc_send_raw((t_ircconnection *)bot->conns.tab[bot->conns.len - 1],
		     str_str(&server->send_onlog),
		     str_size(&server->send_onlog)))
      return (1);
  return (0);
}

int		in_connect(t_bot *bot, t_luneth *luneth)
{
  char		*hostname, *sport, *nick, *user, *realname, *pass;

  hostname = strtok(NULL, " ");
  sport = strtok(NULL, " ");
  if (hostname && !sport)
    return (connect_cfg_server(bot, luneth, hostname));
  if (!hostname || !sport || !(nick = strtok(NULL, " ")) ||
      !(user = strtok(NULL, " ")) || !(realname = strtok(NULL, " ")))
    {
      fprintf(stderr, "/connect <host> <port> <nick> <user> <realname> "
		      "[<pass>]\n");
      fprintf(stderr, "/connect <servername>\n");
      return (0);
    }
  pass = strtok(NULL, " ");
  if (bot_connect(bot, hostname, atoi(sport), nick, user, realname, pass))
    fprintf(stderr, "Failed to connect to %s\n", hostname);
  return (0);
}
