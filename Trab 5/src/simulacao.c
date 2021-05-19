#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulacao.h"
#include "integral.h"
#include "matrix.h"
#include "dstring.h"

Matrix getU(double t){
    Matrix velocidade = matrix_zeros(N$("Velocidade:"), 2,1);
    if(t >= 0 && t < 10){
        velocidade.values[0][0] = 1;
        velocidade.values[1][0] = 0.2*PI;
    }
    else if(t >= 10) {
        velocidade.values[0][0] = 1;
        velocidade.values[1][0] = -0.2*PI;
    }
    return velocidade;
}

Matrix getX(double prev_t, double t){
  Matrix pos = matrix_zeros(N$("Posição:"), 3, 2);
  pos.values[0][0] = AVG_Riemann(sin, prev_t, t);
  pos.values[1][0] = trapezium(cos, prev_t , t);
  pos.values[2][1] = 1;
  return pos;
}

Matrix simulate(double prev_t, double t, Matrix u) {
    Matrix pos = getX(t-1, t);
    Matrix id = matrix_identity(N$("Resultado"), 3, 3);
    Matrix res = matrix_mult(id, matrix_mult(pos, u));
    return res;
}

