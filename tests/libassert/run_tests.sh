#!/bin/bash

# 1 if all is well, 0 otherwise
ok=1

# Try to compile and run tests
# Redirect stdout to test.stdout and stderr to test.stderr

make > /dev/null && gcc test.c assert.c -o test && ./test > test.stdout 2> test.stderr
if [[ $? -ne 0 ]]
then
    echo "Something went wrong"
    exit 1
fi

# Make sure the output is what is expected

diff test.stdout expected.stdout >/dev/null

if [[ $? -ne 0 ]]
then
  echo "stdout differs"
  ok=0
fi

diff test.stderr expected.stderr >/dev/null

if [[ $? -ne 0 ]]
then
  echo "stderr differs"
  ok=0
fi

if [[ $ok -eq 1 ]]
then
  echo "All tests passed"
  exit 0
fi

exit 1
