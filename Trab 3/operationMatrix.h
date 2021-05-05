#ifndef OPERATIONMATRIX
#define OPERATIONMATRIX

#include <stdlib.h>

void sumMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);
void subtractionMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);
void multipleMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);

void sumMatrixPerScalar(float matrix);
void subtractionMatrixPerScalar(float matrix);
void multipleMatrixScalar(float matrix);

void transposed(float matrix[2][2]);
void printMatrix(float matrix[2][2]);

#endif