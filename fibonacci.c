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
 

