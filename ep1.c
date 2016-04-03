/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: ep1.c                                              **/
/**                                                               **/
/**   Ronaldo Yang                   7576750                      **/
/**   Yoshio Mori                    6432393                      **/
/**                                                               **/
/**   04/04/2016                                                  **/
/*******************************************************************/

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
	pid_t  p1, p2, p3, p4, p;	

	if (argc != 5) {
		printf("Quantidade de argumentos incorreta\n");
	}
	else {
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		r = atoi(argv[3]);
		s = atoi(argv[4]);
		
		printf("P0: Iniciando Programa Principal\n");
		
		if ((p1 = fork()) < 0) {
			printf("P0: Erro na criação de P1\n");
			exit(1);
		}
		else if (p1 == 0) { /* Primeiro Filho */
			printf("P1: Iniciando P1\n");
			ordenacao(m);
			printf("P1: Encerrando o P1\n");	
			exit(0);
		}
		else {
			if ((p2 = fork()) < 0) {
				printf("P0: Erro na criação de P2\n");
				exit(1);
			}
			if (p2 == 0) { /* Segundo Filho */
				printf("P2: Iniciando P2\n");
				fibonacci(n);
				printf("P2: Encerrando o P2\n");
				exit(0);
			}	
			else {
				if ((p3 = fork()) < 0) {
					printf("P0: Erro na criação de P3\n");
					exit(1);
				}
				if (p3 == 0) { /* Terceiro Filho */
					printf("P3: Iniciando P3\n");
					buffon(r);
					printf("P3: Encerrando o P3\n");
					exit(0);
				}
				else {
					if ((p4 = fork()) < 0) {
						printf("P0: Erro na criação de P4\n");
						exit(1);
					}
					if (p4 == 0) { /* Quarto Filho */
						printf("P4: Iniciando P4\n");
						integral(s);
						printf("P4: Encerrando o P4\n");
						exit(0);
					}
					else { /* Pai */
						printf("P0: Começando a espera do Programa Principal\n");
						for (i = 0; i < 4; i++) {
							p = wait(&status);
							if (p == p1) printf("P0: Terminou a espera por P1\n");
							else if (p == p2) printf("P0: Terminou a espera por P2\n");
							else if (p == p3) printf("P0: Terminou a espera por P3\n");
							else if (p == p4) printf("P0: Terminou a espera por P4\n");
						}						
						printf("P0: Encerrando o Programa Principal\n");
					}
				}
			}
		}
	}
  return 0;
}
