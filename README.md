# ctests

This is a simple unit testing framework for C programs.

The library is contained in a single header file (`tests.h`) that contains both
the definitions and implementation of the test runner.

Exactly one implementation is required.

To use the provided runner, in one file, define `TESTS_H_IMPLEMENTATION` before
the `#include`:

```
#define TESTS_H_IMPLEMENTATION
#include "tests.h"
```

For any other file, simple `#include "tests.h"`, then use the `test` macro
instead of a regular function call.

For example:

```
int test_add(void) {
  return add(1,1) == 2;
}

// Replace with...

#include "tests.h"

test(add) {
  return add(1,1) == 2;
}

```

Compile and run using:

    $ cc -o testrunner *_test.c && ./testrunnner

You are free to implement your own test runner by writing `main()`.
