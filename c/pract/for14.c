// Roghdestvensky for14
#include <stdio.h>

main()
{
  int N;
  scanf("%d", &N);
  int i,p=1;
  for(i=1; i<N; i++)
  {
    p=i*2-1;
    printf("%d\n", p);
  }

  return 0;
}

