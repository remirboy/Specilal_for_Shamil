#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task5_1
using namespace std;

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank;
    int arr[12];
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    if (rank == 0) {
        cout << "Initialized array: \n";
        for (int i = 0; i < 12; i++) {
            arr[i] = rand() % 100;
            cout << arr[i] << " ";
        }
        cout << "\n";
        int block = 12 / numOfProcess;
        int k = block;
        int* newarr = new int[block];
        int* recvarr = new int[block];
        int* recvarr2 = new int[block];
        int* recvarr3 = new int[block];
        int *finalArray = new int[12];
        printf("Number of process - %d and total - %d\n", rank, numOfProcess);
        for (int i = 0; i < block; i++)
            cout << arr[i] << endl;
        for (int i = 1; i < numOfProcess; i++)
        {
            for (int j = 0; j < block; j++)
            {
                if (k < 12)
                    newarr[j] = arr[k];
                else
                    newarr[j] = 0;
                k++;
            }
            MPI_Send(newarr, block, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
        MPI_Recv(recvarr, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(recvarr2, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(recvarr3, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
        cout << "\nReceived array :\n";
        for (int i = 0; i < 3; i++)
            cout << arr[i] << " ";
        for (int i = 0; i < 3; i++)
            cout << recvarr[i] << " ";
        for (int i = 0; i < 3; i++)
            cout << recvarr2[i] << " ";
        for (int i = 0; i < 3; i++)
            cout << recvarr3[i] << " ";
    }
    if (rank != 0) {
        int count;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);
        int* arr1 = new int[count];
        printf("Number of process - %d and total - %d\n", rank, numOfProcess);
        MPI_Recv(arr1, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        for (int i = 0; i < count; i++)
            printf("%d\n", arr1[i]);
        MPI_Send(arr1, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}

