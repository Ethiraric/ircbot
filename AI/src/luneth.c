/*
** luneth.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Apr 28 09:25:14 2015 Florian SABOURIN
** Last update Tue Apr 28 09:25:14 2015 Florian SABOURIN
*/

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include "luneth.h"

void		*irc_data_get(int argc, char **argv)
{
  t_luneth	*ret;
  int		i;

  // Allocate and initialize structure
  ret = malloc(sizeof(t_luneth));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_luneth));

  // Load configuration
  config_init(&ret->config);
  for (i = 2 ; i < argc ; ++i)
    if (load_config(&ret->config, argv[i]))
      {
	config_clean(&ret->config);
	free(ret);
	return (NULL);
      }

  // Open database
  ret->db = database_new("db");
  if (!ret->db)
    {
      config_clean(&ret->config);
      free(ret);
      return (NULL);
    }

  // Load commands
  ret->cmds = database_load_all_cmds(ret->db);
  if (!ret->cmds)
    {
      config_clean(&ret->config);
      free(ret);
      database_delete(ret->db);
      return (NULL);
    }
  ret->speaks = true;
  return (ret);
}

int		irc_on_mess(t_bot *bot, t_ircconnection *co, void *luneth)
{
  printf("[%s] %s\n", str_str(&co->servername), irc_get_command(co));
  return (handle_message(bot, co, luneth));
}

int		irc_stdin(t_bot *bot, char *input, void *luneth)
{
  printf("[stdin] %s\n", input);
  return (handle_input(bot, input, luneth));
}

static int callback_mapstring_delete_cmd(const t_string *key, void *value)
{
  (void)(key);
  cmd_delete((t_cmd *)(value), true);
  return (0);
}

void		irc_data_delete(void *pluneth)
{
  t_luneth	*luneth;

  luneth = pluneth;
  if (luneth->pk.on)
    pkq_terminate(luneth);
  config_clean(&luneth->config);
  curl_global_cleanup();
  database_delete(luneth->db);
  if (luneth->cmds)
    {
      mapstring_foreach(luneth->cmds, &callback_mapstring_delete_cmd);
      mapstring_delete(luneth->cmds);
    }
  free(luneth);
}

int		irc_nothing(t_bot *bot, void *pluneth)
{
  (void)(bot);
  return (pkq_check_hint(pluneth));
}
