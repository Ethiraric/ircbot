#include "span.h"
#include <stdlib.h>
#include <string.h>

void span_init(t_span* span, size_t elem_size)
{
  span->begin = NULL;
  span->end = NULL;
  span->size = 0;
  span->reserved = 0;
  span->elem_size = elem_size;
}

t_span* span_new(size_t elem_size)
{
  t_span* span;

  span = malloc(sizeof(t_span));
  if (span)
    span_init(span, elem_size);
  return (span);
}

void span_destruct(t_span* span)
{
  if (span->begin)
    free(span->begin);
}

void span_delete(t_span* span)
{
  span_destruct(span);
  free(span);
}

size_t span_size(t_span* span)
{
  return (span->size);
}

void* span_begin(t_span* span)
{
  return (span->begin);
}

void* span_at(t_span* span, unsigned int index)
{
  return (span->begin + (index * span->elem_size));
}

int span_reserve(t_span* span, size_t size)
{
  void* tmp;
  size_t bytesize;

  bytesize = size * span->elem_size;
  tmp = realloc(span->begin, bytesize);
  if (!tmp)
    return (1);
  span->begin = tmp;
  span->end = span->begin + bytesize;
  span->reserved = size;
  if (span->size > size)
    span->size = size;
  return (0);
}

int span_resize(t_span* span, size_t size)
{
  if (size > span->reserved && span_reserve(span, size))
    return (1);
  span->size = size;
  return (0);
}

int span_push_back(t_span* span, void* elem)
{
  void* mem_end;

  if (span->size == span->reserved && span_reserve(span, span->size + 8))
    return (1);
  mem_end = span->begin + (span->elem_size * span->size);
  memcpy(mem_end, elem, span->elem_size);
  ++span->size;
  return (0);
}

int span_pop_back(t_span* span)
{
  --span->size;
  if (span->size + 16 < span->reserved)
    return (span_reserve(span, span->reserved - 8));
  return (0);
}

int span_insert(t_span* span, void* elem, unsigned int index)
{
  if (index >= span->size)
    return (span_push_back(span, elem));
  if (span->size == span->reserved && span_reserve(span, span->size + 8))
    return (1);
  memmove(span_at(span, index),
          span_at(span, index + 1),
          (span->size - index) * span->elem_size);
  memmove(span_at(span, index), elem, span->elem_size);
  ++span->size;
  return (0);
}
