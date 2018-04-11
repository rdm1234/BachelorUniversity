// Рождественский case14
#include <stdio.h>
#include <math.h>

int main(){
  int number;
  float a, R1, R2, S;
  scanf("%d",&number);
  switch(number){
  case 1:
    scanf("%f",&a);
    R1=a*sqrt(3)/6;
    R2=R1*2;
    S=a*a*sqrt(3)/4;
    break;
  case 2:
    scanf("%f",&R1);
    a=R1/sqrt(3)*6;
    R2=R1*2;
    S=a*a*sqrt(3)/4;
    break;
  case 3:
    scanf("%f",&R2);
    R1=R2/2;
    a=R1/sqrt(3)*6;
    S=a*a*sqrt(3)/4;
    break;
  case 4:
    scanf("%f",&S);
    a=sqrt(S/sqrt(3)*4);
    R1=a*sqrt(3)/6;
    R2=R1*2;
    break;
  }

  printf("%f %f %f %f",a,R1,R2,S);
  
  return 0;
}
