#include <stdbool.h>
#define TESTS_H_IMPLEMENTATION
#include "tests.h"
#include "add.c"

test(add) {
    if (add(10,50) != 60) {
        return false;
    }

    if (add(41,-1) != 40) {
        return false;
    }

    return true;
}
