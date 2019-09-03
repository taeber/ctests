// Copyright 2019, Taeber Rapczak <taeber@rapczak.com>
// MIT License https://opensource.org/licenses/MIT
#ifndef TESTS_H
#define TESTS_H

#include <stdbool.h>
#include <stdio.h>

typedef int (*TestCase)(void);

#define MAX_TESTS 256
char *names[MAX_TESTS];
TestCase cases[MAX_TESTS];
int numCases;

#define MACROSTRING(X) #X
#define STRING(X) MACROSTRING(X)
#define test(name) \
    int test_##name(void); \
    __attribute__((constructor)) \
    void test_##name_init(void) { \
        names[numCases] = __FILE__ "@" STRING(__LINE__) ":" #name; \
        cases[numCases] = test_##name; \
        numCases++; \
    } \
    int test_##name(void)


int main() {
    int passed = 0,
        failed = 0;

    for (int i = 0; i < numCases; i++) {
        if (cases[i]()) {
            passed++;
            continue;
        }

        fprintf(stderr, "FAIL: %s\n", names[i]);
        failed++;
    }

    putc('\n', stderr);
    fprintf(stderr, "%3d passed\n", passed);
    fprintf(stderr, "%3d failed\n", failed);
    fprintf(stderr, "%3d total\n", numCases);

    return failed;
}

#endif//TESTS_H
