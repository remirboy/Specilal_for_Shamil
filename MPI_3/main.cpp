#include <iostream>
#include "stdio.h"
#include "mpi.h"
#include "stdlib.h"
#include "math.h"

//task 3
int ProcNum;
int ProcRank;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Status status;
    int a[10]= {};
    if (ProcRank==0){
        srand(time(0));
        for (int i = 0; i < 10; i++)
            a[i]=rand() % 100;
        MPI_Send(a,10,MPI_INT,1,1,MPI_COMM_WORLD);
    }
    if (ProcRank==1){
        MPI_Recv(a,10,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        for (int i = 0; i < 10; i++) {
            std::cout<<"a["<<i<<"]="<<a[i];
        }
    }
    MPI_Finalize();
}
