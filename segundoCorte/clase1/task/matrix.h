#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result);

void printMatrix(int MATRIX_SIZE, double *matrix);

void multiplyMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result);

extern void sample_start();

extern void sample_stop();

extern void sample_end();

#endif
