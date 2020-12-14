#include <iostream>
#include <mpi.h>
#include <stdio.h>
#include <math.h>

//task8_2
int main(int argc, char** argv) {

    int rank, size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int sum = rank;
    int a, dest, source;
    for (int i = 1; i < size - 1; i *= 2) {
        a = 0;
        dest = rank + i;
        source = rank - i;
        if (dest > size - 1) dest = MPI_PROC_NULL;
        if (source < 0) source = MPI_PROC_NULL;

        MPI_Send(&sum, 1, MPI_INT, dest, i, MPI_COMM_WORLD);
        MPI_Recv(&a, 1, MPI_INT, source, i, MPI_COMM_WORLD, &status);
        sum = sum + a;
    }
    printf("Rank = %d sum = %d \n", rank, sum);

    MPI_Finalize();
}
