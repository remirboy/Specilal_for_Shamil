#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>

//task3

int main() {
    int a = 8;
    int b = 9;
    printf("Before:");
    printf("a =%i, b=%i\n", a, b);

    #pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        int delta = omp_get_thread_num();
        a += delta;
        b += delta;
        printf("In:");
        printf("a =%i, b=%i\n", a, b);
    }
    printf("After:");
    printf("a =%i, b=%i\n", a, b);

    printf("Before:");
    printf("a =%i, b=%i\n", a, b);

    #pragma omp parallel num_threads(4) shared(a) private(b)
    {
        int delta = omp_get_thread_num();
        a -= delta;
        b -= delta;
        printf("In:");
        printf("a =%i, b=%i\n", a, b);
    }
    printf("After:");
    printf("a =%i, b=%i\n", a, b);
    return 0;
}
