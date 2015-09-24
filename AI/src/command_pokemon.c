/*
** command_pokemon.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue May 12 13:48:11 2015 Florian SABOURIN
** Last update Tue May 12 13:48:11 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include "luneth.h"

void		pkq_terminate(t_luneth *luneth)
{
  free(luneth->pk.question);
  luneth->pk.question = 0;
  free(luneth->pk.ans);
  luneth->pk.ans = 0;
  free(luneth->pk.ans2);
  luneth->pk.ans2 = 0;
  free(luneth->pk.hint);
  luneth->pk.hint = 0;
  free(luneth->pk.chan);
  luneth->pk.chan = 0;
  luneth->pk.on = false;
}

int		pkq_show_question(t_luneth *luneth)
{
  return (irc_msg(luneth->pk.co, luneth->pk.chan, luneth->pk.question));
}

int		pkq_show_hint(t_luneth *luneth)
{
  return (irc_msgf(luneth->pk.co, luneth->pk.chan, "Pokemon hint : %s",
		   luneth->pk.hint));
}

static int	pkq_reveal_hint(t_luneth *luneth)
{
  unsigned int	pos;
  size_t	len;
  char		*hint;

  hint = luneth->pk.hint;
  if (!strchr(hint, '*'))
    return (1);
  len = strlen(hint);
  pos = rand() % len;
  while (hint[pos] != '*')
    if (++pos == len)
      pos = 0;
  hint[pos] = luneth->pk.ans[pos];
  return (pkq_show_hint(luneth));
}

int		pkq_check_hint(t_luneth *luneth)
{
  time_t	now;
  int		ret;

  if (!luneth->pk.on)
    return (0);
  now = time(NULL);
  if (now >= luneth->pk.next_hint)
    {
      if (pkq_reveal_hint(luneth))
	{
	  ret = irc_msgf(luneth->pk.co, luneth->pk.chan,
			 "Terminating pokemon quizz due to inactivity");
	  pkq_terminate(luneth);
	  return (ret);
	}
      luneth->pk.next_hint = now + HINT_DELAY;
    }
  return (0);
}

static int (*const quizz_fct[])(t_luneth *luneth) =
{
  &pkq_pfrname, &pkq_penname, &pkq_ptype,
  &pkq_afrname, &pkq_aenname, &pkq_atype,
  &pkq_frnum
};

static int	pkq_get_question(t_luneth *luneth)
{
  unsigned int	num;

  num = rand() % sizeof(quizz_fct) / sizeof(quizz_fct[0]);
  if (quizz_fct[num](luneth))
    return (1);
  luneth->pk.hint = strdup(luneth->pk.ans);
  if (luneth->pk.hint)
    {
      memset(luneth->pk.hint, '*', strlen(luneth->pk.ans));
      luneth->pk.next_hint = time(NULL) + HINT_DELAY;
      return (0);
    }
  pkq_terminate(luneth);
  return (1);
}

static int	pkq_init(t_luneth *luneth, t_ircconnection *co)
{
  luneth->pk.chan = strdup(co->cmd.args[0]);
  if (!luneth->pk.chan)
    return (1);
  if (pkq_get_question(luneth))
    {
      free(luneth->pk.chan);
      return (1);
    }
  luneth->pk.co = co;
  luneth->pk.on = true;
  return (0);
}

int		pkq_check_ans(t_luneth *luneth, t_ircconnection *co)
{
  if (!luneth->pk.on ||
      co != luneth->pk.co || strcmp(co->cmd.args[0], luneth->pk.chan))
    return (0);
  if (!strcasecmp(luneth->pk.ans, co->cmd.args[co->cmd.argc - 1]) ||
      (luneth->pk.ans2 &&
       !strcasecmp(luneth->pk.ans2, co->cmd.args[co->cmd.argc - 1])))
    {
      if (irc_msgf(co, co->cmd.args[0], "WP %s ! %s -> %s",
		   co->cmd.prefixnick, luneth->pk.question, luneth->pk.ans))
	return (1);
      free(luneth->pk.ans);
      free(luneth->pk.ans2);
      luneth->pk.ans2 = NULL;
      free(luneth->pk.hint);
      free(luneth->pk.question);
      if (pkq_get_question(luneth) || pkq_show_question(luneth))
	return (1);
      if (database_add_score(luneth->db, co->cmd.prefixnick, co->cmd.args[0],
			     co->servername.m->str, 1))
	return (1);
    }
  return (0);
}

/*
** Commands
*/

static int	pokemon_on(t_ircconnection *co, t_luneth *luneth)
{
  if (luneth->pk.on)
    return (irc_msg(co, co->cmd.args[0], "Pokemon quizz is already on"));
  if (pkq_init(luneth, co))
    return (irc_msg(co, co->cmd.args[0], "Failed to init pokemon quizz"));
  return (pkq_show_question(luneth));
}

static int	pokemon_off(t_ircconnection *co, t_luneth *luneth)
{
  if (!luneth->pk.on)
    return (irc_msg(co, co->cmd.args[0], "Pokemon quizz is already off"));
  if (co != luneth->pk.co || strcmp(co->cmd.args[0], luneth->pk.chan))
    return (irc_msg(co, co->cmd.args[0], "Pokemon quizz not on your chan"));
  pkq_terminate(luneth);
  return (irc_msg(co, co->cmd.args[0], "Pokemon quizz stopped"));
}

static int	pokemon_help(t_ircconnection *co)
{
  static const char	*msg =
      "pokemon ( on | off )";

  return (irc_msg(co, co->cmd.args[0], msg));
}

int		command_pokemon(t_bot *bot, t_ircconnection *co,
				t_luneth *luneth)
{
  char		*command;

  (void)(bot);
  command = strtok(NULL, " ");
  if (!command || strtok(NULL, " "))
    return (0);
  if (!strcasecmp(command, "on") || !strcasecmp(command, "go"))
    return (pokemon_on(co, luneth));
  if (!strcasecmp(command, "off") || !strcasecmp(command, "tg"))
    return (pokemon_off(co, luneth));
  if (!strcasecmp(command, "help"))
    return (pokemon_help(co));
  return (0);
}
