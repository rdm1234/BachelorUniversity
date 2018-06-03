// 9.3 Рождественский
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
  srand(time(NULL));
  FILE *from, *to;
  int num,i, *cache = NULL, cache_size=0;

  if((from = fopen("fromf", "w"))==NULL)
     printf("Ошибка! Невозможно открыть файл для записи");
  else{
    for(i=0;i<100;i++)
      fprintf(from, "%d ", rand()%1000);
    fclose(from);
  }

  if((from = fopen("fromf", "r"))==NULL || (to=fopen("tof", "w+")) == NULL)
    printf("Ошибка! Невозможно открывть файл для чтения или записи");
  else{
    while(!feof(from)){
      cache=(int*)realloc(cache, ++cache_size*sizeof(int));
      fscanf(from, "%d", &cache[cache_size-1]);
    }
    while(cache_size-->1){
      fprintf(to, "%d ", cache[cache_size-1]);
    }
    free(cache);
    
    fclose(from);
    fclose(to);
  }

  return 0;
}
