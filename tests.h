#ifndef TESTS_H
#define TESTS_H

#include <stdbool.h>
#include <stdio.h>

typedef int (*TestCase)(void);

#define MAX_TESTS 256
char *names[MAX_TESTS];
TestCase cases[MAX_TESTS];
int numCases;

#define test(name) \
    int test_##name(void); \
    __attribute__((constructor)) \
    void test_##name_init(void) { \
        names[numCases] = #name; \
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

        fprintf(stderr, "test %s failed\n", names[i]);
        failed++;
    }

    putc('\n', stderr);
    fprintf(stderr, "%03d passed\n", passed);
    fprintf(stderr, "%03d failed\n", failed);
    fprintf(stderr, "%03d total\n", numCases);

    return failed;
}

#endif//TESTS_H
