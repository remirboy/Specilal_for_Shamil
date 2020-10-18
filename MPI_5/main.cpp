#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task5

int main(int argc, char* argv[]) {
    int processId, size;
    srand(time(0));
    int arr[12];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
    MPI_Status status;
    if (processId == 0) {
        for (int i = 0; i < 12; i++) {
            arr[i] = rand() % 100;
        }
        printf("Number of process - %d and total - %d", processId, size);
        int block = 12 / size + 1;
        int k = 0;
        for (int i = 1; i < size; i++) {
            int* newarr = new int[block];
            for (int j = 0; j < block; j++) {
                if (k <= 11)
                    newarr[j] = arr[k];
                else
                    newarr[j] = 0;
                k++;
            }
            MPI_Send(newarr, block, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
    }
    if (processId != 0) {
        int count;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);
        int* arr1 = new int[count];
        printf("Number of process - %d and total - %d\n", processId, size);
        MPI_Recv(arr1, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        for (int i = 0; i < count; i++)
            printf("%d\n", arr1[i]);
    }
    MPI_Finalize();
    return 0;
}