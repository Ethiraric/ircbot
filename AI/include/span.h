#ifndef SPAN_H_
#define SPAN_H_

#include <stddef.h>

// Contiguous array
typedef struct
{
  unsigned char* begin;// Pointer to the first element
  unsigned char* end;  // Pointer past the last element
  size_t size;         // Number of elements stored
  size_t reserved;     // How much element are allocated
  size_t elem_size;    // Size of a single element
} t_span;

void span_init(t_span* span, size_t elem_size);
t_span* span_new(size_t elem_size);
void span_destruct(t_span* span);
void span_delete(t_span* span);

size_t span_size(t_span* span);
void* span_begin(t_span* span);
void* span_at(t_span* span, unsigned int index);

int span_reserve(t_span* span, size_t size);
int span_resize(t_span* span, size_t size);

int span_push_back(t_span* span, void* elem);
int span_pop_back(t_span* span);
int span_insert(t_span* span, void* elem, unsigned int index);

#endif /* !SPAN_H_ */
