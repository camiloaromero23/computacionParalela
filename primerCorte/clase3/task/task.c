#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char **argv)
{
    int MATRIX_SIZE = (int)atof(argv[1]);
    int RANDOM_RANGE = (int)atof(argv[2]);
    int matrixA[MATRIX_SIZE][MATRIX_SIZE], matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int result[MATRIX_SIZE][MATRIX_SIZE];

    setRand();
    initMatrix(MATRIX_SIZE, RANDOM_RANGE, matrixA);
    initMatrix(MATRIX_SIZE, RANDOM_RANGE, matrixB);

    printf("\nFirst matrix:\n");
    printMatrix(MATRIX_SIZE, matrixA, false);

    printf("\nSecond matrix:\n");
    printMatrix(MATRIX_SIZE, matrixB, false);

    multiplyMatrix(MATRIX_SIZE, result, matrixA, matrixB);
    printf("\n\x1B[32mMultiplication result:\n");
    printMatrix(MATRIX_SIZE, result, true);

    return 0;
}
