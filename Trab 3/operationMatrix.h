#ifndef OPERATIONMATRIX
#define OPERATIONMATRIX

void printMatrix(float matrix[2][2]);
void sumMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);
void subtractionMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);
void multipleMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]);
void sumMatrixPerScalar(float matrix[2][2], int scalar);
void subtractionMatrixPerScalar(float matrix[2][2], int scalar);
void multipleMatrixPerScalar(float matrix[2][2], int scalar);
void transposed(float matrix[2][2]);
void determinant(float matrix[2][2]);

#endif