#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE (1024 * 1024 * 64 * 3)
static double MEM_CHUNK[SIZE];

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result);

void printMatrix(int MATRIX_SIZE, double *matrix);

void multiplyMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result);

int main(int argc, char **argv)
{
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

        // printf("Matrix A\n");
        // printMatrix(MATRIX_SIZE, matrixA);
        // printf("Matrix B\n");
        // printMatrix(MATRIX_SIZE, matrixB);

        multiplyMatrix(MATRIX_SIZE, matrixA, matrixB, result);
        // printf("Result matrix\n");

        // printMatrix(MATRIX_SIZE, result);
    }
    return 0;
}

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result)
{
    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrixA[j + i * MATRIX_SIZE] = 3.1 * (j + i);
            matrixB[j + i * MATRIX_SIZE] = 4.1 * (j + i);
            result[j + i * MATRIX_SIZE] = 1.0;
        }
    }
}

void printMatrix(int MATRIX_SIZE, double *matrix)
{
    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%f \t", matrix[j + i * MATRIX_SIZE]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result)
{
    int i, j, k;
#pragma omp for
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            double *auxMatrixA, *auxMatrixB;
            double sum = 0.0;

            auxMatrixA = matrixA + (i * MATRIX_SIZE);
            auxMatrixB = matrixB + j;

            for (k = 0; k < MATRIX_SIZE; k++, auxMatrixA++, auxMatrixB += MATRIX_SIZE)
            {
                sum += (*auxMatrixA * *auxMatrixB);
            }
            result[i * MATRIX_SIZE + j] = sum;
        }
    }
}
