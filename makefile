#***************************************************************#
#   MAC 438  - Programação Concorrente                          #
#   IME-USP  - Primeiro Semestre de 2016                        #
#   Prof. Marcel Parolin Jackowski                              #
#                                                               #
#   Primeiro Exercício-Programa                                 #
#   Arquivo: makefile                                           #
#                                                               #
#   Ronaldo Yang                   7576750                      #
#   Yoshio Mori                    6432393                      #
#                                                               #
#   04/04/2016                                                  #
#***************************************************************#

CC= gcc
CFLAGS=-lm

ep1: ep1.o heapsort.o ordenacao.o fibonacci.o buffon.o integral.o
	$(CC) ep1.o heapsort.o ordenacao.o fibonacci.o buffon.o integral.o -o ep1 $(CFLAGS)
	rm *.o

ep1.o: ep1.c
	$(CC) -c -Wall -ansi -pedantic ep1.c 

heapsort.o: heapsort.c
	$(CC) -c -Wall -ansi -pedantic heapsort.c 

ordenacao.o: ordenacao.c
	$(CC) -c -Wall -ansi -pedantic ordenacao.c 

fibonacci.o: fibonacci.c
	$(CC) -c -Wall -ansi -pedantic fibonacci.c

buffon.o: buffon.c
	$(CC) -c -Wall -ansi -pedantic buffon.c

integral.o: integral.c
	$(CC) -c -Wall -ansi -pedantic integral.c 

clean:	
	rm *.o
