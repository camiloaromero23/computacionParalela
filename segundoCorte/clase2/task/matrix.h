/*
UNIVERSIDAD SERGIO ARBOLEDA
ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES

AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co

12/03/2021
*/

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB);

void printMatrix(int MATRIX_SIZE, double *matrix, char *matrixName);

extern void sample_start();

extern void sample_stop();

extern void sample_end();

#endif
