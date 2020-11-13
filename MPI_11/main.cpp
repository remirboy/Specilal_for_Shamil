#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task11
int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;int globalX[12];int globalY[12];int localX[3];int localY[3];int globalSum = 0;int localSum = 0;
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == root) {
        for (int i = 0; i < 12; i++) {
            globalX[i] = rand() % 100; globalY[i] = rand() % 100;
        }
        std::cout << "global X= ";
        for (int i = 0; i < 12; i++)
            std::cout << globalX[i] << " ";
        std::cout << "\nglobal Y= ";
        for (int i = 0; i < 12; i++)
            std::cout << globalY[i] << " ";
    }
    MPI_Scatter(globalX, 3, MPI_INT, localX, 3, MPI_INT, root, MPI_COMM_WORLD);
    MPI_Scatter(globalY, 3, MPI_INT, localY, 3, MPI_INT, root, MPI_COMM_WORLD);
    std::cout << "proc num = " << rank << std::endl;
    std::cout << "X= ";
    for (int i = 0; i < 3; i++)
        std::cout<< localX[i]<<" ";
    std::cout << "\nY= ";
    for (int i = 0; i < 3; i++)
        std::cout<< localY[i]<<" ";
    for (int i = 0; i < 3; i++)
        localSum += localX[i] * localY[i];
    std::cout << "\nlocal sum =" << localSum << std::endl;
    MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == root)
        std::cout << "Sum = " << globalSum << std::endl;
    MPI_Finalize();
    return 0;
}