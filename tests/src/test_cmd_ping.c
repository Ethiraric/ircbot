#include <stdio.h>
#include <string.h>

#include "irc.h"
#include "luneth.h"
#include "myassert.h"
#include "test_common.h"

typedef struct
{
  t_fake_connection_data const* codata;
  char const* testname;
  char const* command;
  char const* expected;
} test_contents;

// Users in chan #channel
static t_test_user const chusers_channel[] =
{
   { "nick!user@host", 0, 0 }, {NULL, 0, 0}
};

// Channels are the same for all tests here.
static t_test_channel const channels[] = {
    {chusers_channel, "This is a topic", "#channel", 0}, {NULL, NULL, NULL, 0},
};

static t_fake_connection_data const fake_co_data = {
    "Llyud", "username", "realname", "irc.example.org", channels,
};

static test_contents const tests_set[] = {
    {&fake_co_data,
     "Ping in channel",
     ":nick!user@host PRIVMSG #channel :ping",
     "PRIVMSG #channel :nick\r\n"},
    {&fake_co_data,
     "Ping by PM",
     ":nick!user@host PRIVMSG Llyud :ping",
     "PRIVMSG nick :nick\r\n"},
    {&fake_co_data,
     "Ping in channel with arg",
     ":xXxnick33xXx!user@host PRIVMSG #channel :ping "
     "with message",
     "PRIVMSG #channel :xXxnick33xXx with "
     "message\r\n"},
    {&fake_co_data,
     "Ping by PM with arg",
     ":thisisme!user@host PRIVMSG Llyud :ping plop",
     "PRIVMSG thisisme :thisisme plop\r\n"},
};

static int do_test(test_contents const* contents)
{
  t_ircconnection co;
  int err = 0;
  t_luneth luneth;

  printf("Running test '%s'.\n", contents->testname);
  luneth.speaks = true;
  if (get_fake_connection(&co, contents->codata))
  {
    fprintf(stderr, "Error: Failed to setup fake connection.\n");
    return 1;
  }
  if (!(co.command = strdup(contents->command)) || irc_eval_cmd(&co))
  {
    fprintf(stderr, "Error: Failed to setup test environment.\n");
    irc_co_delete(&co);
    return 1;
  }
  if (assert_init_test() == 0)
  {
    char const* command = strtok(co.cmd.args[co.cmd.argc - 1], " ");
    assert(!strcmp(command, "ping"));
    assert(!command_ping(NULL, &co, &luneth));
    char const* wbuffer = buffer_data((t_buffer*)irc_get_wbuffer(&co));
    assert(!strcmp(wbuffer, contents->expected));
  }
  else
    err = 1;
  irc_co_delete(&co);
  return err;
}

int test_cmd_ping()
{
  size_t const nbtests = sizeof(tests_set) / sizeof(*tests_set);
  size_t passes = 0;
  size_t i;

  for (i = 0; i < nbtests; ++i)
    if (!do_test(&tests_set[i]))
      ++passes;
  printf("%zu/%zu tests passed.\n", passes, nbtests);
  return passes == nbtests;
}
