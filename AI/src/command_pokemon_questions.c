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
