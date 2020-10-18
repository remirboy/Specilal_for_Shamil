#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>

//task9

int main() {
    int d[6][8] = {};
    srand(time(0));
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 8; j++)
            d[i][j] = rand() % 100;
    int min,max = d[0][0];
    #pragma omp parallel num_threads(8)
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 8; j++)
            if(d[i][j]>max)
#pragma omp critical
                    if (d[i][j] < min) {
                        min = d[i][j];
                    }
                    else if (d[i][j] > max) {
                        max = d[i][j];
                    }
    }
    std::cout <<"Min "<<min<<"\n";
    std::cout <<"Max "<<max<<"\n";

}

