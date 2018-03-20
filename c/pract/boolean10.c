// Рождественский boolean10
#include <stdio.h>

int main()
{
  int a,b;
  scanf("%d%d", &a,&b);
  if((a%2==0 && b%2!=0) || (b%2==0 && a%2!=0))
    printf("True\n");
  else
    printf("False\n");
    
  return 0;
}
