#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#define len 50

//task11

int main() {
    int arr[50];
    srand(time(0));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100;
    int max = arr[0];
#pragma omp parallel for shared(max) schedule(dynamic)
    for (int i = 0; i < len; i++)
    {
        if (arr[i] % 7 == 0)
        {
#pragma omp critical
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
    }
    std::cout <<"Max "<<max<<"\n";
}
