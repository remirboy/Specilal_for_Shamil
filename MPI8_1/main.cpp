#include <iostream>
#include <mpi.h>
#include <stdio.h>
#include <math.h>

//task8_1

using namespace std;
int main(int argc, char** argv) {
    int rank, size;
    float globaldata[12], localdata[3];
    float localAverage = 0, globalAverage = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size < 2)
    {
        printf("Please run this application with at least 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    if (rank == 0)
    {
        cout << "Global array is \n";
        for (int i = 0; i < 12; i++)
        {
            globaldata[i] = float(rand() % 100);
            cout <<  globaldata[i] <<  " ";
        }
    }
    MPI_Scatter(globaldata, 3, MPI_INT, &localdata, 3, MPI_FLOAT, 0, MPI_COMM_WORLD);
    cout <<  "rank " <<  rank <<  " has local data:\n";
    for (int i = 0; i < 3; i++)
    {
        cout <<  localdata[i] <<  " ";
        localAverage += localdata[i] / 12;
    }
    MPI_Reduce(&localAverage, &globalAverage, 1, MPI_FLOAT, MPI_SUM, 0,
               MPI_COMM_WORLD);
    cout << " and local average = " << localAverage;
    if (rank == 0)
    {
        cout << "\nGlobal average is " << globalAverage;
    }
    MPI_Finalize();
    return 0;
}