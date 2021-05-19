#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "matrix.h"
#define PI 3.14159265358979323846
// Input u
Matrix getU(double t);
// Integral of xdot = x
Matrix getX(double prev_t, double t);
// Run sumilation
Matrix simulate(double prev_t, double t, Matrix u);
#endif

