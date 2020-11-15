#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//task5_2

using namespace std;

#define N 4 // размер
#define procN 2 // количество проц

int main(int argc, char** argv) {
    double* gA = nullptr; // указатель на массив
    int rank, size, root = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (size != procN * procN) {
        if (rank == 0) fprintf(stderr, "%s: Only works with np = %d.\n", argv[0], procN * procN);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
// печать изначальной матрицы
    if (rank == root) {
        gA = new double[N * N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                gA[j * N + i] = rand() % 100;
            }
        }
        printf("A is:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << gA[j * N + i] << " ";
            }
            printf("\n");
        }
    }
    double* lA = new double[N / procN * N / procN];
    int sizes[2] = { N, N };
    int subsizes[2] = { N / procN, N / procN };
    int starts[2] = { 0,0 };
    MPI_Datatype type, subarrtype;
    MPI_Type_create_subarray(2, sizes, subsizes, starts, MPI_ORDER_C, MPI_DOUBLE, &type);
    MPI_Type_create_resized(type, 0, N / procN * sizeof(double), &subarrtype);
    MPI_Type_commit(&subarrtype);
// Вычисляем количество отправленных блоков и расстояние между ними
    int sendcounts[procN * procN];
    int displs[procN * procN];
    if (rank == root) {
        for (int i = 0; i < procN * procN; i++) {
            sendcounts[i] = 1;
        }
        int disp = 0;
        for (int i = 0; i < procN; i++) {
            for (int j = 0; j < procN; j++) {
                displs[i * procN + j] = disp;
                disp += 1;
            }
            disp += ((N / procN) - 1) * procN;
        }
    }
// Рассылаем во все процессы
    MPI_Scatterv(gA, sendcounts, displs, subarrtype, lA,N * N / (procN * procN), MPI_DOUBLE,0, MPI_COMM_WORLD);
// Печать локальных матриц на каждом процессе
    for (int p = 0; p < size; p++) {
        if (rank == p) {
            printf("Local part of A matrix %d:\n", rank);
            for (int i = 0; i < N / procN; i++) {
                for (int j = 0; j < N / procN; j++) {
                    cout << lA[j * N / procN + i] << " ";
                }
                printf("\n");
            }
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }
    MPI_Barrier(MPI_COMM_WORLD);
// Запись в локальные процессы
    for (int i = 0; i < N / procN; i++) {
        for (int j = 0; j < N / procN; j++) {
            lA[j * N / procN + i] = rank;
        }
    }
    MPI_Type_free(&subarrtype);
    if (rank == root) {
        delete gA;
    }
    delete lA;
    MPI_Finalize();
    return 0;
}