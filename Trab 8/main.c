#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrix.h"
#include "simulacao.h"

#define NUM_THREADS 2
#define TIMEOUT 20

double delta = 0.2;


int main(int argc, char const * argv[]) {
	Matrix y = matrix_zeros(N$("Y: "), 2, 1);
	Matrix x = matrix_zeros(N$("X: "), 3, 1);

	for(double i = 0 ; i<13; i = i + delta){
		Matrix ref = reference(i);
		
		Matrix v = v_controler(ref, dot_reference(i), y, 1, 1, 1, 1);
	
		Matrix u = linearizacao(v, x.values[2][0]);

		x.name = N$("X: ");
		matrix_print(x);
		x = simulate_x(i-delta, i, u);
		
		y.name = N$("Y: ");
		matrix_print(y);
		y = simulate_y(i-delta, i, x);

	}

	return 0;
}

