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


Matrix simulate_x(double prev_t, double t, Matrix u){
    Matrix auxMatX = getX(t-1, t);
    Matrix x = matrix_mult(auxMatX, u);
    return x;
}


Matrix simulate_y(double prev_t, double t, Matrix x){
    Matrix Id = matrix_identity(N$("Id: "), 2, 3);
    Matrix aux = matrix_zeros(N$("Aux: "), 2, 1);
    aux.values[0][0] = 0.3 * cos(x.values[2][0]);
    aux.values[1][0] = 0.3 * sin(x.values[2][0]);
    Matrix res = matrix_add(matrix_mult(Id, x), aux);
    return res;
}


Matrix reference(double t){
    Matrix ref = matrix_zeros(N$("Referencia: "), 2, 1);
    if(t>=0 && t<2*PI){
        ref.values[0][0] = 0.5 - 0.5 * cos(t);
        ref.values[1][0] = 0.5 * sin(t);
    }
    else if(t>=2*PI && t<4*PI){
        ref.values[0][0] = -0.5 + 0.5 * cos(t);
        ref.values[1][0] = -0.5 * sin(t);
    }
    return ref;
}

Matrix v_controler(Matrix ref, Matrix dot_ref, Matrix y, 
                   double a1,      double a2,
                   double y1,      double y2){

    Matrix v = matrix_zeros(N$("Controler: "), 2, 1);
    v.values[0][0] = dot_ref.values[0][0] + a1 * (ref.values[0][0] - y1);
    v.values[0][1] = dot_ref.values[1][0] + a2 * (ref.values[1][0] - y2);
    return v;
}

Matrix L(double x3){
    Matrix a = matrix_zeros(N$("Aux:"), 2, 2);
    a.values[0][0] = cos(x3);
    a.values[0][1] = -0.3 * sin(x3);
    a.values[1][0] = sin(x3);
    a.values[1][1] = 0.3 * cos(x3);

    return a;
}

Matrix linearizacao(Matrix v, double x3){
    Matrix L_inv = matrix_inverse2x2(L(x3));
    Matrix u = matrix_mult(L_inv, v);

    return u;
}


Matrix dot_reference(double t){
    Matrix ref = matrix_zeros(N$("Referencia: "), 2, 1);
    if(t>=0 && t<2*PI){
        ref.values[0][0] = 0.5 * sin(t);
        ref.values[1][0] = 0.5 * cos(t);
    }
    else if(t>=2*PI && t<4*PI){
        ref.values[0][0] = -0.5 * sin(t);
        ref.values[1][0] = -0.5 * cos(t);
    }
    return ref;
}