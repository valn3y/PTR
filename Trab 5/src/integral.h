#ifndef INTEGRAL_H
#define INTEGRAL_H

// F: R -> R
typedef double(*function_t)(double t);

// Integral by trapezium
double trapezium(function_t func, double begin, double finish);

// Integral by Average Riemann Sum.
double AVG_Riemann(function_t func, double begin, double finish);

// Integral by Left Riemann Sum.
double Left_Riemann(function_t func, double begin, double finish);

// Integral by Right Riemann Sum.
double Right_Riemann(function_t func, double begin, double finish);



#endif