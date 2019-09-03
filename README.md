# ctests

This is a simple unit testing framework for C programs.

To use it, `#include "tests.h"` in your tests files, then use the `test` macro instead of a regular function call.

For example:

```
int test_add(void) {
  return add(1,1) == 2;
}

// Replace with...

test(add) {
  return add(1,1) == 2;
}

```

Compile and run using:

    $ cc -o testrunner *_test.c && ./testrunnner
