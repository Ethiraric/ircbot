/*
** vector.c for  in /home/sabour_f/rendu/ircbot/main/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Apr 24 17:55:52 2015 Florian SABOURIN
** Last update Fri Apr 24 17:55:53 2015 Florian SABOURIN
*/

#include "vector.h"
#include <stdlib.h>

// Deallocate all resources allocated for a vector
void vector_delete(t_vector* vec, bool free_struct)
{
  free(vec->tab);
  vec->allocd = 0;
  vec->len = 0;
  if (free_struct)
    free(vec);
}

// Erase an element in the vector at given index
// Does NOT free the pointer
int vector_erase(t_vector* vec, unsigned int pos)
{
  // Ensure it is inbounds
  if (pos >= vec->len)
    return (1);
  --(vec->len);
  // Move the cells that are after the one erased
  memmove(&vec->tab[pos], &vec->tab[pos + 1], sizeof(void*) * (vec->len - pos));
  // Shrink the vector if we have enough space
  if (vec->allocd - vec->len > 2 * vec->alloc_step)
    if (vector_realloc(vec, vec->allocd - vec->alloc_step))
      return (1);
  return (0);
}

// Find an element in the vector
// Note that it compares pointers and not the value pointed by the pointer
unsigned int vector_find(t_vector* vec, void* elem)
{
  unsigned int it;

  it = 0;
  // Foreach element, compare pointers
  while (it < vec->len)
  {
    if (vec->tab[it] == elem)
      return (it);
    ++it;
  }
  // Return -1 if we can't find it
  return ((unsigned int)(-1));
}

// Insert an element at given index
int vector_insert(t_vector* v, unsigned int pos, void* elem)
{
  // Ensure it is inbounds
  if (pos > v->len)
    return (1);
  // Realloc if necessary
  if (v->len + 1 > v->allocd && vector_realloc(v, v->allocd + v->alloc_step))
    return (1);
  // Insert
  memmove(&v->tab[pos + 1], &v->tab[pos], (v->len - pos) * sizeof(void*));
  v->tab[pos] = elem;
  ++(v->len);
  return (0);
}

// Initialize a new vector
void vector_new(t_vector* vec)
{
  static const t_vector ret = {0, 0, 10, NULL};

  *vec = ret;
}

// Remove (if any) the last element of the vector
void vector_pop_back(t_vector* vec)
{
  if (vec->len)
    --(vec->len);
}

// Append an element at the end of the vector
int vector_push_back(t_vector* vec, void* elem)
{
  // Realloc if necessary
  if (vec->len + 1 > vec->allocd &&
      vector_realloc(vec, vec->allocd + vec->alloc_step))
    return (1);
  // Insert
  vec->tab[vec->len] = elem;
  ++(vec->len);
  return (0);
}

// Reallocate the vector so it can hold at least size elements
int vector_realloc(t_vector* v, size_t size)
{
  void* newptr;

  // Try to realloc, return if it fails
  if ((newptr = realloc(v->tab, size * sizeof(void*))) == NULL)
    return (1);
  // Update pointer and allocated size (size if we shrink too far)
  v->tab = newptr;
  v->allocd = size;
  if (v->allocd < v->len)
    v->len = v->allocd;
  return (0);
}

// Returns the size of the vector (number of elements in the vector)
size_t vector_size(const t_vector* v)
{
  return (v->len);
}

// Returns the pos-th element in the vector
// Does not check if it is inbounds
void* vector_at(t_vector* v, size_t pos)
{
  return (v->tab[pos]);
}

// Call a function on each of the elements in the vector
// Useful when freeing everything
void vector_foreach(t_vector* v, void (*fct)(void*))
{
  size_t it;

  it = 0;
  while (it < v->len)
  {
    fct(v->tab[it]);
    ++it;
  }
}
