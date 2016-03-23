#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "heapsort.h"

#define seed time(NULL)

void ordenacao(int m) {
	int *numeros, i;
	
	srand(seed);
	numeros = malloc(sizeof(int) * m);

	for (i = 0; i < m; i++) {
		numeros[i] = rand() % m;
	}

	printf("P1: Vetor Inicial: ");
	for (i = 0; i < m; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");

	heapsort(m, numeros);

	printf("P1: Vetor Ordenado: ");
	for (i = 0; i < m; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");

	free(numeros);
}
