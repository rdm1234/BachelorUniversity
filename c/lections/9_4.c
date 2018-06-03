// 9.4 Рождественский
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_to_file(FILE *);
int check(FILE *, int);
int if_prime(int);

main()
{
  FILE *base;
  int n, num;

  if((base = fopen("data", "w+"))==NULL)
    printf("ошибка открытия файла");
  else{
    write_to_file(base);
    fclose(base);
  }
  if((base = fopen("data", "r"))==NULL)
    printf("ошибка открытия файла");
  else{
    while(!feof(stdin)){
      scanf("%d", &num);
      if(check(base, num) == 1)
	printf("prime\n");
      else
	printf("not prime\n");
    }
    fclose(base);
  }
  return 0;
}
int check(FILE *base, int num){
  rewind(base);
  int l;
  while(!feof(base)){
    fscanf(base, "%d", &l);
    if(num == l) return 1;
  }
  return 0;
}

void write_to_file(FILE *base){
  int i;
  for(i=1; i<1000; i++)
    if(if_prime(i)==1){
      fprintf(base, "%d ", i);
    }
  
}

int if_prime(int n){
  int d,l=1;
  if(n==1)
    l=0;
  for(d=2;d<n;d++)
    if(n%d==0)
      l=0;
  return l;
}
