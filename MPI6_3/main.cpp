#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//task6_3

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        int matrix [3][3]={1,2,3,0,4,5,0,0,6};
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++)
                cout<<matrix[i][j];
            printf("\n");
        }
        MPI_Datatype triangleType;
        int lengths[3]={3,2,1};
        int displacements[3]={0,4,8};
        MPI_Type_indexed(3,lengths,displacements,MPI_INT,&triangleType);
        MPI_Type_commit(&triangleType);
        for (int i = 1; i < size; i++)
            MPI_Send(matrix,1,triangleType,i,0,MPI_COMM_WORLD);
    }
    else{
        int buffer[6];
        MPI_Recv(&buffer,6,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        cout<<"In process "<<rank;
        printf("\n");
        for (int i = 0; i < 6; i++)
            cout<<buffer[i]<<",";
        printf("\n");
    }
    MPI_Finalize();
}
