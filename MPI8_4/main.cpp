#include <stdio.h>
#include <mpi.h>
#include <math.h>

//task8_4
int main(int argc, char** argv) {

    float a, b, len, ar, br, x0, x1, h, s, r;
    int size, rank, i;
    const int n = 100;

    a = 1.2;
    b = 2;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    len = (b - a) / size;
    ar = a + rank * len;
    br = ar + len;
    x0 = ar;
    h = (br - ar) / n;

    s = 0;
    for (i = 0; i < n; i++){
        if (i == 0 || i == n - 1)
            s = s + (float)(h / 3) * sqrt(1+2*x0*x0-x0*x0*x0);
        if (i%2==0 && i!=0 && i!=n)
            s = s + 2*(float)(h / 3) * sqrt(1+2*x0*x0-x0*x0*x0);
        if (i % 2 == 1)
            s = s + 4*(float)(h / 3) * sqrt(1+2*x0*x0-x0*x0*x0);
        x0 += h;
    }

    MPI_Reduce(&s, &r, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) printf("int=%f\n", r);
    MPI_Finalize();
}