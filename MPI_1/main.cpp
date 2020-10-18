#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"

//task 1
int ProcNum;
int ProcRank;

int main(int argc, char *argv[]){
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);

    printf("Hello, World!\n", ProcRank);

    MPI_Finalize();
}
