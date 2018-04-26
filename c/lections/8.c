#include <stdlib.h>
#include <stdio.h>

int pop(int *, int);
void push(int *, int, int);
void coutArr(int *, int);

main(){
  int *arr, arrSize = 1,i;
  char c;
  arr = (int*)malloc(sizeof(int));
  arr[0]=100;
  
  while(1){
    printf("To push press i, to pop press o, to end press e\n");
    c = getchar();
    if(c=='e')
      break;
    if(c=='i'){
      printf("new num = ");
      scanf("%d", &i);
      push(arr, i, arrSize);
      arrSize++;
    }
    if(c=='o'){
      printf("%d\n", pop(arr, arrSize));
      arrSize--;
    }
    coutArr(arr, arrSize);
    getchar();
  }

  return 0;  
}

int pop(int *arr, int s){
  if(s == 0)
    return 0;
  int num = arr[s-1];
  
  arr = (int*)realloc(arr, s*sizeof(int)-sizeof(int));
  return num;
}
void push(int *arr, int newNum, int s){
  arr = (int*)realloc(arr, s*sizeof(int)+sizeof(int));
  arr[s-1] = newNum;
}

void coutArr(int *arr, int s){
  int i;
  for(i=0; i<s; i++)
    printf("\n%d\n\n", arr[i]);
}
