#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>

//task2

int main() {

    int threads_count = 3;
    #pragma omp parallel num_threads(threads_count)
    if (threads_count>1){
        printf("Area1, thread num = %i, num of threads = %i\n", omp_get_thread_num(),
               omp_get_num_threads());
    }

    int threads_count2 = 1;

    #pragma omp parallel num_threads(threads_count2)
        if (threads_count2>1){
        printf("Area2, thread num = %i, num of threads = %i\n", omp_get_thread_num(),
               omp_get_num_threads());
    }
}
