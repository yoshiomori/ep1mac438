#include <stdio.h>
#include "fibonacci.h"
#include "integral.h"

int main(){
  printf("f1 = %d(1)\n", fibonacci(1));
  printf("f2 = %d(1)\n", fibonacci(2));
  printf("f5 = %d(5)\n", fibonacci(5));
  printf("f6 = %d(8)\n", fibonacci(6));
  integral();
  return 0;
}
