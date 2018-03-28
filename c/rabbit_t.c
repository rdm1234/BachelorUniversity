#include <stdio.h>
#include <stdlib.h>

void sitT(int,int*);
void sitR(int,int*);
main()
{
  srand(time(NULL));
  int rabbit=1, turtle=1,step;

  printf("Turtle Rabbit");
  while((rabbit<70)&&(turtle<70)){
    
    step=rand()%100;
    sitT(step,&turtle);
    sitR(step,&rabbit);
    printf("%d %d\n", turtle, rabbit);
  }
    
  return 0;
}


void sitR(int p, int *rP){
  if(p>19&&p<40)
    *rP+=9;
  if(p>39&&p<50)
    *rP-=12;
  if(p>49&&p<80)
    *rP++;
  if(p>80)
    *rP-=2;

  if(*rP<0)
    *rP=0;
}
void sitT(int p, int *tP){
  if(p<50){
    *tP+=3;
  } else if(p<70){
    *tP-=6;
  } else
    *tP++;

  if(*tP<0)
    *tP=0;
  }
