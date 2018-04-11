// Рождественский case7
#include <stdio.h>

int main(){
  int si;
  float mass;
  scanf("%d%f",&si,&mass);
  switch(si){
  case 1:
    break;
  case 2:
    mass/=1000000;
    break;
  case 3:
    mass/=1000;
    break;
  case 4:
    mass*=1000;
    break;
  case 5:
    mass*=100;
    break;
  }

  printf("%f kg\n", mass);
  
  return 0;
}
