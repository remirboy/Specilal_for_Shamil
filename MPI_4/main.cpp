#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

//task4

int main(int argc, char* argv[]) {
    int processId, size;
    srand(time(0));
    int arr[10];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
    MPI_Status status;
    if (processId == 0) {
        for (int i = 0; i < 10; i++) {
            arr[i] = rand() % 100;
        }
        printf("Number of process - %d and total - %d", processId, size);
        for (int j = 1; j < 4; j++) {
            MPI_Send(arr, 10, MPI_INT, j, 1, MPI_COMM_WORLD);
        }
    }
    if (processId != 0) {
        int count;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);
        int *arr1 = new int[count];
        printf("Number of process - %d and total - %d\n", processId, size);
        MPI_Recv(arr1,10 , MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        for (int i = 0; i < 10; i++) {
            printf("%d\n", arr1[i]);
        }
    }
    MPI_Finalize();
    return 0;
}