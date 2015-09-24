/*
** command_pokemon_questions.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue May 12 21:41:20 2015 Florian SABOURIN
** Last update Tue May 12 21:41:20 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <stdio.h>
#include "luneth.h"

static const char	*pkq_str_fromtype(e_type type)
{
  static const char *ret[] =
  {
    "None",
    "Normal",
    "Fighting",
    "Flying",
    "Poison",
    "Ground",
    "Rock",
    "Bug",
    "Ghost",
    "Steel",
    "Fire",
    "Water",
    "Grass",
    "Electric",
    "Psychic",
    "Ice",
    "Dragon",
    "Dark",
    "???"
  };

  return (ret[type]);
}

int		pkq_pfrname(t_luneth *luneth)
{
  unsigned int	num;
  int		ret;

  num = rand() % (pk_entries) + 1;
  ret = asprintf(&luneth->pk.question, "What is the french name of %s ?",
		 pokemons_db[num].name);
  if (ret == -1)
    return (1);
  ret = asprintf(&luneth->pk.ans, "%s", pokemons_db[num].nom);
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_penname(t_luneth *luneth)
{
  unsigned int	num;
  int		ret;

  num = rand() % (pk_entries) + 1;
  ret = asprintf(&luneth->pk.question, "What is the english name of %s ?",
		 pokemons_db[num].nom);
  if (ret == -1)
    return (1);
  ret = asprintf(&luneth->pk.ans, "%s", pokemons_db[num].name);
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_ptype(t_luneth *luneth)
{
  const t_poke	*poke;
  unsigned int	num;
  int		ret;

  num = rand() % (pk_entries) + 1;
  poke = &pokemons_db[num];
  ret = asprintf(&luneth->pk.question, "What is/are the type(s) of %s ?",
		 poke->name);
  if (poke->type2)
    {
      ret = asprintf(&luneth->pk.ans, "%s %s", pkq_str_fromtype(poke->type1),
		     pkq_str_fromtype(poke->type2));
      if (ret == -1)
	{
	  free(luneth->pk.question);
	  return (1);
	}
      ret = asprintf(&luneth->pk.ans2, "%s %s", pkq_str_fromtype(poke->type2),
		     pkq_str_fromtype(poke->type1));
      if (ret == -1)
	free(luneth->pk.ans);
    }
  else
    ret = asprintf(&luneth->pk.ans, "%s", pkq_str_fromtype(poke->type1));
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_afrname(t_luneth *luneth)
{
  unsigned int	num;
  int		ret;

  num = rand() % (ab_entries) + 1;
  ret = asprintf(&luneth->pk.question, "What is the french name of %s ?",
		 abilities_db[num].name);
  if (ret == -1)
    return (1);
  ret = asprintf(&luneth->pk.ans, "%s", abilities_db[num].nom);
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_aenname(t_luneth *luneth)
{
  unsigned int	num;
  int		ret;

  num = rand() % (ab_entries) + 1;
  ret = asprintf(&luneth->pk.question, "What is the english name of %s ?",
		 abilities_db[num].nom);
  if (ret == -1)
    return (1);
  ret = asprintf(&luneth->pk.ans, "%s", abilities_db[num].name);
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_atype(t_luneth *luneth)
{
  unsigned int	num;
  int		ret;

  num = rand() % (ab_entries) + 1;
  ret = asprintf(&luneth->pk.question, "What is the type of %s ?",
		 abilities_db[num].name);
  if (ret == -1)
    return (1);
  ret = asprintf(&luneth->pk.ans, "%s",
		 pkq_str_fromtype(abilities_db[num].type));
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}

int		pkq_frnum(t_luneth *luneth)
{
  const t_poke	*poke;
  unsigned int	num;
  int		ret;

  num = rand() % (pk_entries) + 1;
  poke = &pokemons_db[num];
  ret = asprintf(&luneth->pk.question, "What is the french name of the pokemon"
				       " #%d ?",
		 num);
  ret = asprintf(&luneth->pk.ans, "%s", poke->nom);
  if (ret == -1)
    {
      free(luneth->pk.question);
      return (1);
    }
  return (0);
}
