#include "stdio.h"

#define MATRIX_SIZE 3

void initMatrix(int matrix[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int result[][MATRIX_SIZE], int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main()
{
    int matrixA[MATRIX_SIZE][MATRIX_SIZE], matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int result[MATRIX_SIZE][MATRIX_SIZE];

    printf("Enter first matrix values:\n");
    initMatrix(matrixA);

    printf("Enter second matrix values:\n");
    initMatrix(matrixB);

    printf("\nFirst matrix:\n");
    printMatrix(matrixA);

    printf("\nSecond matrix:\n");
    printMatrix(matrixB);

    multiplyMatrix(result, matrixA, matrixB);
    printf("\nMultiplication result:\n");
    printMatrix(result);

    return 0;
}
