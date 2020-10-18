#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#define len 12

int main() {
    int rmax = 20;
    int rmin = 120;
    int i;
    int a[len];
    int b[len];
    int c[len];
#pragma omp parallel num_threads(3)
    {
#pragma omp for private(i) schedule(static)
        for (i = 0; i < len; i++) {
            a[i] = rmax + rand() % (rmin - rmax);
            b[i] = rmax + rand() % (rmin - rmax);
        }
        for (i = 0; i < len; i++) {
            std::cout << a[i]<<"\t";
        }
        for (i = 0; i < len; i++) {
            std::cout << b[i]<<"\t";
        }
        std::cout << "\n";
        std::cout <<"Thread "<< omp_get_thread_num()<<"\n";
        std::cout <<"Threads "<< omp_get_num_threads()<<"\n";

    }

#pragma omp parallel num_threads(4)
    {
#pragma omp for private(i) schedule(dynamic)
        for (i = 0; i < len; i++) {
            c[i] = a[i]+b[i];
        }
        for (i = 0; i < len; i++) {
            std::cout << c[i]<<"\t";
        }
        std::cout << "\n";
        std::cout <<"Thread "<< omp_get_thread_num()<<"\n";
        std::cout <<"Threads "<< omp_get_num_threads()<<"\n";
    }
}
