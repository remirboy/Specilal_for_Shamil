#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

//task14

int main() {
    int a = 210;
    int num = 0;
#pragma omp parallel for lastprivate(num)
    for (int i = 1; i < a * 2; i = i + 2)
        num = num + i;
    printf("%i", num);
}