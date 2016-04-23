/*
** database.h for  in /home/sabour_f/rendu/ircbot/AI/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri May  1 23:16:37 2015 Florian SABOURIN
** Last update Fri May  1 23:16:38 2015 Florian SABOURIN
*/

#ifndef DATABASE_H_
# define DATABASE_H_

# include <stdbool.h>
# include <sqlite3.h>
# include "t_mapstring.h"
# include "vector.h"
# include "database_structs.h"

# define TABLE_MESSAGES		"messages"
# define TABLE_SONGS		"musics"
# define TABLE_PEOPLE		"authors"
# define TABLE_CHANS		"chans"
# define TABLE_CMD		"cmd"
# define TABLE_SAY		"say"

int		chan_delete(t_chan *chan, bool free_struct);
t_chan		*chan_from_db(t_mapstring *res, unsigned int it);

t_song		*song_from_db(t_mapstring *res, unsigned int it);
int		song_delete(t_song *song, bool free_struct);
t_vector	*song_tab_from_db(t_mapstring *res);

t_people	*ppl_from_db(t_mapstring *res, unsigned int it);
int		ppl_delete(t_people *ppl, bool free_struct);

t_cmd		*cmd_from_db(t_mapstring *res, unsigned int it);
int		cmd_delete(t_cmd *cmd, bool free_struct);

t_say		*say_from_db(t_mapstring *res, unsigned int it);
int		say_delete(t_say *say, bool free_struct);
t_vector	*say_tab_from_db(t_mapstring *res);

typedef struct	s_db
{
  sqlite3	*handler;
}		t_db;

t_db		*database_new(const char *filename);
void		database_delete(t_db *db);

  // Helper database functions
char		*database_escape_quotes(const char *in);
t_mapstring	*database_select_exec(t_db *db, const char *statement);

  // People
t_people	*database_get_ppl_fromnickchan(t_db *db, const char *nick,
					       t_id chan);
t_id		database_insert_ppl(t_db *db, const char *nick, t_id chan);
t_people	*database_ppl_fromid(t_db *db, t_id id);
int		database_add_score(t_db *db, const char *nickname,
				   const char *channel,const char *server,
				   int modif);

  // Channel
t_chan		*database_get_chan_fromchanserv(t_db *db, const char *serv,
						const char *chan);
t_id		database_insert_chan(t_db *db, const char *serv,
				     const char *chan);

  // Song
t_song		*database_get_song_fromcode(t_db *db, const char *code);
t_id		database_insert_song(t_db *db, const char *code,
				     const char *categ, t_id auth);
t_song		*database_get_song_fromid(t_db *db, unsigned int id);
t_song		*database_select_random_song(t_db *db);
t_song		*database_select_random_songcateg(t_db *db, const char *categ);
int		database_edit_category(t_db *db, const char *code,
				       const char *categ);
int		database_edit_title(t_db *db, const char *code,
				    const char *title);
t_vector	*database_search_song(t_db *db, const char *pattern);

  // Message
t_id		database_insert_msg(t_db *db, const char *nick,
				    const char *chan, const char *serv,
				    const char *msg);

  // Commands
bool		database_is_command(t_db *db, const char *cmd);
t_id		database_insert_command(t_db *db, const char *cmd,
					const char *text);
t_cmd		*database_get_cmd(t_db *db, const char *cmd);
int		database_rm_cmd(t_db *db, const char *cmd);
t_mapstring	*database_load_all_cmds(t_db *db);

  // Say
t_id		database_insert_say(t_db *db, t_id auth, t_id dest,
				    const char *text);
t_vector	*database_get_say(t_db *db, t_id dest);
t_say		*database_say_fromid(t_db *db, t_id id);
int		database_rm_say(t_db *db, t_id id);

  // DB helpers
t_id		database_pplid(t_db *db, const char *nick, const char *serv,
			       const char *chan);
t_id		database_chanid(t_db *db, const char *serv, const char *chan);
t_people	*database_get_song_auth(t_db *db, const char *code);
t_vector	*database_list_categories(t_db *db);

#endif /* DATABASE_H_ */
