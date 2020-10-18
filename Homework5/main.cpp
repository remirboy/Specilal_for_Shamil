#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> // для функций rand() и srand()

//task5

int main()
{
    int a[6][8] = {};
    srand(time(0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = rand() % 100;
        }
    }
#pragma omp parallel sections
    {
#pragma omp section
        {
            int len = 0;
            int sum = 0;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    sum += a[i][j];
                    len += 1;
                }
            }
            printf("Average  %d  thread num = %d\n", sum / len, omp_get_thread_num());
        }
#pragma omp section
        {
            int min = 0;
            int max = 0;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (a[i][j] < min) {
                        min = a[i][j];
                    }
                    else if (a[i][j] > max) {
                        max = a[i][j];
                    }
                }
            }
            printf("min = %d and max = %d,\n thread num = %d\n", min, max, omp_get_thread_num());
        }
#pragma omp section
        {
            int num = 0;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (a[i][j] % 3 == 0) {
                        num++;
                    }
                }
            }
            printf("count of multiples of three = %d,\n thread num = %d\n", num, omp_get_thread_num());
        }
    }
}