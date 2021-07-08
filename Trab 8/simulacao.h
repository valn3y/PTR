#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "matrix.h"
#define PI 3.14159265358979323846
// Input u
Matrix getU(double t);
// Integral of xdot = x
Matrix getX(double prev_t, double t);
// Matrix point
Matrix getYt(double prev_t, double t);
// Run simulate
Matrix simulate(double prev_t, double t, Matrix u);

Matrix reference(double t);

Matrix v_controler(Matrix ym, Matrix ym_dot, 
                   double a1,      double a2,
                   double y1,      double y2);

Matrix L(double x3);

Matrix linearizacao(Matrix v, double x3);


#endif