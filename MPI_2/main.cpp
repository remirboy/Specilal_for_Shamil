#include <iostream>
#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"

//task 2
int ProcNum;
int ProcRank;

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    std::cout <<"Process:"<<ProcRank<<" All:"<<ProcNum<<"\n";
    MPI_Finalize();
}
