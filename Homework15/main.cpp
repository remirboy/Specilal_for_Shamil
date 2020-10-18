#include <iostream>
#include <stdio.h>
#include "/usr/local/opt/libomp/include/omp.h"
#include <cmath>

//task15

int main() {
    int first, second;
    std::cout << "Enter two number: ";
    std::cin >> first >> second;
    printf("\nNumbers: \n");
    omp_set_num_threads(4);
#pragma omp parallel for
    for (int i = first; i < second; i++) {
        bool simple = true;
        for (int j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
                simple = false;
        if (simple)
            printf("%d\n", i);
    }
}