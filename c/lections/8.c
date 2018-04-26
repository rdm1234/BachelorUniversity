#include <stdlib.h>
#include <stdio.h>

int pop(int *);
void push(int *, int);
void coutArr(int *);

main(){
  int *arr, arrSize,i;
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
      push(arr, i);
    }
    if(c=='o')
      printf("%d\n", pop(arr));
    coutArr(arr);
    getchar();
  }

  return 0;  
}

int pop(int *arr){
  if(sizeof(arr) == 0)
    return 0;
  int num = arr[sizeof(arr)/sizeof(int*)-1];
  
  arr = (int*)realloc(arr, sizeof(arr)-sizeof(int*));
  return num;
}
void push(int *arr, int newNum){
  arr = (int*)realloc(arr, sizeof(arr)+sizeof(int*));
  arr[sizeof(arr)/sizeof(int*)-1] = newNum;
}

void coutArr(int *arr){
  int i, aS = sizeof(arr)/sizeof(int*);
  for(i=0; i<aS; i++)
    printf("%d\n", arr[i]);
}
