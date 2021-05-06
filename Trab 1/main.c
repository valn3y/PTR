#include "sum.h"
#include "subtraction.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	printf("----Trabalho 1 - PTR----\n");
	printf("Dupla: Josias Ben e Valney Marinho\n");

	double a, b;
	printf("Preencha o valor de a: ");
	scanf("%lf", &a);

	printf("Preencha o valor de b: ");
	scanf("%lf", &b);

	printf("Resultado da soma (a+b): %lf\n", sum(a, b));
	printf("Resultado da diferença (a-b): %lf\n", subtraction(a, b));
	return 0;
}
