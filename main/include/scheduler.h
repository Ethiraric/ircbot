#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <time.h>

typedef struct s_task
{
  time_t time;
  void* data;
  int (*callback)(void*, time_t);
  struct s_task* next;
  struct s_task* prev;
} t_task;

typedef t_task* t_tasklist;

int tasklist_insert(t_tasklist* tasklist,
                    void* data,
                    int (*callback)(void*, time_t),
                    time_t tasktime);
int tasklist_call_and_discard(t_tasklist* tasklist, time_t now);
void tasklist_delete(t_tasklist tasklist);

#endif /* !SCHEDULER_H_ */
