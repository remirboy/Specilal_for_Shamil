#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>


//task8

int main(int argc, char* argv[]) {
    int processId, size;
    srand(time(0));
    int n=10;
    int A[n][n];int B[n][n];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
    MPI_Status status;
    if (processId == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = rand() % 100;
                B[i][j] = rand() % 100;
            }
        }
        printf("Number of process - %d and total - %d\n", processId, size);
        int block = 12 / size + 1; int k = 0;
        int H[n][n];int H2[n][n];int H3[n][n];
        for (int i = 1; i < size; i++) {
            int newA [block][block];
            int newB [block][block];
            for (int j = 0; j < block; j++) {
                if (k <= 11) {
                    newA[j][j] = A[k][k];
                    newB[j][j] = B[k][k];
                    printf("A = %i and B = %i\n", newA[j][j], newB[j][j]);
                }
                else {
                    newA[j][j] = 0;
                    newB[j][j] = 0;
                }
                k++;
            }
            printf("\n");
            MPI_Send(newA, block, MPI_INT, i, 1, MPI_COMM_WORLD);
            MPI_Send(newB, block, MPI_INT, i, 1, MPI_COMM_WORLD);
            MPI_Recv(H, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(H2, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(H3, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(A, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(B, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
            for (int i = 0; i < block; i++)
                for (int j=0; j < block; j++){
                    std::cout<<"H["<<i<<"]["<<j<<"]="<<H[i][j];
                    std::cout<<"H2["<<i<<"]["<<j<<"]="<<H2[i][j];
                    std::cout<<"H3["<<i<<"]["<<j<<"]="<<H3[i][j];
                }
        }
    }
    if (processId != 0) {
        int count;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);
        int A[n][n];int B[n][n];
        int H[n][n];int H2[n][n];int H3[n][n];
        int c;
        printf("Number of process - %d and total - %d\n", processId, size);
        MPI_Recv(A, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(B, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                H[i][j] = 0;
                for (int t = 0; t < n; t++){
                    H[i][j] += A[i][t] * B[t][j];
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                H2[i][j] = A[i][j] * B[i][j];
            }
        }

        for (int i=0;i< n;i++)
            for (int j=0;j< n;j++)
                H3[j][i]=A[i][j];

        MPI_Send(H, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
        MPI_Send(H2, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
        MPI_Send(H3, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
