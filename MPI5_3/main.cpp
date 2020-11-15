#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>


//task5_3
using namespace std;

int main(int args, char** argvs) {
    srand(time(0));
    int numOfProcess, rank, root = 0;
//массив с рандомными числами которые берут потоки
    int global[4];
//глобальная сумма всех рандомных чисел сюда reduce
    int globalSum = 0;
//рандомное число каждого потока
    int localRandomNum;
    MPI_Init(&args, &argvs);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
//инициализируем массив
    for (int i = 0; i < 4; i++)
        global[i] = rand() % 100;
    if (rank == root)
    {
        cout << "ARRAY OF RANDOM NUMS: \n";
        for (int i = 0; i < 4; i++)
            cout << global[i] << " ";
        cout << "\n";
    }
//каждый поток берет себе рандомное число
    localRandomNum = global[rank];
    cout << "I'm rank " << rank << " and my number = " << localRandomNum << "\n";
//рандомное число каждого о=потока суммируется в globalSum
    MPI_Reduce(&localRandomNum, &globalSum, 1, MPI_INT, MPI_SUM, 0,MPI_COMM_WORLD);
    MPI_Bcast(&globalSum, 1, MPI_INT, root, MPI_COMM_WORLD);
    cout << "I'm rank " << rank << " and my sum = " << globalSum << "\n";
    MPI_Finalize();
    return 0;
}
