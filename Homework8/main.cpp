#include <iostream>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> // для функций rand() и srand()
#include <chrono>

//task8
int main() {
    srand(time(0));
    int matrix[500][500];
    int vector[500];
    for (int i = 0; i < 500; i++) {
        vector[i] = rand() % 500;
        for (int j = 0; j < 500; j++) {
            matrix[i][j] = rand() % 500;
        }
    }
    int arr[500];
    auto time1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            arr[i] = arr[i] + matrix[i][j] * vector[j];
        }
    }
    auto time2 = std::chrono::high_resolution_clock::now();
    printf("Without openpm = %lld ms\n", std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count());


#pragma omp parallel num_threads(8)
    {
    auto time3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            arr[i] = arr[i] + matrix[i][j] * vector[j];
        }
    }
    auto time4 = std::chrono::high_resolution_clock::now();
    printf("With openpm = %lld ms\n", std::chrono::duration_cast<std::chrono::microseconds>(time4 - time3).count());
}
}
