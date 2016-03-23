#include <stdio.h>

int fibonacci(int n){
  if (n == 1 || n == 2)
    return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}

void printFibonacci(int n) {
	printf("P2: Para n = %d\n", n);
	printf("P2: f%d = %d\n", n, fibonacci(n));
}
