#include <stdio.h>
#include "operationMatrix.h"

void printMatrix(float matrix[2][2]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("Resultado [%d][%d]: %f\n", i , j, matrix[i][j]);
		}
	}
}

void sumMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]){
	printf("------------SOMA DE DUAS MATRIZES------------\n");
	float matrixResult[2][2];
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void subtractionMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]) {
	printf("------------SUBTRAÇÃO DE DUAS MATRIZES------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void multipleMatrixPerMatrix(float matrixA[2][2], float matrixB[2][2]) {
	printf("------------MULTIPLICAÇÃO DE DUAS MATRIZES------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			matrixResult[i][j] = 0;
			for(int x = 0; x < 2; x++){
				matrixResult[i][j] += matrixA[i][x] * matrixB[x][j]; 
			}
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void sumMatrixPerScalar(float matrix[2][2], int scalar){
	printf("------------SOMA DE MATRIZ POR ESCALAR------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			matrixResult[i][j] = scalar + matrix[i][j];
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void subtractionMatrixPerScalar(float matrix[2][2], int scalar){
	printf("------------SUBTRAÇÃO DE MATRIZ POR ESCALAR------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			matrixResult[i][j] = scalar - matrix[i][j];
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void multipleMatrixPerScalar(float matrix[2][2], int scalar){
	printf("------------MULTIPLICAÇÃO DE MATRIZ POR ESCALAR------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			matrixResult[i][j] = scalar * matrix[i][j];
		}
	}

	printMatrix(matrixResult);
	printf("\n");
}

void transposed(float matrix[2][2]){
	printf("------------MATRIZ TRANSPOSTA------------\n");
	float matrixResult[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			matrixResult[j][i] = matrix[i][j];
		}
	}
	printMatrix(matrixResult);
	printf("\n");
}

void determinant(float matrix[2][2]){
	printf("------------MATRIZ DETERMINANTE------------\n");
	float result = 1;
	float mult;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			mult = matrix[j][i] / matrix[i][i];
			for (int x = 0; x < 2; x++){
				if(i == j) break;
				matrix[j][x] = matrix[j][x] - matrix[i][x] * mult;
			}
		}
	}
	for(int i = 0; i < 2; i++){
		result = result * matrix[i][i];
	}

	printf("Resultado: %f\n", result);
	printf("\n");
}