// Рождественский case4
#include <stdio.h>

int main(){
  int num;
  scanf("%d",&num);
  if(num==2)
    printf("28\n");
  else if(num%2==0)
    printf("30\n");
  else
    printf("31\n");
  
  return 0;
}
