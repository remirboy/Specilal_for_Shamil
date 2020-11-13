#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task10

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;
    int global[12];
    int local[3];
    int globalSum = 0;
    int localSum = 0;
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == root) {
        for (int i = 0; i < 12; i++) {
            global[i] = rand() % 100;
            std::cout << global[i] << " ";
        }
    }
    MPI_Scatter(global, 3, MPI_INT, local, 3, MPI_INT, root, MPI_COMM_WORLD);
    std::cout << "proc num = " << rank << std::endl;
    for (int i = 0; i < 3; i++)
        localSum += abs(local[i]);
    std::cout << "local sum =" << localSum << std::endl;
    MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0,
               MPI_COMM_WORLD);
    if (rank == root)
        std::cout << "Sum = " << globalSum << std::endl;
    MPI_Finalize();
    return 0;
}