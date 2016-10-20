#include <stdlib.h>
#include <string.h>

#include "test_common.h"

static int add_user(t_channel* tchan, t_test_user const* user)
{
  t_user* tuser;
  char* prefixdup;

  tuser = malloc(sizeof(t_user));
  if (!tuser)
    return 1;
  prefixdup = strdup(user->prefix);
  if (!prefixdup)
  {
    free(tuser);
    return 1;
  }
  if (new_user(tuser, prefixdup))
  {
    free(tuser);
    free(prefixdup);
  }
  free(prefixdup);
  if (mapstring_insert(&tchan->users, &tuser->nick, tuser))
  {
    delete_user(tuser, true);
    return 1;
  }
  tuser->netmode = user->netmode;
  tuser->chanmode = user->chanmode;
  return 0;
}

static int add_channel(t_ircconnection* co, t_test_channel const* channel)
{
  t_channel* tchan;
  unsigned int i;

  tchan = malloc(sizeof(t_channel));
  if (!tchan)
    return 1;
  new_chan(tchan);
  for (i = 0; channel->users[i].prefix; ++i)
    if (add_user(tchan, &channel->users[i]))
    {
      delete_chan(tchan, true);
      return 1;
    }
  if (str_newfromcstr(&tchan->name, channel->name) ||
      str_newfromcstr(&tchan->topic, channel->topic) ||
      mapstring_insert(&co->chanlist, &tchan->name, tchan))
  {
    delete_chan(tchan, true);
    return 1;
  }
  return 0;
}

int get_fake_connection(t_ircconnection* co, t_fake_connection_data const* data)
{
  unsigned int i;

  irc_co_new(co);
  co->accepted = true;
  for (i = 0; data->channels[i].name; ++i)
    if (add_channel(co, &data->channels[i]))
    {
      irc_co_delete(co);
      return 1;
    }
  if (str_newfromcstr(&co->nick, data->nickname) ||
      str_newfromcstr(&co->user, data->username) ||
      str_newfromcstr(&co->realname, data->realname) ||
      str_newfromcstr(&co->servername, data->host))
  {
    irc_co_delete(co);
    return 1;
  }
  return 0;
}
