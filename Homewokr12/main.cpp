#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>

//task12
//1
int main() {
    int* threads = new int[8];
    omp_set_num_threads(8);
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 8; ++i)
            threads[i] = omp_get_thread_num();
#pragma omp for ordered
        for (int i = 7; i >= 0; --i) {
#pragma omp ordered
            {
                printf("Current thread: %i; Total number of threads: %i; Hello World!\n", threads[i], omp_get_num_threads());
            }
        }
    }

    printf("\n");
    // 2
#pragma omp parallel num_threads(8)
    {
        for (int i = omp_get_num_threads() - 1; i >= 0; i--) {
#pragma omp barrier
            {
                if (i == omp_get_thread_num()) {
#pragma omp critical
                    printf("Hello world, thread num = %i, num of threads = %i\n", omp_get_thread_num(),
                           omp_get_num_threads());
                }
            }
        }
    }

    printf("\n");
}
