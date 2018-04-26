#include <stdio.h>
#include <stdlib.h>

void fill(int*, int, int);
void sort(int*, int);
void coutArr(int*, int);
void moreElements(int*, int, int);

main()
{
  srand(time(NULL));
  int n, m, *arr;
  
  scanf("%d%d", &n, &m);
  arr=(int *)malloc(n*sizeof(int));
  fill(arr, 0, n);
  coutArr(arr, n);
  sort(arr, n);
  coutArr(arr, n);
  moreElements(arr, n, m);
  fill(arr, n, m);
  coutArr(arr, n+m);
  sort(arr, n+m);
  coutArr(arr, n+m);

  return 0;  
}

void fill(int *arr, int f, int t){
  for(f; f<t; f++){
    arr[f]=rand()%10;
  }
}

void sort(int *arr, int aS){
  int i,j;
  for(aS; aS > 0; aS--){
    for(j=0; j<aS; j++){
    if(arr[j]>arr[j-1]){
      i = arr[j];
      arr[j]=arr[j-1];
      arr[j-1]=i;
    }
    }
  }
}
void coutArr(int *arr, int aS){
  int i;
  for(i=0; i<aS; i++)
    printf("%d\n", arr[i]);
  printf("\n");
}

void moreElements(int *arr, int f, int t){
  arr=(int*)realloc(arr, (f+t)*sizeof(int));
}
