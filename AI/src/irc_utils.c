#include "luneth.h"
#include <stdio.h>
#include <stdlib.h>

static const char* get_response_channel(t_ircconnection* co)
{
  const char* ret;

  // Was a PM, respond to the sender
  if (!strcmp(str_str(&co->nick), co->cmd.args[0]))
    ret = co->cmd.prefixnick;
  else
    ret = co->cmd.args[0];
  return (ret);
}

int luneth_msg(t_ircconnection* co,
               t_luneth* luneth,
               const char* dst,
               const char* msg)
{
  if (luneth->speaks)
    return (irc_msg(co, dst, msg));
  return (0);
}

int luneth_msgf(t_ircconnection* co,
                t_luneth* luneth,
                const char* dst,
                const char* fmt,
                ...)
{
  va_list va;
  char* msg;
  int ret;

  va_start(va, fmt);
  ret = vasprintf(&msg, fmt, va);
  va_end(va);
  if (ret == -1)
    return (1);
  ret = luneth_msg(co, luneth, dst, msg);
  free(msg);
  return (ret);
}

int luneth_respond_msg(t_ircconnection* co, t_luneth* luneth, const char* msg)
{
  return (luneth_msg(co, luneth, get_response_channel(co), msg));
}

int luneth_respond_msgf(t_ircconnection* co,
                        t_luneth* luneth,
                        const char* fmt,
                        ...)
{
  va_list va;
  char* msg;
  int ret;

  va_start(va, fmt);
  ret = vasprintf(&msg, fmt, va);
  va_end(va);
  if (ret == -1)
    return (1);
  ret = luneth_respond_msg(co, luneth, msg);
  free(msg);
  return (ret);
}
