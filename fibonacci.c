/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: fibonacci.c                                        **/
/**                                                               **/
/**   Ronaldo Yang                   7576750                      **/
/**   Yoshio Mori                    6432393                      **/
/**                                                               **/
/**   04/04/2016                                                  **/
/*******************************************************************/

#include <stdio.h>

void fibonacci(int n) {
	unsigned int fprox, f, fant;
	int i;	

	if (n == 0) f = 0;
	else {
		fant = 0;
		f = 1;
		for (i = 2; i < n; i++) {
			fprox = f + fant;
			fant = f;
			f = fprox;
		}
	}	
	printf("P2: Para n = %d\n", n);
	printf("P2: f%d = %u\n", n, f);
}
 

