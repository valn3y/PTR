#include <stdio.h>
#include <math.h>
#include "integral.h"

// Traditional Control Systems functions
double ramp(double t){
    const double a = 1;
    const double b = 0;
    if(t<0) return 0;
    else return a*t + b;
}

// Miscelaneous
double misc1(double t){
    return 2*(pow(t,2)) + t - 3;
}


int main(int argc, char const *argv[]){
    const double delta = 0.001;
    double y;

    for(double t = 0; t<5; t+=delta){
        y = ramp(t);
        printf("y = %f\n", y);
    }

    const int A = 1;
    const int B = 2;

    printf("The Trapezium integral between %d and %d seconds: %f\n", 
        A,
        B,
        trapezium(misc1, A, B)
    );

    printf("The Left Riemann integral between %d and %d seconds: %f\n", 
        A,
        B,
        Left_Riemann(misc1, A, B)
    );
 
    printf("The Right Riemann integral between %d and %d seconds: %f\n", 
        A,
        B,
        Right_Riemann(misc1, A, B)
    );

    printf("The Average Riemann integral between %d and %d seconds: %f\n", 
        A,
        B,
        AVG_Riemann(misc1, A, B)
    );

    return(0);
}