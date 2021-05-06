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

// Miscelaneous
double misc1(double t){
    return 2*(pow(t,2)) + t - 3;
}

// Trigonometric
double misc2(double t){
    return (cos(t) + cos(-t))/2; // Rad
}


int main(int argc, char const *argv[]){
    function_t f;
    // ------ Select a Function
    //f = u;
    //f = misc1;
    //f = ramp;
    f = misc2;


    // double y;
    // const double delta = 0.001;
    // for(double t = 0; t<5; t+=delta){
    //     y = f(t);
    //     printf("y = %f\n", y);
    // }

    const int A = 1;
    const int B = 2;
    

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