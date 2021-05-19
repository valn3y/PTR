#include <stdio.h>
#include <math.h>
#include "integral.h"

// Traditional Control Systems functions
// Ramp
double ramp(double t){
    const double a = 1;
    const double b = 0;
    if(t<0) return 0;
    else return a*t + b;
}

// Heaviside
double u(double t){
    if(t<0) return 0;
    else return 1;
}

// Polinomial
double pol(double t){
    return 5*(pow(t,3)) + 2*(pow(t,2)) + t - 3;
}

// Trigonometric
double trig(double t){
    return (cos(t) + sin(-2*t))/2; // Rad
}


int main(int argc, char const *argv[]){
    function_t f;
    // ------ Select a Function --------
    //f = pol;
    f = pol;

    const int A = 0;
    const int B = 10;
    
    printf("The Trapezium integral between %d and %d seconds: %f\n", 
        A, B, trapezium(f, A, B)
    );
    printf("The Left Riemann integral between %d and %d seconds: %f\n", 
        A, B, Left_Riemann(f, A, B)
    );
    printf("The Right Riemann integral between %d and %d seconds: %f\n", 
        A, B, Right_Riemann(f, A, B)
    );
    printf("The Average Riemann integral between %d and %d seconds: %f\n", 
        A, B, AVG_Riemann(f, A, B)
    );

    return(0);
}