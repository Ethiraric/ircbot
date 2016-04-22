/*
** mess_join.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Apr 30 03:07:43 2015 Florian SABOURIN
** Last update Thu Apr 30 03:07:44 2015 Florian SABOURIN
*/

#include "luneth.h"

static int	say_say(t_ircconnection *co, t_luneth *luneth, t_say *say)
{
  t_people	*ppl;
  int		ret;

  ppl = database_ppl_fromid(luneth->db, say->auth);
  if (!ppl)
    return (0);
  ret = luneth_respond_msgf(co, luneth, "[#%u %s -> %s] %s", say->id, ppl->nick,
      co->cmd.prefixnick, say->text);
  ppl_delete(ppl, true);
  say_delete(say, true);
  return (ret);
}

static int	handle_says(t_ircconnection *co, t_luneth *luneth)
{
  unsigned int	i;
  t_vector	*says;
  t_say		*say;
  t_id		pplid;
  int		ret;

  pplid = database_pplid(luneth->db, co->cmd.prefixnick,
			 str_str(&co->servername), co->cmd.args[0]);
  if (!pplid)
    return (0);
  says = database_get_say(luneth->db, pplid);
  if (!says)
    return (0);
  i = 0;
  ret = 0;
  while (i < vector_size(says))
    {
      say = vector_at(says, i);
      if (!ret)
	ret = say_say(co, luneth, say);
      else
	say_delete(say, true);
      ++i;
    }
  vector_delete(says, true);
  return (ret);
}

int		mess_join(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  (void)(bot);
  if (co->cmd.argc == 0 || !co->cmd.prefix)
    return (0);
  return (handle_says(co, luneth));
}
