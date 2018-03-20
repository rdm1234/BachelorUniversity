// Рождественский boolean35
#include <stdio.h>

int main()
{
  int x1,x2,y1,y2;
  scanf("%d%d%d", &x1,&y1,&x2,&y2);
  if(y1%2!=0){
    if(y2%2!=0){
      if((x1%2==0 && x2%2==0) || (x1%2!=0 && x2%2!=0))
         printf("True\n");
      else
        printf("False\n");
    }
    if(y2%2==0){
       if((x1%2==0 && x2%2!=0) || (x1%2!=0 && x2%2==0))
         printf("True\n");
      else
        printf("False\n");
    }
  }
  else {
    if(y2%2==0){
      if((x1%2==0 && x2%2==0) || (x1%2!=0 && x2%2!=0))
         printf("True\n");
      else
        printf("False\n");
    }
    if(y2%2!=0){
       if((x1%2==0 && x2%2!=0) || (x1%2!=0 && x2%2==0))
         printf("True\n");
      else
        printf("False\n");
    }
  }
   
    
  return 0;
}
