#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

#include "luneth.h"

void* irc_data_get(int argc, char** argv)
{
  t_luneth* ret;
  int i;

  // Allocate and initialize structure
  ret = malloc(sizeof(t_luneth));
  if (!ret)
    return (NULL);
  memset(ret, 0, sizeof(t_luneth));
  span_init(&ret->songs, sizeof(t_song));

  // Load configuration
  config_init(&ret->config);
  for (i = 2; i < argc; ++i)
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

  // Load commands and songs
  ret->cmds = database_load_all_cmds(ret->db);
  if (!ret->cmds || database_load_all_songs(&ret->songs, ret->db))
  {
    irc_data_delete(ret);
    return (NULL);
  }
  ret->speaks = true;
  return (ret);
}

int irc_on_mess(t_bot* bot, t_ircconnection* co, void* luneth)
{
  printf("[%s] %s\n", str_str(&co->servername), irc_get_command(co));
  return (handle_message(bot, co, luneth));
}

int irc_stdin(t_bot* bot, char* input, void* luneth)
{
  printf("[stdin] %s\n", input);
  return (handle_input(bot, input, luneth));
}

static int callback_mapstring_delete_cmd(const t_string* key, void* value)
{
  (void)(key);
  cmd_delete((t_cmd*)(value), true);
  return (0);
}

void irc_data_delete(void* pluneth)
{
  t_luneth* luneth;

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
    free(luneth->cmds);
  }

  unsigned int const nsongs = span_size(&luneth->songs);
  for (unsigned int i = 0; i < nsongs; ++i)
    song_delete(span_at(&luneth->songs, i), false);
  span_destruct(&luneth->songs);

  free(luneth);
}

int irc_nothing(t_bot* bot, void* pluneth)
{
  (void)(bot);
  (void)(pluneth);
  return 0;
}
