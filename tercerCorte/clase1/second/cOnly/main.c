#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfib.h"

int main(int argc, char **argv)
{

  int arg = 0, numiter = 0, i;

  clock_t t;
  if (argc != 3)
  {
    fprintf(stderr, "%s <arg> <numiter>\n", argv[0]);
    return 1;
  }

  arg = atoi(argv[1]);
  numiter = atoi(argv[2]);
  t = clock();

  for (i = 0; i < numiter; i++)
  {
    cfib(arg);
  }

  t = clock() - t;

  printf("%f\n", ((float)t) / 1000000 / numiter * 1e9);

  return 0;
}
