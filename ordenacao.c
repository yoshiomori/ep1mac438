/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: ordenacao.c                                        **/
/**                                                               **/
/**   Ronaldo Yang                   7576750                      **/
/**   Yoshio Mori                    6432393                      **/
/**                                                               **/
/**   04/04/2016                                                  **/
/*******************************************************************/

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
