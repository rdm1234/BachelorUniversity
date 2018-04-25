// Roghdestvensky for18
#include <stdio.h>
#include <math.h>
main()
{
  float A = 10.3, sum = 0;
  int N = 5,i;
  
  for(i=0; i<N; i++)
    sum+=powf(A, N);

  printf("%f\n", sum);

  return 0;
}

