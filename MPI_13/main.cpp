#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task13

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;int globalA[16];int globalB[16];int globalC[16];int localA[4];int localB[4];int localC[4];
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == root) {
        for (int i = 0; i < 16; i++)
            globalA[i] = rand() % 100;
        for (int i = 0; i < 4; i++)
        {
            for (int k = i; k < 16; k += 4)
                std::cout << globalA[k] << " ";
            std::cout << std::endl;
        }
        std::cout << "\n" << std::endl;
        for (int i = 0; i < 16; i++)
            globalB[i] = rand() % 100;
        for (int i = 0; i < 4; i++)
        {
            for (int k = i; k < 16; k += 4)
                std::cout << globalB[k] << " ";
            std::cout << std::endl;
        }
    }
    std::cout << "\n";
    MPI_Scatter(globalA, 4, MPI_INT,localA, 4, MPI_INT,root, MPI_COMM_WORLD);
    MPI_Scatter(globalB, 4, MPI_INT,localB, 4, MPI_INT,root, MPI_COMM_WORLD);
    std::cout << "proc num = " << rank << std::endl;
    std::cout << "local vector A " << std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << localA[i] << " ";
    std::cout << "\nlocal vector B " << std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << localB[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        localC[i] = localA[i] * localB[i];
    MPI_Gather(localC, 4, MPI_INT,globalC, 4, MPI_INT,root, MPI_COMM_WORLD);
    if (rank == root)
    {
        std::cout << "RESULT" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            for (int k = i; k < 16; k += 4)
                std::cout << globalC[k] << " ";
            std::cout <<  std::endl;
        }
        std::cout << std::endl;
    }
    MPI_Finalize();
    return 0;
}
