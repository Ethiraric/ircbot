/*
** command_song.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Sat May  9 15:39:25 2015 Florian SABOURIN
** Last update Sat May  9 15:39:25 2015 Florian SABOURIN
*/

#include "luneth.h"
#include <errno.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

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
const char* regex_link =
    "^(https?:\\/\\/)?(www\\.|m\\.)?youtu\\.?be(\\.com)?\\/"
    "((watch\\/?|embed\\/|v\\/|attribution_link\\??"
    "))*\\??"
    "(([0-9a-zA-Z_-]{11})|"
    "((v=([0-9a-zA-Z_-]{11})|"
    "feature=(player_embedded|related)|"
    "list=[0-9a-zA-Z_-]+|"
    "index=[0-9]+|"
    "\\#?t=([0-9]+m)?[0-9]+s?)&?)+)$";

static char* code_from_link(const char* link)
{
  regmatch_t* matches;
  regex_t reg;
  size_t nmatch;
  char* code;
  int ret;

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

static bool is_code(const char* link)
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

static t_song* find_song_from_code(t_span* songs, char const* code)
{
  size_t const size = span_size(songs);
  t_song* song;

  song = span_begin(songs);
  for (unsigned int i = 0; i < size; ++i, ++song)
  {
    if (!strcmp(song->code, code))
      return (song);
  }
  return (NULL);
}

static char* cat_codes(t_vector* songs)
{
  size_t len;
  size_t i;
  char* mess;
  char* end;

  len = 0;
  i = 0;
  while (i < vector_size(songs))
  {
    len += strlen(((t_song*)vector_at(songs, i))->code);
    ++i;
  }
  len += i + 16;
  mess = malloc(len);
  if (mess)
  {
    end = stpcpy(mess, "Codes: ");
    i = 0;
    while (i < vector_size(songs))
    {
      end = stpcpy(end, ((t_song*)vector_at(songs, i))->code);
      *end = ' ';
      ++end;
      *end = 0;
      ++i;
    }
  }
  return (mess);
}

static int song_add(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_song song;
  t_id auth;
  t_id songid;
  char* link;
  char* category;
  char* code;
  char* title;

  (void)(bot);
  link = strtok(NULL, " ");
  category = strtok(NULL, " ");
  if (strtok(NULL, ""))
    return (0);
  auth = database_pplid(luneth->db,
                        co->cmd.prefixnick,
                        str_str(&co->servername),
                        co->cmd.args[0]);
  if (!auth)
    return (1);
  code = code_from_link(link);
  if (!code)
    return (luneth_respond_msgf(co, luneth, "Failed to get code for %s", link));
  if (find_song_from_code(&luneth->songs, code))
  {
    free(code);
    return (
        luneth_respond_msg(co, luneth, "This link is already in the database"));
  }
  songid = database_insert_song(luneth->db, code, category, auth);
  if (!songid)
  {
    free(code);
    return (luneth_respond_msg(co, luneth, "Failed to insert in db"));
  }
  title = youtube_title(code);
  if (!title)
    luneth_respond_msgf(
        co, luneth, "Added %s in %s as %u", code, category, songid);
  else if (title)
  {
    database_edit_title(luneth->db, code, title);
    luneth_respond_msgf(
        co, luneth, "Added %s in %s as %u : %s", code, category, songid, title);
  }
  if (!song_from_datas(&song, songid, auth, title, code, category))
  {
    if (span_push_back(&luneth->songs, &song))
    {
      song_delete(&song, false);
      return (1);
    }
  }
  else
  {
    free(code);
    free(title);
    return (1);
  }
  return (0);
}

static int song_help(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  static const char* msg =
      "song [ help | add <link> [category] | edit <code> <category> | "
      "title <code> | whois <code> | categories ]";

  (void)(bot);
  (void)(luneth);
  return (luneth_respond_msg(co, luneth, msg));
}

static int song_edit(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_song* song;
  char* code;
  char* category;

  (void)(bot);
  code = strtok(NULL, " ");
  category = strtok(NULL, " ");
  if (!code || !category || strtok(NULL, " "))
    return (0);
  if (!is_code(code))
    return (luneth_respond_msgf(co, luneth, "Invalid code %s", code));
  song = find_song_from_code(&luneth->songs, code);
  if (!song)
    return (luneth_respond_msgf(co, luneth, "Unable to find song %s", code));
  if (database_edit_category(luneth->db, code, category))
    return (luneth_respond_msgf(co, luneth, "Failed to edit %s", code));
  if (song_edit_category(song, category))
    return (1);
  return (luneth_respond_msgf(co, luneth, "%s is now %s", code, category));
}

static int song_whois(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_people* ppl;
  t_song* song;
  char* code;
  int ret;

  (void)(bot);
  code = strtok(NULL, " ");
  if (!code || strtok(NULL, " ") || !is_code(code))
    return (0);
  song = find_song_from_code(&luneth->songs, code);
  if (!song)
    return (luneth_respond_msgf(co, luneth, "Unknown song: %s", code));
  ppl = database_ppl_fromid(luneth->db, song->authid);
  if (!ppl)
    return (luneth_respond_msgf(co, luneth, "Unknown author for %s", code));
  ret = luneth_respond_msgf(co, luneth, "Author for %s is %s", code, ppl->nick);
  ppl_delete(ppl, true);
  return (ret);
}

static int song_title(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_song* song;
  char* code;
  char* title;
  int ret;

  (void)(bot);
  code = strtok(NULL, " ");
  if (!code || strtok(NULL, " "))
    return (0);
  song = find_song_from_code(&luneth->songs, code);
  if (!song)
    return (luneth_respond_msgf(co, luneth, "Failed to find song %s", code));
  title = youtube_title(code);
  if (!title)
    return (
        luneth_respond_msgf(co, luneth, "Failed to find title for %s", code));
  ret = database_edit_title(luneth->db, code, title);
  if (ret)
  {
    luneth_respond_msgf(co, luneth, "Failed to edit title for %s", code);
    free(title);
    return (1);
  }
  free(song->title);
  song->title = title;
  ret = luneth_respond_msgf(co, luneth, "Title for %s is %s", code, title);
  return (ret);
}

static int song_search(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_vector* songs;
  t_song* song;
  size_t i;
  char* pattern;
  char* mess;
  int ret;

  (void)(bot);
  ret = 0;
  pattern = strtok(NULL, "");
  if (!pattern)
    return (0);
  songs = database_search_song(luneth->db, pattern);
  if (!songs)
    return (luneth_respond_msgf(
        co, luneth, "Couldnt find a song matching '%s'", pattern));
  if (vector_size(songs) == 1)
  {
    song = vector_at(songs, 0);
    ret = luneth_respond_msgf(
        co,
        luneth,
        "%s -> https://www.youtube.com/watch?v=%s [%s] : %s",
        co->cmd.prefixnick,
        song->code,
        song->category ? song->category : "",
        song->title ? song->title : "");
  }
  else
  {
    mess = cat_codes(songs);
    if (!mess)
    {
      ret = 1;
      luneth_respond_msg(co, luneth, "Failed to disp codes");
    }
    else
      ret = luneth_respond_msg(co, luneth, mess);
  }
  i = 0;
  while (i < vector_size(songs))
  {
    song_delete(vector_at(songs, i), true);
    ++i;
  }
  vector_delete(songs, true);
  return (ret);
}

static int song_categories(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  t_vector* categories;
  size_t i;
  char resp[513];
  char* curr;
  char* end;

  (void)(bot);
  categories = database_list_categories(luneth->db);
  if (!categories)
    return (luneth_respond_msg(co, luneth, "No categories"));
  i = 0;
  resp[0] = 0;
  curr = resp;
  end = curr + 500;
  while (i < vector_size(categories))
  {
    if (curr + strlen(vector_at(categories, i)) < end)
    {
      curr = stpcpy(curr, vector_at(categories, i));
      *(curr++) = ' ';
      ++i;
    }
    else
      i = vector_size(categories);
  }
  *curr = '\0';
  vector_foreach(categories, &free);
  vector_delete(categories, true);
  if (resp[0])
    return (luneth_respond_msg(co, luneth, resp));
  return (luneth_respond_msg(co, luneth, "No categories"));
}

static const char* const song_cmds[] = {
    "search", "add", "edit", "whois", "title", "help", "categories", NULL};

static int (*const song_fcts[])(t_bot*, t_ircconnection*, t_luneth*) = {
    song_search,
    song_add,
    song_edit,
    song_whois,
    song_title,
    song_help,
    song_categories,
    NULL};

int command_song(t_bot* bot, t_ircconnection* co, t_luneth* luneth)
{
  unsigned int i;
  t_song* song;
  char* category;

  (void)(bot);
  category = strtok(NULL, " ");
  if (category)
    for (i = 0; song_cmds[i]; ++i)
      if (!strcasecmp(category, song_cmds[i]))
        return (song_fcts[i](bot, co, luneth));
  song = database_select_random_songcateg(luneth->db, category);
  if (song)
  {
    luneth_respond_msgf(co,
                        luneth,
                        "%s -> https://www.youtube.com/watch?v=%s [%s] : %s",
                        co->cmd.prefixnick,
                        song->code,
                        song->category ? song->category : "",
                        song->title ? song->title : "");
    song_delete(song, true);
  }
  else if (errno == ENOMEM)
    return (1);
  else if (luneth_respond_msgf(co, luneth, "Failed to find a song"))
    return (1);
  return (0);
}
