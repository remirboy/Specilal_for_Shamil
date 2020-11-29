#include <iostream>
#include <mpi.h>
#include <stdio.h>
#include <math.h>
//task7-1
using namespace std;

int main(int argc, char **argv) {
    int size1 = 10;
    int newGroupOfProcesses[5] = { 8, 3, 9, 1, 6 };
    int rank;int size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    MPI_Group groupFirst;
    MPI_Group groupSecond;
    MPI_Comm_group(MPI_COMM_WORLD, &groupFirst);
    MPI_Group_incl(groupFirst, 5, newGroupOfProcesses, &groupSecond);
    MPI_Comm comm;
    MPI_Comm_create(MPI_COMM_WORLD, groupSecond, &comm);
    int current_rank = -1;int a[size1];
    if (comm != MPI_COMM_NULL)
        MPI_Comm_rank(comm, &current_rank);
    if (current_rank == 0 && comm != MPI_COMM_NULL) {
        for (int i = 0; i < size1; i++)
            a[i] = rand() % 10;
        MPI_Bcast(&a, size1, MPI_INT, 0, comm);
    }

    if (current_rank != -1 && comm != MPI_COMM_NULL) {
        MPI_Bcast(&a, size1, MPI_INT, 0, comm);
        cout << "Номер процесса " << current_rank << " с массивом: " << endl;
        for (int i = 0; i < size1; i++)
            cout << a[i] << " ";
        cout << endl;
        if (current_rank == 4)
            MPI_Send(a, size1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        MPI_Recv(a, size1, MPI_INT, 6, 0, MPI_COMM_WORLD, &status);
        cout << "Результирующий массив " << endl;
        for (int i = 0; i < size1; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    if (comm != MPI_COMM_NULL)
        MPI_Comm_free(&comm);
    MPI_Group_free(&groupSecond);
    MPI_Finalize();
    return 0;
}
