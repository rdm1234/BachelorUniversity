// Roghdestvensky for29
#include <stdio.h>

main()
{
  int N = 10;
  float A=5.3, B=73.2, H,i;
  H=(B-A)/10;
  printf("H = %f\n", H);

  for(i=0; i < (B-A)/H; i++)
    printf("%f\n", (A + i*H));
  
  return 0;
}
