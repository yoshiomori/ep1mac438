/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: integral.c                                         **/
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

#define sec1 1.85081571768
#define seed time(NULL)

void integral(int s){
	int i, t = 0;
	srand(seed);
	for (i = 0; i < s; i++)
		if(1.0 / cos((double)rand() / RAND_MAX) >= (double)rand() * sec1 / RAND_MAX)
			t++;
	printf("P4: Número de pontos t = %d\n", t);
	printf("P4: Número de pontos s = %d\n", s);
	printf("P4: Área estimada = %f\n", (double)t * sec1 / s);
}
