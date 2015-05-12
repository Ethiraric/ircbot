/*
** vector.h for  in /home/sabour_f/rendu/ircbot/main/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Apr 24 19:45:43 2015 Florian SABOURIN
** Last update Fri Apr 24 19:45:44 2015 Florian SABOURIN
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include <stdbool.h>
# include <string.h>

typedef struct	s_vector
{
  size_t	len;
  size_t	allocd;
  size_t	alloc_step;
  void		**tab;
}		t_vector;

void		vector_new(t_vector *vec);
void		vector_delete(t_vector *vec, bool free_struct);
int		vector_insert(t_vector *v, unsigned int pos, void *elem);
int		vector_erase(t_vector *vec, unsigned int pos);
int		vector_push_back(t_vector *vec, void *elem);
void		vector_pop_back(t_vector *vec);
unsigned int	vector_find(t_vector *vec, void *elem);
int		vector_realloc(t_vector *v, size_t size);
size_t		vector_size(const t_vector *v);
void		*vector_at(t_vector *v, size_t pos);
void		vector_foreach(t_vector *v, void (*fct)(void *));

#endif /* !VECTOR_H_ */
