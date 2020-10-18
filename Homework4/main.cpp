#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#define len 10
//task4
int main() {

    int a[] = {3, 4, 5, -1, 3, 1, 6, 5, 3, 2};
    int b[] = {3, 4, 5, 7, 3, 1, 4, 5, 3, 2};
    int min = a[0];
    int max = b[0];
#pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < len;i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
        }

        if (omp_get_thread_num() == 1) {
            for (int i = 0; i <len; i++) {
                if (b[i] > max) {
                    max = b[i];
                }
            }
        }

    }
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    return 0;
}
