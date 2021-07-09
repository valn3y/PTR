#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrix.h"
#include "simulacao.h"

#define NUM_THREADS 2
#define TIMEOUT 20

double delta = 0.2;


int main(int argc, char const * argv[]) {
	
	for(int i = 0 ; i<13; i = i + delta){
		Matrix ref = reference(i);
	}


	return 0;
}

