#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//task6_1

using namespace std;

#define n 8
#define m 4

int main(int argc, char** argv) {
    int matrix [n][n];
    int rank;
    int size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    struct Rows{
        int rows[16];
    };
// печать изначальной матрицы
    if (rank == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand()%100;
            }
        }
        printf("A is:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j]  << " ";
            }
            printf("\n");
        }
        MPI_Datatype type;
        MPI_Type_vector(4,8,16,MPI_INT,&type);
        MPI_Type_commit(&type);
        MPI_Send(&matrix[1][0],1,type,1,0,MPI_COMM_WORLD);
        MPI_Send(&matrix[0][0],1,type,2,0,MPI_COMM_WORLD);
    }
    else if(rank==1){
        int received[32];
        MPI_Recv(received,32,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        cout << "In process "<< rank;
        printf("\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << received[8*i+j]  << " ";
            }
            printf("\n");
        }
    }
    else if(rank==2) {
            int received[32];
            MPI_Recv(received,32,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            cout << "In process "<< rank;
            printf("\n");
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << received[8*i+j]  << " ";
                }
                printf("\n");
            }
    }
    MPI_Finalize();
}
