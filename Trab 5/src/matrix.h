#include <stdio.h>
#include "dstring.h"

#ifndef _MATRIX_H
#define _MATRIX_H

#define M_MAX 10 // O numero maximo de linhas que uma matriz pode possuir
#define N_MAX 10 // O numero maximo de colunas que uma matriz pode possuir

// Struct da matriz
typedef struct{
  dstring name;
  int m; // numero de linhas
  int n; // numero de colunas
  double values[M_MAX][N_MAX]; // valores das linhas e colunas
} Matrix;

// Imprime todos os valores da matriz
void matrix_print(Matrix matrix);

// Cria uma matriz recebendo como parâmetros os elementos um dstring nome, 
// nro de linhas e colunas, e um array com os elementos.
Matrix create_matrix(dstring name, int m, int n, double elements[N_MAX*M_MAX]);

// Cria uma matriz de em que todos os elementos são 0.
Matrix matrix_zeros(dstring name, int m, int n);

// Faz a soma de duas matrizes de mesma dimensão.
Matrix matrix_add(Matrix mat1, Matrix mat2);

// Faz a subtração de duas matrizes de mesma dimensão.
Matrix matrix_sub(Matrix mat1, Matrix mat2);

// Faz a multiplicação de duas matrizes, onde o numero de columas da primeira
// é igual ao numero de colunas da segunda. A matriz resultante tem o
// nro de linhas da primeira, e o nro de colunas da segunda.
Matrix matrix_mult(Matrix mat1, Matrix mat2);

// Retorna a matriz transposta de uma matriz.
// Linhas tornam-se colunas. Colunas tornam-se linhas.
Matrix matrix_transp(Matrix mat);

// Faz a multiplicação de uma matriz por um escalar.
Matrix matrix_scalar_mult(double scalar, Matrix mat);

// Cria uma matriz onde todos os elementos são 0, exceto os 
// elementos da diagonal principal que são 1.
Matrix matrix_identity(dstring name, int m, int n);



#endif