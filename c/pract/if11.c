// if11
#include "stdio.h"

int main(){
  int a=10,b=10;

  if(a!=b){
    a=a+b;
    b=a;
  } else {
    a=0;
    b=0;
  }

  printf("%d %d\n", a,b);
  
  return 0;
}
