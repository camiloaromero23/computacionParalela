/*
UNIVERSIDAD SERGIO ARBOLEDA
ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES

AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co

12/03/2021
*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

struct timeval start, end;

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB)
{

  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      matrixA[j + i * MATRIX_SIZE] = 2.01 * (i + j);
      matrixB[j + i * MATRIX_SIZE] = 3.01 * (i - j);
    }
  }
}

void printMatrix(int MATRIX_SIZE, double *matrix, char *matrixName)
{
  int i, j;
  if (MATRIX_SIZE <= 5)
  {
    printf("\n%s\n", matrixName);
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
  printf("\nExecution time: %ld microsec\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}
