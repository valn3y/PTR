#include <stdio.h>
#include <stdlib.h>
#include "operationMatrix.h"

int main(){
	printf("----Trabalho 3 - PTR----\n");
	printf("Dupla: Josias Ben e Valney Marinho\n");
	printf("\n");

	int scalar = 10;	
	float matrixA[2][2] = {
		{0.23, 0.96},
		{0.16, 0.00}	
	};
	float matrixB[2][2] = {
		{0.77, 1.04},
		{2.84, 4.00}	
	};

	printf("-----MATRIZ A-----\n");
	printMatrix(matrixA);
	printf("\n");
	printf("-----MATRIZ B-----\n");
	printMatrix(matrixB);
	printf("\n");

	sumMatrixPerMatrix(matrixA, matrixB);
	subtractionMatrixPerMatrix(matrixA, matrixB);
	multipleMatrixPerMatrix(matrixA, matrixB);

	printf("-----OPERAÇÃO MATRIZ A------\n");
	transposed(matrixA);
	sumMatrixPerScalar(matrixA, scalar);
	subtractionMatrixPerScalar(matrixA, scalar);
	multipleMatrixPerScalar(matrixA, scalar);
	determinant(matrixA);

	printf("-----OPERAÇÃO MATRIZ B------\n");
	transposed(matrixB);
	sumMatrixPerScalar(matrixB, scalar);
	subtractionMatrixPerScalar(matrixB, scalar);
	multipleMatrixPerScalar(matrixB, scalar);
	determinant(matrixB);

	return 0;
}