/*
 * Simulation
 * Authors: Josias Cavalcante, Valney Junior 
 * Last edit: May, 2021
*/

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

Matrix getYt(double prev_t, double t){
    double Diameter = 2.5;
    Matrix point = matrix_zeros(N$("Ponto:"), 3,3);
    if(t > 0){
        point.values[0][0] = 0.5 * Diameter * trapezium(cos, prev_t, t);
        point.values[1][1] = 0.5 * Diameter * AVG_Riemann(sin, prev_t, t);
        point.values[2][2] = 1;
    }

    return point;
}

// Matrix simulate(double prev_t, double t, Matrix u) {
//     Matrix pos = getX(t-1, t);
//     Matrix id = matrix_identity(N$("Resultado"), 3, 3);
//     Matrix res = matrix_mult(id, matrix_mult(pos, u));
//     return res;
// }

Matrix simulate(double prev_t, double t, Matrix u){
    Matrix auxMatX = getX(t-1, t);
    Matrix x = matrix_mult(auxMatX,u);
    Matrix auxMatY = getYt(t-1, t);
    Matrix res = matrix_add(matrix_mult(auxMatY,x), x);
    return res;
}
