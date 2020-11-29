#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//task6_2

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int matrix [8][8];
    struct Rows{
        int rows[16];
    };

    MPI_Datatype pareOfType;
    int lengths[1]={16};
    const MPI_Aint displacements[1]={0};
    MPI_Datatype datatype[1]={MPI_INT};
    MPI_Type_create_struct(1,lengths,displacements,datatype,&pareOfType);
    MPI_Type_commit(&pareOfType);

    if (rank == 0) {
        for (int i = 0; i < 64; i++) {
                matrix[i/8][i%8] = rand()%100;
        }
        for (int i = 0; i < 4; i++) {
            Rows pair;
            for (int j=0;j<8;j++)
                pair.rows[j]=matrix[i][j];
            for (int j=0;j<8;j++)
                pair.rows[8+j]=matrix[i+4][j];
            MPI_Send(&pair,1,pareOfType,i+1,0,MPI_COMM_WORLD);
        }
    }
    else {
        Rows recv;
        MPI_Recv(&recv,1,pareOfType,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        cout<<"In process "<<rank;
        for(int i=0;i<2;i++)
            for(int j=0;j<8;j++)
                cout<< recv.rows[8*i+j];
            printf("\n");
    }
    MPI_Finalize();
}
