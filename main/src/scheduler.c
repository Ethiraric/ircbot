#include <stdlib.h>
#include <time.h>

#include "scheduler.h"

static void tasklist_insert_task(t_tasklist* tasklist, t_task* task)
{
  if (!*tasklist)
  {
    task->prev = NULL;
    task->next = NULL;
    *tasklist = task;
    return;
  }

  t_task* current;

  current = *tasklist;
  while (current->next)
  {
    // If the task is to be executed before the next one in the queue
    if (task->time < current->time)
    {
      task->prev = current->prev;
      current->prev = task;
      task->next = current;
      if (!task->prev)
        *tasklist = task;
      return;
    }
    current = current->next;
  }

  // current points to the last element of the list
  // If the task is to be executed before, insert it before
  if (task->time < current->time)
  {
    task->prev = current->prev;
    current->prev = task;
    task->next = current;
  }
  // Otherwise as the last element
  else
  {
    task->prev = current;
    task->next = NULL;
    current->next = task;
  }
  if (!task->prev)
    *tasklist = task;
}

// free()s a task and all subsequent tasks, using recursion
static void tasklist_delete_stub(t_task* task)
{
  if (task->next)
    tasklist_delete_stub(task->next);
  free(task);
}

int tasklist_insert(t_tasklist* tasklist,
                    void* data,
                    int (*callback)(void*, time_t),
                    time_t tasktime)
{
  t_task* task;

  task = malloc(sizeof(t_task));
  if (!task)
    return 1;
  task->data = data;
  task->callback = callback;
  task->time = tasktime;
  tasklist_insert_task(tasklist, task);
  return 0;
}

int tasklist_call_and_discard(t_tasklist* tasklist, time_t now)
{
  if (!now)
    now = time(NULL);

  t_task* current;
  int result;

  current = *tasklist;
  while (current && current->time <= now)
  {
    result = current->callback(current->data, now);
    *tasklist = current->next;
    if (*tasklist)
      (*tasklist)->prev = NULL;
    free(current);
    if (result)
      return result;
    current = *tasklist;
  }
  return 0;
}

void tasklist_delete(t_tasklist tasklist)
{
  tasklist_delete_stub(tasklist);
}
