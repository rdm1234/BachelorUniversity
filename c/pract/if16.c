// Рождественский if16
#include "stdio.h"

int main(){
  float a=11,b=10,c=75;
  if(a<b&&b<c){
    a*=2;
    b*=2;
    c*=2;
  }
  else{
    a = -a;
    b = -b;
    c = -c;
  }

  printf("%f %f %f\n", a,b,c);
  
  return 0;
}
