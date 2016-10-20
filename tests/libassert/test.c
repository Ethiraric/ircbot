/*
** test.c for  in /home/sabour_f/rendu/gomoku/tests/libassert
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Nov  9 02:07:57 2015 Florian SABOURIN
** Last update Mon Nov  9 02:07:59 2015 Florian SABOURIN
*/

#include <stdio.h>
#include "myassert.h"

int	good_function()
{
  assert(0 == 0);
  return (0);
}

int	bad_function()
{
  assert(1 == 2);
  return (1);
}

/*
** Tests that should run smoothly
*/
void	everything_ok()
{
  assert_run_test(&good_function, 0, (void *)(0));
  assert_run_test(&good_function, 0, "good_function");
  printf("\n");

  if (!assert_init_test())
    assert(3 == 3);
  else
    printf("Assert Error !\n");
}

/*
** Each of these tests should fail
*/
void	everything_wrong()
{
  // Return value is not the one expected
  assert_run_test(&good_function, 1, "good_function_fails");
  printf("\n");

  assert_run_test(&bad_function, 1, "bad_function");
  printf("\n");

  if (!assert_init_test())
    {
      assert(2 == 3);
      printf("Assert Error !\n\n");
    }
  else
    {
      printf("Failed as expected\n\n");
    }

  if (!assert_init_test())
    {
      assert_error("expr", "file", "function", 42);
      printf("Assert Error !\n\n");
    }
  else
    {
      printf("Failed as expected\n\n");
    }
}

/*
** When changing strings
*/
void	change_strings()
{
  // Changing strings
  assert_set_errmsg(NULL);
  assert_run_test(&bad_function, 0, NULL);

  assert_set_errmsg("yolo\n\n");
  assert_run_test(&bad_function, 0, NULL);

  assert_set_errmsg((void *)(-1));
  assert_run_test(&bad_function, 0, NULL);
  printf("\n");

  assert_run_test_setstrs("Testing %s\n", "Passed\n", "Failed\n");
  assert_run_test(&good_function, 0, "good");
  printf("\n");
  assert_run_test(&bad_function, 0, "bad");

}

/*
** Testing suite for assert library
*/
int	main()
{
  everything_ok();
  everything_wrong();
  change_strings();
  return (0);
}
