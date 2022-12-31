// Copyright 2019–2022, Taeber Rapczak <taeber@rapczak.com>
// MIT License https://opensource.org/licenses/MIT
#ifndef TESTS_H
#define TESTS_H

typedef _Bool (*TestCase)(void);

#ifndef MAX_TESTS
#define MAX_TESTS 256
#endif

char *names[MAX_TESTS];
TestCase cases[MAX_TESTS];
int numCases;

#define MACROSTRING(X) #X
#define STRING(X) MACROSTRING(X)
#define test(name) \
    _Bool test_ ## name(void); \
    __attribute__((constructor)) \
    void test_ ## name ## _init(void) { \
        names[numCases] = __FILE__ "@" STRING(__LINE__) ":" #name; \
        cases[numCases] = test_##name; \
        numCases++; \
    } \
    _Bool test_##name(void)

#ifdef TESTS_H_IMPLEMENTATION

#include <stdio.h>

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

    if (failed > 0) {
        putc('\n', stderr);
    }
    fprintf(stderr, "%3d passed\n", passed);
    fprintf(stderr, "%3d failed\n", failed);
    fprintf(stderr, "%3d total\n", numCases);

    return failed;
}

#endif//TESTS_H_IMPLEMENTATION

#endif//TESTS_H
