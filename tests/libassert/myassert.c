/*
** assert.c for  in /home/sabour_f/rendu/gomoku/tests/libassert
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Nov  9 01:52:58 2015 Florian SABOURIN
** Last update Mon Nov  9 01:52:59 2015 Florian SABOURIN
*/

#include <stdio.h>
#ifdef NDEBUG
# undef NDEBUG
#endif
#include "myassert.h"

/*
** jmp_buf used by assert to simulate throw
*/
static jmp_buf assert_jmpbuf;

/*
** Respectively default and current error message
** Note that if assert_error_msg is null, no message is printed by assert_error
*/
static const char *assert_default_err_msg = "%s:%s:%u: assertion %s failed\n";
static const char *assert_error_msg = "%s:%s:%u: assertion %s failed\n";

/*
** Strings displayed by assert_run_test respectively when running a test, when
** the test passed and when the test failed
*/
static const char *assert_testingstr = "Testing: %s\n";
static const char *assert_testokstr = "Test passed: %s\n";
static const char *assert_testfailedstr = "Test failed: %s\n";

/*
** Returns the location of the assert jmp_buf
*/
jmp_buf	*assert_jmpbuf_location()
{
  return (&assert_jmpbuf);
}

/*
** When an assert test fails
** Prints an error message on stderr if assert_error_msg is not null, and jumps
** to assert_init_test
*/
void	assert_error(const char *expr, const char *file, const char *function,
		     unsigned int line)
{
  if (assert_error_msg)
    fprintf(stderr, assert_error_msg, file, function, line, expr);
  longjmp(assert_jmpbuf, 1);
}

/*
** Convenience function to run a test
** If testname is not null, prints a message on stdout before and after testing
** Returns zero if the test passed, non-zero otherwise
*/
int	assert_run_test(int (*test_function)(), int expected_return_value,
			const char *testname)
{
  if (!assert_init_test())
    {
      if (testname)
	{
	  printf(assert_testingstr, testname);
	  assert(test_function() == expected_return_value);
	  printf(assert_testokstr, testname);
	}
      else
	assert(test_function() == expected_return_value);
      return (0);
    }
  else
    {
      if (testname)
	printf(assert_testfailedstr, testname);
      return (1);
    }
}

/*
** Sets the error message when assert_error is called
** fprintf parameters are (in that order):
** const char * : the file assert_error was called from
** const char * : the function assert_error was called from
** unsigned int : the line assert_error was called from
** const char * : the expression that was asserted
**
** If str is null, no error message will be printed by assert_error
** If str is (void *)(-1), the default error message will be used
*/
void	assert_set_errmsg(const char *str)
{
  if (str == (void *)(-1))
    assert_error_msg = assert_default_err_msg;
  else
    assert_error_msg = str;
}

/*
** Sets the messages printed when using assert_run_test
** Each of them has one printf parameter:
** const char * : the name of the test
**
** Warning: No check is performed. All parameters must point to valid strings
*/
void assert_run_test_setstrs(const char *testingstr, const char *testokstr,
			     const char *testfailedstr)
{
  assert_testingstr = testingstr;
  assert_testokstr = testokstr;
  assert_testfailedstr = testfailedstr;
}
