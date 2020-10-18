#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#define len 30

//task10

int main() {
    int a[30]= {};
    int count=0;
    srand(time(0));
    for (int i = 0; i < len; i++)
        a[i]=rand() % 100;

#pragma omp parallel num_threads(4)
    {
        for (int i = 0; i < len; i++)
            if (a[i] % 9 == 0)
#pragma omp atomic
                count++;
    }
    std::cout <<"Count "<<count<<"\n";

}
