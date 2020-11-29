#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//task6_4
using namespace std;
int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int position=0; char buffer[200];
    if (rank == 0) {
        int intnums[10]={0,1,2,3,4,5,6,7,8,9};
        double doublenums[8]={0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
        MPI_Pack(&intnums,10,MPI_INT,buffer,200,&position,MPI_COMM_WORLD);
        MPI_Pack(&doublenums,8,MPI_DOUBLE,buffer,200,&position,MPI_COMM_WORLD);
        for (int i = 1; i < size; i++)
            MPI_Send(buffer,position,MPI_PACKED,i,0,MPI_COMM_WORLD);
    }
    else{
        int recvbuffer[200];int recvintnums[10];int recvdoublnums[8];
        MPI_Recv(recvbuffer,200,MPI_PACKED,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int unpackPosition = 0;
        MPI_Unpack(recvbuffer,200,&unpackPosition,recvintnums,10,MPI_INT,MPI_COMM_WORLD);
        MPI_Unpack(recvbuffer,200,&unpackPosition,recvdoublnums,8,MPI_DOUBLE,MPI_COMM_WORLD);
        cout<<"In process "<<rank;
        printf("\n");
        cout<<"Ints "<<"\n";
        for (int i = 0; i < 10; i++)
            cout<<recvintnums[i]<<",";
        printf("\n");
        cout<<"Doubles "<<"\n";
        for (int i = 0; i < 8; i++)
            cout<<recvdoublnums[i]<<",";
        printf("\n");
    }
    MPI_Finalize();
}
