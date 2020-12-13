#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <algorithm>

//task8_3
using namespace std;

int main(int argc, char* argv[]) {
    int nump, rank, n, localn;
    int* data, recdata[100], recdata2[100];
    int* temp;
    int ierr, i;
    int root_process;
    int sendcounts;
    MPI_Status status;

    ierr = MPI_Init(&argc, &argv);
    root_process = 0;
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &nump);

    if (rank == root_process) {
        n = 4;
        int avgn = n / nump;
        localn = avgn;

        data = (int*)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++) {
            data[i] = rand() % 100;
        }
        printf("array data is:");
        for (i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
else {
        data = NULL;
    }
    ierr = MPI_Bcast(&localn, 1, MPI_INT, 0, MPI_COMM_WORLD);
    ierr = MPI_Scatter(data, localn, MPI_INT, &recdata, 100, MPI_INT, 0, MPI_COMM_WORLD);
    printf("%d:received data:", rank);
    for (i = 0; i < localn; i++) {
        printf("%d ", recdata[i]);
    }
    printf("\n");
    sort(recdata, recdata + localn);

    int oddrank, evenrank;

    if (rank % 2 == 0) {
        oddrank = rank - 1;
        evenrank = rank + 1;
    }
else {
        oddrank = rank + 1;
        evenrank = rank - 1;
    }
    if (oddrank == -1 || oddrank == nump) {
        oddrank = MPI_PROC_NULL;
    }
    if (evenrank == -1 || evenrank == nump) {
        evenrank = MPI_PROC_NULL;
    }

    int p;
    for (p = 0; p < nump - 1; p++) {
        if (p % 2 == 1) {
            MPI_Sendrecv(recdata, localn, MPI_INT, oddrank, 1, recdata2,
            localn, MPI_INT, oddrank, 1, MPI_COMM_WORLD, &status);
        }
else {
            MPI_Sendrecv(recdata, localn, MPI_INT, evenrank, 1, recdata2,
            localn, MPI_INT, evenrank, 1, MPI_COMM_WORLD, &status);
        }

        temp = (int*)malloc(localn * sizeof(int));
        for (i = 0; i < localn; i++) {
            temp[i] = recdata[i];
        }
        if (status.MPI_SOURCE == MPI_PROC_NULL) continue;
else if (rank < status.MPI_SOURCE) {
            int i, j, k;
            for (i = j = k = 0; k < localn; k++) {
                if (j == localn || (i < localn && temp[i] < recdata2[j])) {
                    recdata[k] = temp[i++];
                }
else {
                    recdata[k] = recdata2[j++];
                }
            }
        }
else {
            int i, j, k;
            for (i = j = k = localn - 1; k >= 0; k--) {
                if (j == -1 || (i >= 0 && temp[i] >= recdata2[j])) {
                    recdata[k] = temp[i--];
                }
else {
                    recdata[k] = recdata2[j--];
                }
            }
        }
    }

    ierr = MPI_Gather(recdata, localn, MPI_INT, data, localn, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == root_process) {
        printf("Sorted Array:");
        for (i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    ierr = MPI_Finalize();

}