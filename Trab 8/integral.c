/*
 * INTEGRAÇÃO NUMERICA
 * An API responsible to calculate a function integral in certain range.
 * Authors: Josias Cavalcante, Valney Junior 
 * Last edit: May, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "integral.h"

// Integral by Trapezium
double trapezium(function_t func, double begin, double finish){
    // Error case
    if(begin>finish) return 0.0; 

    const int g_delta = 100000;
    double delta = (finish-begin)/g_delta;

    double ans = 0.0;
    for(double t = begin; t<=finish; t+= delta){
        ans += ( (func(t) + func(t+delta)) * (delta) / 2 );
    }

    return ans;
}


// Integral by Average Riemann sum
double AVG_Riemann(function_t func, double begin, double finish){
    // Error case
    if(begin>finish) return 0.0; 

    const int g_delta = 10000000;
    double delta = (finish-begin)/g_delta;
    
    double ans = 0.0;
    for(double t = begin; t<=finish; t+= delta){
        ans += ( (func(t + delta*0.5)) * delta );
    }

    return ans;
}

// Integral by Left Riemann sum
double Left_Riemann(function_t func, double begin, double finish){
    // Error case
    if(begin>finish) return 0.0; 

    const int g_delta = 10000000;
    double delta = (finish-begin)/g_delta;
    
    double ans = 0.0;
    for(double t = begin; t<=finish; t+= delta){
        ans += ( (func(t)) * delta );
    }

    return ans;
}

// Integral by Right Riemann sum
double Right_Riemann(function_t func, double begin, double finish){
    // Error case
    if(begin>finish) return 0.0; 

    const int g_delta = 10000000;
    double delta = (finish-begin)/g_delta;
    
    double ans = 0.0;
    for(double t = begin; t<=finish; t+= delta){
        ans += ( (func(t+delta)) * delta );
    }

    return ans;
}