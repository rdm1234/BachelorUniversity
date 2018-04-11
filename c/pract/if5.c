// if5 
#include "stdio.h"

int main(){
  int a=5,b=3,c=-1,countPlus=0,countMinus=0;
  if(a>0)
    countPlus++;
  if(a<0)
    countMinus++;
  if(b>0)
    countPlus++;
  if(b<0)
    countMinus++;
  if(c>0)
    countPlus++;
  if(c<0)
    countMinus++;

  printf("Amount of numbers greater than 0 = %d\nAmount of nubers less than 0 = %d\n", countPlus,countMinus);
  
  return 0;
}
