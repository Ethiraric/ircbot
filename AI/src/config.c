/*
** config.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sun Nov 29 03:17:23 2015 Florian SABOURIN
** Last update Sun Nov 29 03:17:23 2015 Florian SABOURIN
*/

#include "config.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** When we meet the key "newserver"
** Create a new entry in the servers member of config
*/
static int key_newserver(t_config* config,
                         char* key,
                         char* value,
                         const char* filename,
                         unsigned int lineno)
{
  t_cfg_server* cfgserver;

  // Checking line parameters
  if (*key)
  {
    fprintf(
        stderr, "%s:%u: warning: subkey in newserver key.\n", filename, lineno);
    return (0);
  }
  if (!*value)
  {
    fprintf(stderr,
            "%s:%u: warning: No value in newserver key.\n",
            filename,
            lineno);
    return (0);
  }

  // Creating entry and adding it to config
  cfgserver = cfg_server_new(value);
  if (!cfgserver)
  {
    perror("cfg_server_new");
    return (1);
  }
  if (mapstring_insertnewcstr(&config->servers, cfgserver->name, cfgserver))
  {
    cfg_server_delete(cfgserver);
    perror("mapstring_insertnewcstr");
    return (1);
  }
  printf("Adding server %s\n", value);
  return (0);
}

/*
** Loads a key-value pair
** Before calling a subfunction, the key is amputated from anything before a '.'
** If the key has no '.', the key sent is ""
*/
static int process_key_value(t_config* config,
                             char* key,
                             char* value,
                             const char* filename,
                             unsigned int lineno)
{
  // Contains, for each key, the appropriate handler
  static const struct
  {
    const char* key;
    int (*handler)(t_config*, char*, char*, const char*, unsigned int);
  } handlers[] = {
      {"newserver", &key_newserver}, {"server", &key_server}, {NULL, NULL}};

  unsigned int i;
  char* firstkey;

  // Separate first key from subkey (left and right parts from the first '.')
  firstkey = key;
  key = strchrnul(key, '.');
  if (*key)
  {
    *key = '\0';
    ++key;
  }

  // Look through all handlers which one matches
  for (i = 0; handlers[i].key; ++i)
    if (!strcmp(firstkey, handlers[i].key))
      return (handlers[i].handler(config, key, value, filename, lineno));

  // Print an error if we couldn't handle the key
  fprintf(stderr,
          "%s:%u: warning: Unknown key `%s`.\n",
          filename,
          lineno,
          firstkey);
  return (0);
}

/*
** Processes a line from the configuration file
*/
static int process_line(t_config* config,
                        char* line,
                        const char* filename,
                        unsigned int lineno)
{
  char* key;
  char* value;

  value = strchr(line, '=');
  if (!value)
  {
    fprintf(stderr, "%s:%u: warning: no '=' token.\n", filename, lineno);
    return (0);
  }
  *value = '\0';
  ++value;
  key = line;
  return (process_key_value(config, key, value, filename, lineno));
}

/*
** Initializes the configuration structure
*/
void config_init(t_config* config)
{
  mapstring_new(&config->servers);
}

/*
** Cleans information contained in the configuration
*/
void config_clean(t_config* config)
{
  unsigned int i;

  for (i = 0; i < config->servers.len; ++i)
    cfg_server_delete((t_cfg_server*)(config->servers.tab[i].value));
  mapstring_delete(&config->servers);
}

/*
** Loads configuration from a file
*/
int load_config(t_config* config, const char* file)
{
  unsigned int lineno;
  FILE* ifs;
  char* line;
  char* eol;
  size_t linesize;

  // Open file and initialize variables
  ifs = fopen(file, "r");
  if (!ifs)
  {
    perror("fopen");
    return (1);
  }
  line = NULL;
  lineno = 0;
  errno = 0;

  // Read and process line by line
  while (getline(&line, &linesize, ifs) != -1)
  {
    // Remove '\n' from the line
    eol = strchr(line, '\n');
    if (eol)
      *eol = '\0';
    if (*line && process_line(config, line, file, ++lineno))
    {
      // Exit in case of error, don't forget to cleanup
      free(line);
      fclose(ifs);
      return (1);
    }
  }

  // Cleanup
  free(line);
  fclose(ifs);

  // Ensure getline succeeded
  if (errno)
  {
    perror("getline");
    return (1);
  }
  return (0);
}
