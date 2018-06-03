// Рождественский 9.5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){
  FILE *fdata;
  int n, m, i, j;
  if((fdata = fopen("friendly", "w")) == NULL)
    printf("Ошибка при открытии файла для записи!");
  else {
    for(i=0; i<10000000; i++){
      n=0;
      m=0;
      for(j=0;j<i/2+1;j++)
	if(i%j==0)
	  n+=j;
      for(j=0;j<n/2+1;j++)
	if(n%j==0)
	  m+=j;
      if(m==i)
	fprintf(fdata, "%d %d\n", n, m);
    }
    fclose(fdata);
  }

  return 0;
}
