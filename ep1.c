#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fibonacci.h"
#include "integral.h"
#include "ordenacao.h"
#include "buffon.h"

int main(int argc, char **argv) {
	int m, n, r, s, status, i;	
	
	if (argc != 5) {
		printf("Quantidade de argumentos incorreta\n");
	}
	else {
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		r = atoi(argv[3]);
		s = atoi(argv[4]);
		
		printf("P0: Iniciando Programa Principal\n");
		if (fork() == 0) { /* Primeiro Filho */
			printf("P1: Iniciando P1\n");
			ordenacao(m);
			printf("P1: Encerrando o P1\n");	
		}
		else {
			if (fork() == 0) { /* Segundo Filho */
				printf("P2: Iniciando P2\n");
				printFibonacci(n);
				printf("P2: Encerrando o P2\n");
			}	
			else {
				if (fork() == 0) { /* Terceiro Filho */
					printf("P3: Iniciando P3\n");
					buffon(r);
					printf("P3: Encerrando o P3\n");
				}
				else {
					if (fork() == 0) { /* Quarto Filho */
						printf("P4: Iniciando P4\n");
						integral(s);
						printf("P4: Encerrando o P4\n");
					}
					else {
						printf("P0: Começando a espera do Programa Principal\n");
						for (i = 0; i < 4; i++) {
							wait(&status);
						}						
						printf("P0: Encerrando o Programa Principal\n");
					}
				}
			}
		}
	}
  return 0;
}
