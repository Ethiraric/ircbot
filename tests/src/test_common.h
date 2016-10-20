#ifndef TEST_COMMON
#define TEST_COMMON

#include "irc.h"

typedef struct
{
  char const* prefix;
  t_mode chanmode;
  t_mode netmode;
} t_test_user;

typedef struct
{
  t_test_user const* users;
  char const* topic;
  char const* name;
  t_mode mode;
} t_test_channel;

typedef struct
{
  char const* nickname;
  char const* username;
  char const* realname;
  char const* host;
  t_test_channel const* channels;
} t_fake_connection_data;

int get_fake_connection(t_ircconnection* co,
                        t_fake_connection_data const* data);

#endif /* !TEST_COMMON */
