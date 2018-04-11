// if25
#include "stdio.h"

int main(){
  int x,f;

  scanf("%d", &x);

  if(x<-2 || x>2)
    f=2*x;
  else
    f=(-3)*x;

  printf("%d",f);
  
  return 0;
}
