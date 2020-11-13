#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#define len 16000

int main() {
    int a[len];
    int b[len-2];
    int i;
#pragma omp parallel num_threads(4)
    {
        auto time3 = std::chrono::high_resolution_clock::now();
#pragma omp for private(i) schedule(guided)
        for (i = 0; i < len; i++)
            a[i] = i;
        for (i = 1; i < len - 1; i++)
            b[i-1] = (a[i - 1] + a[i] + a[i + 1]) / 3;
        auto time4 = std::chrono::high_resolution_clock::now();
        printf("With openpm = %lld ms\n", std::chrono::duration_cast<std::chrono::microseconds>(time4 - time3).count());
    }
}
