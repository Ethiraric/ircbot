#ifndef MYASSERT_H_
#define MYASSERT_H_

/*
** libassert: easy-to-use tools to write unit tests
**
** Unlike the default assert macro, no signal is raised. When a test fails, the
** assert_error function jumps back to where assert_init_test was last called
** and the latter returns non-zero.
**
** A common way to use it is :
** // Change strings if needed
** assert_set_errmsg("%s:%s:%u: %s\n");
** if (assert_init_test() == 0)
** {
**   // Run tests, using assert()
** }
** else
** {
**   // Something bad happened, an error message has been printed
** }
**
** Or using assert_run_test:
** // Change strings if needed
** assert_set_errmsg("%s:%s:%u: %s\n");
** assert_run_test_setstrs("Testing %s\n", "Passed\n", "Failed\n");
** if (assert_run_test(&test_function, 0, "mytest") == 0)
** {
**   // Everything went as expected
** }
** else
** {
**   // The test failed
** }
**
** You don't need to define error strings. Default messages are preset
*/

# include <setjmp.h>

# ifndef NDEBUG
/*
** Convenient way to assert an expression
*/
#  define assert(expr)	\
  do { \
    if (!(expr)) \
	 assert_error(#expr, __FILE__, __func__, __LINE__); \
  } while (0)
# else
#  define assert(expr) (void)(expr)
# endif

/*
** Initializes an assert test
** If it returns zero, you may start asserting
** If it returns non-zero, an assertion failed
** Turning it into a function breaks setjmp because a return is made in the
** program's call stack
*/
# ifndef NDEBUG
#  define assert_init_test()	setjmp(*assert_jmpbuf_location())
# else
#  define assert_init_test()	(0)
# endif

/*
** Assert utility functions
*/
# ifndef NDEBUG
void	assert_error(const char *expr, const char *file, const char *function,
		     unsigned int line);
int	assert_run_test(int (*test_function)(), int expected_return_value,
			const char *testname);
# else
#  define assert_error(a, b, c, d) (void)(a),(void)(b),(void)(c),(void)(d)
#  define assert_run_test(a, b, c) (a,b,c,0)
# endif
void	assert_set_errmsg(const char *str);
void	assert_run_test_setstrs(const char *testingstr, const char *testokstr,
				const char *testfailedstr);

/*
** "Private" functions
** Use at your own risks
*/
jmp_buf	*assert_jmpbuf_location();

#endif /* !MYASSERT_H_ */
