#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"
#include "matrix.h"

void setRand()
{
    srand(time(NULL) * clock());
}

void initMatrix(size_t MATRIX_SIZE, int randomRange, int matrix[][MATRIX_SIZE])
{
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % (randomRange + 1);
        }
    }
}

void printMatrix(size_t MATRIX_SIZE, int matrix[][MATRIX_SIZE], bool printGreen)
{
    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            if (printGreen)
            {
                printf("\x1B[32m%d\t", matrix[i][j]);
            }
            else
            {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void multiplyMatrix(size_t MATRIX_SIZE, int result[][MATRIX_SIZE], int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE])
{
    int i, j, k;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
