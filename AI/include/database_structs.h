#ifndef DATABASE_STRUCTS_H_
# define DATABASE_STRUCTS_H_

# include "vector.h"
# include "t_mapstring.h"

typedef unsigned int t_id;

typedef struct	s_chan
{
  t_id		id;
  char		*channel;
  char		*server;
}		t_chan;

typedef struct	s_song
{
  t_id		id;
  t_id		authid;
  char		*title;
  char		*code;
  char		*category;
}		t_song;

typedef struct	s_people
{
  t_id		id;
  t_id		channel;
  char		*nick;
  unsigned int	score;
}		t_people;

typedef struct	s_message
{
  t_id		id;
  t_id		author;
  char		*message;
}		t_message;

typedef struct	s_cmd
{
  t_id		id;
  char		*cmd;
  char		*text;
}		t_cmd;

typedef struct	s_say
{
  t_id		id;
  t_id		auth;
  t_id		dest;
  char		*text;
}		t_say;

#endif /* !DATABASE_STRUCTS_H_ */
