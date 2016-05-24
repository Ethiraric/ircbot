/*
** config.h for  in /home/sabour_f/rendu/ircbot/AI/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Dec 03 21:57:21 2015 Florian SABOURIN
** Last update Thu Dec 03 21:57:21 2015 Florian SABOURIN
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#include "t_mapstring.h"

/*
** Shortcut for a remote server
** This specifies default parameters
** Imagine you want to connect to irc.freenode.com
** You may set up a shortcut, with your default nickname, username, realname,
** password, and maybe some commands you want to send each time you connect
** under "freenode". That way, when you type "/connect freenode", the bot does
** all the work for you
*/
typedef struct s_cfg_server
{
  char* name;          // Name of the shortcut
  t_string send_onlog; // Datas to send when logging on the remote server
  char* hostname;      // Hostname of the server
  char* nick;          // Nickname to use on the server
  unsigned short port; // Port to use when connecting
  char* username;      // Username to use when connecting
  char* realname;      // Realname to use when connecting
  char* password;      // Password to use when connecting
} t_cfg_server;

t_cfg_server* cfg_server_new(const char* name);
void cfg_server_delete(t_cfg_server* server);

/*
** Bot configuration
** See above structures for more informations
*/
typedef struct s_config
{
  t_mapstring servers; // Map of s_cfg_server
} t_config;

void config_init(t_config* config);
void config_clean(t_config* config);
int load_config(t_config* config, const char* file);

// Configuration subroutines
int key_server(t_config* config,
               char* key,
               char* value,
               const char* filename,
               unsigned int lineno);

#endif /* !CONFIG_H_ */
