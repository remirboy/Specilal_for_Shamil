#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>


//task 14
using namespace std;

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;int globalA[16];int x[4] = { 1 , 2, 3, 4 };int localA[4];int globalMult[16];
    int localMult[1] = { 0 };
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == root) {
        for (int i = 0; i < 16; i++)
            globalA[i] = rand() % 100;
        for (int i = 0; i < 16; i++)
            cout << globalA[i] << " ";
        cout << "\n" << endl;
        for (int i = 0; i < 16; i += 4)
        {
            for (int k = i; k < i + 4; k++)
                cout << globalA[k] << " ";
            cout << endl;
        }
        cout << "\nVector x:" << endl;
        for (int i = 0; i < 4; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    MPI_Scatter(globalA, 4, MPI_INT,localA, 4, MPI_INT,root, MPI_COMM_WORLD);
    MPI_Bcast(x, 4, MPI_INT, root, MPI_COMM_WORLD);
    cout << "proc num = " << rank <<" \n";
    cout << "local vector A: \n";
    for (int i = 0; i < 4; i++)
        cout << localA[i] << " ";
    cout << "\nlocal vector X: \n";
    for (int i = 0; i < 4; i++)
        cout << x[i] << " ";
    cout << " \n";
    for (int i = 0; i < 4; i++)
        localMult[0] += localA[i] * x[i];
    MPI_Gather(localMult, 1, MPI_INT,globalMult, 1, MPI_INT,root, MPI_COMM_WORLD);
    if (rank == root)
    {
        cout << "\nRESULT\n";
        for (int i = 0; i < 4; i++)
            cout << globalMult[i] << " ";
    }
    MPI_Finalize();
    return 0;
}