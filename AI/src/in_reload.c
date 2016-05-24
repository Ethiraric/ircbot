/*
** in_reload.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Wed May 27 10:30:07 2015 Florian SABOURIN
** Last update Wed May 27 10:30:08 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <stdio.h>
#include <stdlib.h>

int in_reload(t_bot* bot, t_luneth* luneth)
{
  char* name;

  (void)(luneth);
  name = strtok(NULL, " ");
  if (!name || strtok(NULL, " "))
  {
    fprintf(stderr, "/reload <soname>\n");
    return (0);
  }
  bot->so_name = strdup(name);
  return (0);
}
