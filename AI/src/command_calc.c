/*
** command_calc.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Sep  3 17:46:23 2015 Florian SABOURIN
** Last update Thu Sep  3 17:46:23 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include "luneth.h"

static char	*escape_doublequotes(const char *in)
{
  size_t	len;
  const char	*curr;
  char		*ret;
  char		*it;
  char		*res;

  len = 0;
  curr = in;
  /* Count chars to escape, one char will be added for each one of them */
  while (*(curr = strchrnul(curr, '"')))
    {
      ++len;
      ++curr;
    }
  /* Add size of the string (including '\0') */
  len += curr - in + 1;
  ret = malloc(len);
  if (!ret)
    return (NULL);
  it = ret;
  curr = in;
  while (*(res = strchrnul(curr, '"')))
    {
      /* Copy chars until a quote is met, then escape */
      it = stpncpy(it, curr, res - curr);
      it = stpcpy(it, "\"\"");
      curr = res + 1;
    }
  /* Copy the rest of the string */
  strcpy(it, curr);
  return (ret);
}

#define CALC_BUFSIZ	512
int		command_calc(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  static char	result[CALC_BUFSIZ];
  size_t	sizeread;
  FILE		*stream;
  char		*str;
  char		*execstr;
  char		*escapedstr;

  (void)(luneth);
  (void)(bot);
  /* Get and escape command */
  str = strtok(NULL, "");
  escapedstr = escape_doublequotes(str);
  if (!escapedstr)
    return (1);
  if (asprintf(&execstr, "echo \"e=2.71828182846;"
	       "pi=3.14159265359;"
	       "%s\" | bc", escapedstr) == -1)
    return (1);
  printf("command: %s -> %s\n", str, escapedstr);
  printf("res: %s\n", execstr);
  free(escapedstr);
  /* Open pipe and read result */
  stream = popen(execstr, "r");
  free(execstr);
  if (!stream)
    {
      perror("popen");
      return (1);
    }
  sizeread = fread(result, 1, CALC_BUFSIZ, stream);
  printf("Read %zu chars\n", sizeread);
  if (pclose(stream) == -1)
    return (1);
  if (!sizeread)
    return (luneth_respond_msg(co, luneth, "No result to display"));
  result[sizeread] = '\0';
  // Replace '\n' by spaces
  str = result;
  while ((str = strchr(str, '\n')))
    *str = ' ';
  return (luneth_respond_msg(co, luneth, result));
}
