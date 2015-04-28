/*
** AI.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Apr 27 21:01:12 2015 Florian SABOURIN
** Last update Mon Apr 27 21:01:13 2015 Florian SABOURIN
*/

#include <dlfcn.h>
#include <stdio.h>
#include "ircbot.h"

/* Default functions, simulate an empty AI */
int	handler_fct_none(t_bot *bot, t_ircconnection *co, void *dat)
{
  /* Supress warnings */
  (void)(bot);
  (void)(co);
  (void)(dat);
  /* Everything is fine */
  return (0);
}

int	handler_input_fct_none(t_bot *bot, char *input, void *dat)
{
  // TODO: Add sample commands, "load", "quit"...
  /* Supress warnings */
  (void)(bot);
  (void)(input);
  (void)(dat);
  /* Everything is fine */
  return (0);
}

void		unloadAI(t_bot *bot)
{
  void		(*deleter)(void *data);

  if (bot->dlhandle)
    {
      printf("uHandle: %p\n", bot->dlhandle);
      deleter = dlsym(bot->dlhandle, SYM_DEL);
      if (!deleter)
	fprintf(stderr, "dlsym: %s\n", dlerror());
      else
	deleter(bot->handler_data);
      if (dlclose(bot->dlhandle))
	fprintf(stderr, "dlclose: %s\n", dlerror());
      bot->dlhandle = NULL;
      bot->handler_data = NULL;
      bot->handler_fct = &handler_fct_none;
      bot->handler_input_fct = &handler_input_fct_none;
    }
}

int		loadAI(t_bot *bot, char *filename)
{
  void		*(*handler_data_getter)();
  void		*dlhandle;
  void		*data;
  int		(*handler_fct)(t_bot *, t_ircconnection *, void *);
  int		(*handler_input_fct)(t_bot *, char *, void *);

  /* Try to load a brand new AI */
  dlhandle = dlopen(filename, RTLD_NOW);
  if (!dlhandle)
    {
      fprintf(stderr, "dlopen: %s\n", dlerror());
      return (1);
    }

  /* Return 1 if we can't load a symbol or datas */
  if (!(handler_fct = dlsym(dlhandle, SYM_IRC)) ||
      !(handler_input_fct = dlsym(dlhandle, SYM_STDIN)) ||
      !(handler_data_getter = dlsym(dlhandle, SYM_GET)))
    {
      fprintf(stderr, "dlsym: %s\n", dlerror());
      if (dlclose(dlhandle))
	fprintf(stderr, "dlclose: %s\n", dlerror());
      return (1);
    }
  if (!(data = handler_data_getter()))
    {
      if (dlclose(dlhandle))
	fprintf(stderr, "dlclose: %s\n", dlerror());
      return (1);
    }

  /* Everything is fine, change the AI */
  unloadAI(bot);
  bot->handler_data = data;
  bot->dlhandle = dlhandle;
  bot->handler_fct = handler_fct;
  bot->handler_input_fct = handler_input_fct;
  printf("Handle: %p\n", bot->dlhandle);
  return (0);
}
