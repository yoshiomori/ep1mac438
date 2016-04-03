/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: buffon.c                                           **/
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

#define seed time(NULL)
#define L 1
#define G 1
#define PI 3.141592653589793
#define PROB (2/PI)*(L/G)

void buffon(int r) {
	int i, t = 0;
	double theta, d, calc;

	srand(seed);

	for (i = 0; i < r; i++) {
		d = ((double)rand()/(double)(RAND_MAX)) * G;
		theta = ((double)rand()/(double)(RAND_MAX)) * PI * 2;					
		calc = d + L*sin(theta); 
				
		if (calc < 0 || calc > G) t++;
	}
	printf("P3: Estimativa com %d interações\n", r);
	printf("P3: Probabilidade: %f\n", PROB);
	printf("P3: Probabilidade Estimada: %f\n", (double)t/r);
}
