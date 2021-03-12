#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

struct timeval start, end;

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result)
{

    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrixA[j + i * MATRIX_SIZE] = 2.01 * (i + j);
            matrixB[j + i * MATRIX_SIZE] = 3.01 * (i - j);
            result[j + i * MATRIX_SIZE] = 4.01;
        }
    }
}

void printMatrix(int MATRIX_SIZE, double *matrix)
{
    int i, j;
    if (MATRIX_SIZE <= 5)
    {
        for (i = 0; i < MATRIX_SIZE; i++)
        {
            for (j = 0; j < MATRIX_SIZE; j++)
            {
                printf("%f \t", matrix[j + i * MATRIX_SIZE]);
            }
            printf("\n");
        }
    }
}

extern void sample_start()
{
    gettimeofday(&start, NULL);
}

extern void sample_stop()
{
    gettimeofday(&end, NULL);
}

extern void sample_end()
{
    printf("Execution time: %ld microsec\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}
