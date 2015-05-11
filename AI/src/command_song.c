/*
** command_song.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  9 15:39:25 2015 Florian SABOURIN
** Last update Sat May  9 15:39:25 2015 Florian SABOURIN
*/

#include <errno.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include "luneth.h"

/*
** If your regex supports non capturing groups, uncomment this one
** const char * link_regex =
**     "^(?:https?:\\/\\/)?(?:www\\.|m\\.)?youtu\\.?be(?:\\.com)?\\/"
**     "(?:(?:watch\\/?|embed\\/|v\\/|attribution_link\\??))*\\??"
**     "(?:([0-9a-zA-Z_-]{11})|"
**        "(?:(?:v=([0-9a-zA-Z_-]{11})|"
**            "feature=(?:player_embedded|related)|"
**            "list=[0-9a-zA-Z_-]+|"
**            "index=[0-9]+|"
**            "\\#?t=(?:[0-9]+m)?[0-9]+s?)&?)+)$";
*/

// Capturing groups are 7;10
const char *regex_link =
    "^(https\\/\\/)?(www\\.|m\\.)?youtu\\.?be(\\.com)?\\/"
    "((watch\\/?|embed\\/|v\\/|attribution_link\\??""))*\\??"
    "(([0-9a-zA-Z_-]{11})|"
       "((v=([0-9a-zA-Z_-]{11})|"
	   "feature=(player_embedded|related)|"
	   "list=[0-9a-zA-Z_-]+|"
	   "index=[0-9]+|"
	   "\\#?t=([0-9]+m)?[0-9]+s?)&?)+)$";

static char	*code_from_link(const char *link)
{
  regmatch_t	*matches;
  regex_t	reg;
  size_t	nmatch;
  char		*code;
  int		ret;

  code = NULL;
  /* Compile regex */
  ret = regcomp(&reg, regex_link, REG_EXTENDED);
  if (ret)
    return (NULL);

  /* Allocate match tab */
  nmatch = reg.re_nsub;
  matches = malloc(sizeof(regmatch_t) * nmatch);
  if (!matches)
    {
      regfree(&reg);
      return (NULL);
    }

  /* Match regex against the link */
  ret = regexec(&reg, link, nmatch, matches, 0);

  /* Links are at position 7 or 10 */
  regfree(&reg);
  if (!ret)
    {
      if (matches[7].rm_so != -1 && matches[7].rm_eo != -1)
	ret = 7;
      else if (matches[10].rm_so != -1 && matches[10].rm_eo != -1)
	ret = 10;
      if (ret)
	code = strndup(&(link[matches[ret].rm_so]),
	    matches[ret].rm_eo - matches[ret].rm_so);
    }
  free(matches);
  return (code);
}

static bool	is_code(const char *link)
{
  if (strlen(link) != 11)
    return (false);
  while (*link)
    {
      if (!((*link <= 'z' && *link >= 'a') || (*link <= 'Z' && *link >= 'A') ||
	    (*link <= '9' && *link >= '0') || *link == '_' || *link == '-'))
	return (false);
      ++link;
    }
  return (true);
}

static int	song_add(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  t_song	*song;
  t_id		auth;
  char		*link;
  char		*category;
  char		*code;

  (void)(bot);
  link = strtok(NULL, " ");
  category = strtok(NULL, " ");
  if (strtok(NULL, ""))
    return (0);
  auth = database_pplid(luneth->db, co->cmd.prefixnick, co->cmd.args[0]);
  if (!auth)
    return (1);
  code = code_from_link(link);
  if (!code)
    return (irc_msgf(co, co->cmd.args[0], "Failed to get code for %s", link));
  song = database_get_song_fromcode(luneth->db, code);
  if (song)
    {
      song_delete(song, true);
      free(code);
      return (irc_msgf(co, co->cmd.args[0],
	      "This link is already in the database"));
    }
  auth = database_insert_song(luneth->db, code, category, auth);
  if (!auth)
    {
      free(code);
      return (irc_msgf(co, co->cmd.args[0], "Failed to insert in db"));
    }
  irc_msgf(co, co->cmd.args[0], "Added %s in %s as %u", code, category, auth);
  free(code);
  return (0);
}

static int	song_help(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  const char	*msg = "song [help | add <link> [category]]";

  (void)(bot);
  (void)(luneth);
  return (irc_msgf(co, co->cmd.args[0], msg));
}

static int	song_edit(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  char		*code;
  char		*category;

  (void)(bot);
  code = strtok(NULL, " ");
  category = strtok(NULL, " ");
  if (!code || !category || strtok(NULL, " "))
    return (0);
  if (!is_code(code))
    return (irc_msgf(co, co->cmd.args[0], "Invalid code %s", code));
  if (database_edit_category(luneth->db, code, category))
    return (irc_msgf(co, co->cmd.args[0], "Failed to edit %s", code));
  return (irc_msgf(co, co->cmd.args[0], "%s is now %s", code, category));
}

static int	song_whois(t_bot *bot, t_ircconnection *co, t_luneth *luneth)
{
  t_people	*ppl;
  char		*code;
  int		ret;

  (void)(bot);
  code = strtok(NULL, " ");
  if (!code || strtok(NULL, " ") || !is_code(code))
    return (0);
  ppl = database_get_song_auth(luneth->db, code);
  if (!ppl)
    return (irc_msgf(co, co->cmd.args[0], "Unknown author for %s", code));
  ret = irc_msgf(co, co->cmd.args[0], "Author for %s is %s", code, ppl->nick);
  ppl_delete(ppl, true);
  return (ret);
}

int		command_song(t_bot *bot, t_ircconnection *co,
			     t_luneth *luneth)
{
  t_song	*song;
  char		*category;

  (void)(bot);
  category = strtok(NULL, " ");
  if (category)
    {
      if (!strcasecmp(category, "add"))
	return (song_add(bot, co, luneth));
      else if (!strcasecmp(category, "edit"))
	return (song_edit(bot, co, luneth));
      else if (!strcasecmp(category, "whois"))
	return (song_whois(bot, co, luneth));
      else if (!strcasecmp(category, "help"))
	return (song_help(bot, co, luneth));
      // RM
    }
  song = database_select_random_songcateg(luneth->db, category);
  if (song)
    {
      irc_msgf(co, co->cmd.args[0],
	  "%s -> https://www.youtube.com/watch?v=%s [%s] : %s",
	  co->cmd.prefixnick, song->code,
	  song->category ? song->category : "",
	  song->title ? song->title : "");
      song_delete(song, true);
    }
  else if (errno == ENOMEM)
    return (1);
  else if (irc_msgf(co, co->cmd.args[0], "Failed to find a song"))
    return (1);
  return (0);
}
