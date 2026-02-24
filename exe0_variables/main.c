#include "stdio.h"

void foo(int *a) {
    *a = *a + 1;
}

void main(void) {
    int a = 0;
    int b = 0;
    while (1) {
        foo(&a);

        if (a > 5) {
            b = 1;
        }
    }
}
