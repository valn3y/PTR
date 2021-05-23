#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "matrix.h"
#include "simulacao.h"

#define NUM_THREADS 2
#define TIMEOUT 20

double delta = 1;
double aux = 0;
Matrix mat_U;
pthread_mutex_t mutexThread;
pthread_cond_t conditionSimulateThread;

void *SimulateFirst(void *idThread){
	pthread_mutex_lock(&mutexThread);
	while(aux <= TIMEOUT){
		mat_U = getU(delta);
		pthread_cond_wait(&conditionSimulateThread, &mutexThread);
	}

	pthread_mutex_unlock(&mutexThread);
	pthread_exit(NULL);
}

void *SimulateSecond(void *idThread){
	Matrix mat_Yt;

	pthread_mutex_lock(&mutexThread);
	while(aux <= TIMEOUT){
		mat_Yt = simulate(aux-delta, aux, mat_U);
		printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",
		aux,
		mat_U.values[0][0], mat_U.values[1][0], 
		mat_Yt.values[0][0], mat_Yt.values[1][0], mat_Yt.values[2][0]);

		aux += delta;

		pthread_cond_signal(&conditionSimulateThread);
		pthread_mutex_unlock(&mutexThread);
	}

	pthread_exit(NULL);
}


int main(int argc, char const * argv[]) {
	long t1=1, t2=2;
	pthread_t threads[3];

	pthread_mutex_init(&mutexThread, NULL);
	pthread_cond_init(&conditionSimulateThread, NULL);

	pthread_create(&threads[0], NULL, SimulateFirst, (void *)t1);
	pthread_create(&threads[1], NULL, SimulateSecond, (void *)t2);

	for(int i = 0; i < NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}

	pthread_mutex_destroy(&mutexThread);
	pthread_cond_destroy(&conditionSimulateThread);
	pthread_exit(NULL);

	return 0;
}

