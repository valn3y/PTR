#include <stdio.h>
#include "operationMatrix.h"

void printMatrix(float matrix[2][2]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("Resultado [%d][%d]: %f\n", i , j, matrix[i][j]);
		}
	}
}

void indentityMatrix(int rows, int columns){
	float matrixResult[rows][columns];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(i == j){
				matrixResult[i][j] = 1;
			} else {
				matrixResult[i][j] = 0;
			}
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

void sumMatrixPerScalar(float matrix){
	
}

void subtractionMatrixPerScalar(float matrix){

}

void multipleMatrixPerScalar(float matrix){

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