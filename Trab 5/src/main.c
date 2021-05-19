#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrix.h"
#include "simulacao.h"

int main(int argc, char const * argv[]) {
	int time = 20;
	double delta = 1;
	Matrix mat_X, mat_U, mat_Y;

	//printf("i\tu0\tu1\ty0\ty1\ty2\n");
	for(double i = 0; i <= time; i += delta) {
		mat_X = getX(i-delta, i);
		mat_U = getU(i);
		mat_Y = simulate(i-delta, i, getU(i));
		printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",
		i,
		mat_U.values[0][0], mat_U.values[1][0], 
		mat_Y.values[0][0], mat_Y.values[1][0], mat_Y.values[2][0]);
	}

	return 0;
}

