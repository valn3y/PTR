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
Matrix simulate_x(double prev_t, double t, Matrix u);

Matrix simulate_y(double prev_t, double t, Matrix x);

Matrix reference(double t);

Matrix v_controler(Matrix ref, Matrix dot_ref, Matrix y,
                   double a1,      double a2,
                   double y1,      double y2);

Matrix L(double x3);

Matrix linearizacao(Matrix v, double x3);

Matrix dot_reference(double t);

#endif