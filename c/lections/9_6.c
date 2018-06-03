#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct student{
  char first_name[20];
  char second_name[20];
  float addmark;
  float mark[4];
  float rate;
};

void fill_data(FILE *);
void modify(FILE *);
void add_element(FILE *);
void edit_element(FILE *);
void sort_by_rate(FILE *);
void show_data(FILE *);

main(){
  setlocale(LC_ALL, "Rus");
  FILE *ivt11;
  struct student d;
  int if_new, what_to_do;
  printf("Do you want to create default base? (1/2) ");
  scanf("%d", &if_new);
  if(if_new == 1){
    fill_data(ivt11);
  }
  show_data(ivt11);
  
  while(!feof(stdin)){
    printf("Введите:\n 0 - чтобы увидеть данные студентов\n 1 - чтобы добавить элемент в базу\n 2 - чтобы редактировать данные в базе\n 3 - чтобы просмотреть студентов с рейтингом не ниже заданного\n");
    scanf("%d", &what_to_do);
    if(what_to_do==0)
      show_data(ivt11);
    else
      if(what_to_do==1)
	add_element(ivt11);
      else
	if(what_to_do == 2)
	  edit_element(ivt11);     
	else
	  if(what_to_do == 3)
	    sort_by_rate(ivt11);
	  else
	    printf("Wrong num! Fail!\n");
  }

  
  return 0;
}

void sort_by_rate(FILE *ivt11){
  struct student d;
  float n;
  if((ivt11=fopen("ivt11.dat", "r"))==NULL)
    printf("Ошибка открытия фала для чтения");
  else{
    printf("Введите рейтинг: "); scanf("%f", &n);
    int i=0;
    while(!feof(ivt11)){
      fread(&d, sizeof(struct student), 1, ivt11);
      if(d.rate>=n)
	printf("%d: %s %s\n Оценки: %f, %f, %f, %f\n Доп. баллы: %f\n Рейтинг: %f\n", i, d.second_name, d.first_name, d.mark[0], d.mark[1], d.mark[2], d.mark[3], d.addmark, d.rate);
      i++;
    }
    fclose(ivt11);
  }
}

void show_data(FILE *ivt11){
  struct student d;
  int i=0;
  if((ivt11=fopen("ivt11.dat", "r"))==NULL)
    printf("Ошибка открытия фала для чтения");
  else{
    while(!feof(ivt11)){
      fread(&d, sizeof(struct student), 1, ivt11);
      printf("%d: %s %s\n Оценки: %f, %f, %f, %f\n Доп. баллы: %f\n Рейтинг: %f\n", i, d.second_name, d.first_name, d.mark[0], d.mark[1], d.mark[2], d.mark[3], d.addmark, d.rate);
      i++;
    }
    fclose(ivt11);
  }
}

void add_element(FILE *ivt11){
  if((ivt11=fopen("ivt11.dat", "a"))==NULL)
    printf("Ошибка открытия файла для добавления");
  else{
    struct student d;
    printf("Введите Фамилию, Имя, дополнительные баллы, 4 оценки за работы\n");
    scanf("%s%s%f%f%f%f%f", d.second_name, d.first_name, &d.addmark, &d.mark[0], &d.mark[1], &d.mark[2], &d.mark[3]);
    d.rate=(d.mark[0]+d.mark[1]+d.mark[2]+d.mark[3]+d.addmark)/5;
    fwrite(&d, sizeof(struct student), 1, ivt11);
    fclose(ivt11);
  }
}
void edit_element(FILE *ivt11){
  if((ivt11=fopen("ivt11.dat", "r+"))==NULL)
    printf("Ошибка открытия открытия файла для редактирования");
  else{
    int n;
    struct student d;
    printf("Введите номер студента: "); scanf("%d", &n);
    printf("Введите Фамилию, Имя, дополнительные баллы, 4 оценки за работы\n");
    scanf("%s%s%f%f%f%f%f", d.first_name, d.second_name, &d.addmark, &d.mark[0], &d.mark[1], &d.mark[2], &d.mark[3]);
    d.rate=(d.mark[0]+d.mark[1]+d.mark[2]+d.mark[3]+d.addmark)/5;
    fseek(ivt11, n*sizeof(struct student), SEEK_SET);
    fwrite(&d, sizeof(struct student), 1, ivt11);
    fclose(ivt11);
  }
}

void fill_data(FILE *ivt11){
  FILE *cache;
  struct student d;
  int i;
  if((ivt11 = fopen("ivt11.dat", "w"))==NULL || (cache = fopen("cache", "w+")) == NULL)
      printf("Ошибка записи в файл");
    else{
      fprintf(cache, "Аветисян Даниил 0 0 1.17 4 4.3 Багаев Георгий 0 3 0 3 4.5 Гревцева Мария -0.5 1.5 1 4 4 Дёмин Максим 0.3 4.3 4.34 4 4 Еремеев Дмитрий 0 3 1.4 5 4 Калмыков Максим 0 3.5 1.3 5 5 Карпов Дмитрий 0 2 0 3 3 Качало Валерия 0 2.5 2.97 4 3.8 Кондратьев Вячеслав 0 3 1.3 3 4 Кузьминов Евгений 0 2.5 0 0 0 Липилин Геннадий 0.1 3 2.97 3 0 Макагонов Пётр 0 3 1.9 3 0 Парчевский Владислав -0.5 0 1.3 0 3.5 Пояс Алексей 0 4 4 4 4 Рождественский Дмитрий 0.2 3.9 4.64 4 4 Сизых Максим 2.5 0 0 0 0 Тимофеев Иван 0 0 0 0 0 Тонина Марина 0 0 0 0 0 Тюрников Сергей 0 3 3.77 3 3.5 Файзуллаев Сайфуло 0.1 4 4.34 4.3 4 Федоров Имя 0 0 0 0 0 Челбухов Юрий 0.5 4 4.27 4.7 4");
      //int i=0;
      rewind(cache);
      while(!feof(cache)){
	fscanf(cache, "%s%s%f%f%f%f%f", d.second_name, d.first_name, &d.addmark, &d.mark[0], &d.mark[1], &d.mark[2], &d.mark[3]);
	d.rate=(d.mark[0]+d.mark[1]+d.mark[2]+d.mark[3]+d.addmark)/5;
	//printf("%d: %s %s Оценки: %f, %f, %f, %f; Доп. баллы: %f; Рейтинг: %f\n", i, d.second_name, d.first_name, d.mark[0], d.mark[1], d.mark[2], d.mark[3], d.addmark, d.rate);
	//i++;
	fwrite(&d, sizeof(struct student), 1, ivt11);
      }
      
      fclose(ivt11);
      fclose(cache);
    }
}
