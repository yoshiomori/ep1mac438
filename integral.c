#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define S 100000
#define sec1 1.85081571768
#define seed 1

void integral(){
  int i, t = 0;
  srand(seed);
  for (i = 0; i < S; i++)
    if(1.0 / cos((double)rand() / RAND_MAX) >= (double)rand() * sec1 / RAND_MAX)
      t++;
  printf("t = %d\ns = %d\nt/s = %lf\n", t, S, (double)t * sec1 / S);
}
