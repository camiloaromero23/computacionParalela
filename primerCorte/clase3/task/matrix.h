#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdbool.h>

void setRand();

void initMatrix(size_t MATRIX_SIZE, int randomRange, int matrix[][MATRIX_SIZE]);

void printMatrix(size_t MATRIX_SIZE, int matrix[][MATRIX_SIZE], bool printGreen);

void multiplyMatrix(size_t MATRIX_SIZE, int result[][MATRIX_SIZE], int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE]);

#endif
