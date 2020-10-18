#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#define len 10

//task6

int main() {
    int a[] = {3, 4, 5, -1, 3, 1, 6, 5, 3, 2};
    int b[] = {3, 4, 5, 7, 3, 1, 4, 5, 3, 2};
    int i;
    int meana=0;
    int meanb=0;
#pragma omp parallel
    {
#pragma for reduction shared(a) private(i)(+:meana,meanb)
        for(i=0; i<len; i++) {
            meana += a[i];
            meanb += b[i];
        }

    }
    std::cout << meanb/len-meana/len<<"\t";

}
