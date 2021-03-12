#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "matrix.h"

#define SIZE (1024 * 1024 * 64 * 3)
static double MEM_CHUNK[SIZE];

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "%s <matrix size> <number of threads>\n", argv[0]);
        return -1;
    }

    int MATRIX_SIZE = atoi(argv[1]);
    argc--;
    argv++;

    int NUM_THREADS = atoi(argv[1]);
    argc--;
    argv++;

    double *matrixA, *matrixB, *result;

    matrixA = MEM_CHUNK;
    matrixB = matrixA + MATRIX_SIZE * MATRIX_SIZE;
    result = matrixB + MATRIX_SIZE * MATRIX_SIZE;

    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {

#pragma omp master
        initMatrix(MATRIX_SIZE, matrixA, matrixB, result);

        // if (MATRIX_SIZE <= 5)
        // printf("Matrix A\n");
        // printMatrix(MATRIX_SIZE, matrixA);
        // if (MATRIX_SIZE <= 5)
        // printf("Matrix B\n");
        // printMatrix(MATRIX_SIZE, matrixB);
        sample_start();

        multiplyMatrix(MATRIX_SIZE, matrixA, matrixB, result);
        // if (MATRIX_SIZE <= 5)
        // printf("Result matrix\n");

        // printMatrix(MATRIX_SIZE, result);
        sample_stop();
        sample_end();
    }
    return 0;
}
