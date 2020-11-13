
#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task12

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;int global[16];int local[4];int globalMax = -1;int localSum = 0;
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == root) {
        for (int i = 0; i < 16; i++)
            global[i] = rand() % 100;
        for (int i = 0; i < 4; i++)
        {
            for (int k = i; k < 16; k += 4)
                std::cout << global[k] << " ";
            std::cout << std::endl;
        }
    }
    std::cout << "\n";
    MPI_Scatter(global, 4, MPI_INT, local, 4, MPI_INT, root, MPI_COMM_WORLD);
    std::cout << "proc num = " << rank << std::endl;
    std::cout << "local vector " << std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << local[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        localSum += abs(local[i]);
    std::cout << "local sum =" << localSum << std::endl;
    MPI_Reduce(&localSum, &globalMax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if (rank == root)
        std::cout << "MAX = " << globalMax << std::endl;
    MPI_Finalize();
    return 0;
}

