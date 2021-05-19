#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "dstring.h"

// Printa uma variavel matrix
void matrix_print(Matrix mat) {
	printf("%s\n", dstring_base(mat.name));
	for (int i = 0; i < mat.m; i++) {
		printf("\n");
		for (int j = 0; j < mat.n; j++) {
			if (j == 0) {
				printf("| ");
				printf("%4.2f ", mat.values[i][j]);
			} 
			else if (j == mat.n - 1) {
				printf("%4.2f ", mat.values[i][j]);
				printf("|");
			} 
			else {
				printf("%4.2f ", mat.values[i][j]);
			}
		}
	}
	printf("\n\n");
}



// Cria matriz de zeros. Também é utilizada como intermédio para inicializar uma matriz.
Matrix matrix_zeros(dstring name, int m, int n) {
	Matrix mat;
	if (m <= 0 || n <= 0) {
		printf("tamanho de matriz inválido\n");
		m = 1;
		n = 1;
	}

	mat.name = name;
	mat.m = m;
	mat.n = n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat.values[i][j] = 0;

	return mat;
}

// Cria matriz a partir de um vetor de valores
// Matrix mat = create_matrix(N$("M1"), 2, 2, {4.5, 3, 2, 1.25 })
Matrix create_matrix(dstring name, int m, int n, double elements[N_MAX * M_MAX]) {
	Matrix mat = matrix_zeros(name, m, n);
	int el = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat.values[i][j] = elements[el];
			el += 1;
		}
	}

	return mat;
}

// Soma de duas Matrizes
Matrix matrix_add(Matrix mat1, Matrix mat2) {
	Matrix mat3 = matrix_zeros(dstring_new("Matriz Resultante:"), mat1.m, mat1.n);
	if (mat1.m != mat2.m || mat1.n != mat2.n) {
		printf("Operacao de soma nao pode ser realizada. Tamanhos incompativeis.\n");
		printf("Retornando matrix de zeros das dimensões de mat1");
		return mat3;
	} 
	else {
		for (int i = 0; i < mat1.m; i++)
			for (int j = 0; j < mat1.n; j++)
				mat3.values[i][j] = mat1.values[i][j] + mat2.values[i][j];
	}
	return mat3;
}

// Subtração de duas matrizes
Matrix matrix_sub(Matrix mat1, Matrix mat2) {
	Matrix mat3 = matrix_zeros(N$("Matriz Resultante:"), mat1.m, mat1.n);
	if (mat1.m != mat2.m || mat1.n != mat2.n) {
		printf("Operacao de subtracao nao pode ser realizada. Tamanhos incompativeis.\n");
		printf("Retornando matrix de zeros das dimensões de mat1");
		return mat3;
	} 
    else {
		for (int i = 0; i < mat1.m; i++)
			for (int j = 0; j < mat1.n; j++)
				mat3.values[i][j] = mat1.values[i][j] - mat2.values[i][j];
	}
	return mat3;
}

// Multiplicação de duas matrizes.
Matrix matrix_mult(Matrix mat1, Matrix mat2) {
	Matrix mat3 = matrix_zeros(dstring_new("Matrix Resultante:"), mat1.m, mat2.n);
	if (mat1.n != mat2.m) {
		printf("Operacao de multiplicacao nao pode ser realizada. Tamanhos incompativeis.\n");
		printf("Retornando matrix de zeros das dimensões linhas de mat1 e colunas de mat2.");
		return mat3;
	} 
    else {
		double sum = 0;
		for (int c = 0; c < mat1.m; c++) { // 1o loop - linhas da 1a matriz
			for (int d = 0; d < mat2.n; d++) { // 2o loop - colunas da 2a matriz
				for (int k = 0; k < mat2.m; k++) { // 3o loop - linhas da 2a matriz
					sum = sum + mat1.values[c][k] * mat2.values[k][d];
				}
				mat3.values[c][d] = sum;
				sum = 0;
			}
		}
	}
	return mat3;
}


// Matriz transposta (linhas tornam-se colunas, colunas tornam-se linhas)
Matrix matrix_transp(Matrix mat) {
	Matrix res = matrix_zeros(dstring_new("Matrix Resultante:"), mat.n, mat.m);
	int i, j = 0;
	for (i = 0; i < mat.m; i++) 
		for (j = 0; j < mat.n; j++) 
			res.values[j][i] = mat.values[i][j];

	return res;
}

// Multiplicação por escalar
Matrix matrix_scalar_mult(double scalar, Matrix mat) {
	for (int i = 0; i < mat.m; i++) 
		for (int j = 0; i < mat.n; i++) 
			mat.values[i][j] = mat.values[i][j] * scalar;

	return mat;

}

// "Matriz identidade", cria uma diagonal de 1's em uma matriz de zeros mxn
Matrix matrix_identity(dstring name, int m, int n) {
	Matrix id = matrix_zeros(name, m, n);
	for (int i = 0; i < id.m; i++) 
		for (int j = 0; j < id.n; j++) 
			if (i == j) id.values[i][j] = 1;
	
	return id;

}