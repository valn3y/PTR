#include <stdio.h>
#include <stdlib.h>
#include "operationMatrix.h"

int main(){
	printf("----Trabalho 3 - PTR----\n");
	printf("Dupla: Josias Ben e Valney Marinho\n");
	printf("\n");

	/*
	int a, b;
	printf("Preencha o número de linhas da PRIMEIRA matriz: ");
	scanf("%d", &a);
	printf("Preencha o número de colunas da PRIMEIRA matriz: ");
	scanf("%d", &b);

	int c,d;
	printf("Preencha o número de linhas da SEGUNDA matriz: ");
	scanf("%d", &c);
	printf("Preencha o número de colunas da SEGUNDA matriz: ");
	scanf("%d", &d);
	*/

	float matrixA[2][2] = {
		{0.23, 0.96},
		{0.16, 0.00}	
	};
	float matrixB[2][2] = {
		{0.77, 1.04},
		{2.84, 4.00}	
	};

	printf("------Matriz A-----\n");
	printMatrix(matrixA);
	printf("\n");
	printf("------Matriz B-----\n");
	printMatrix(matrixB);
	printf("\n");

	sumMatrixPerMatrix(matrixA, matrixB);
	subtractionMatrixPerMatrix(matrixA, matrixB);
	multipleMatrixPerMatrix(matrixA, matrixB);
	printf("-----OPERAÇÃO MATRIZ A------\n");
	transposed(matrixA);
	printf("-----OPERAÇÃO MATRIZ B------\n");
	transposed(matrixB);

	// printf("Matriz B: %f\n", MatrizB );

	// Soma, subtração e multiplicção de uma matriz por escalar.
	// Determinante de uma matriz quadrada.
	// Inversão de uma matriz

	return 0;
}