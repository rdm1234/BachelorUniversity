#include <stdio.h> // Стандартная библиотека ввода/вывода итд stdio.h
#include <stdlib.h> // Подключение библиотеки stdlib.h
#include <math.h> // Библиотека с математическими функциями math.h, для работы некоторых функций нужно компилировать с ключом -lm
#include <time.h> // Подключение библиотеки time.h

float method_1 (int, float, float, float, float, float); // Прототип функции вычисляющей корни по заданному методу
float f(int, float, float, float); // Прототип функции, возвращающей резульаты уравнения
float df();
void inputAndFails(int *, int *, float *, float *, float *, float *, float *); 

main(){
  srand(time(NULL)); // Генерация случайных чисел будет зависеть от времени
  
  int findMethod, eqNum;
  float k1, k2, E, a, b;

  inputAndFails(&findMethod, &eqNum, &k1, &k2, &E, &a, &b);
  printf("b = %f a = %f k1 = %f k2 = %f E = %f\nx = %.16f\n", b,a,k1,k2,E,method_1(eqNum, k1, k2, E, a, b));

  return 0;  
}

float method_1(int eN, float k1, float k2, float E, float a, float b){
  float c, fc;
  do{
    c=(a+b)/2;
    if(c == a || c == b)
      break;
    fc=f(eN, k1, k2, c);
    if(fc>0)
      b=c;
    if(fc<0)
      a=c;
      
  } while(abs(b - a) > E);
  return c;
}

float f(int eqNum, float k1, float k2, float x){
  
  switch(eqNum){ // Оператор switch обрабатывает 
  case 1:
    return log2f(k1*x) - k2;
  case 2:
    return powf(x,4) + k1*powf(x,3) - k2*x;
  case 3:
    return powf(x,5) + k1*powf(x,2) - k2;
  case 4:
    return 0;
  case 5:
    return 0;
  case 6:
    return 0;
  default:
    return 0;
  }
  
}

void inputAndFails(int *fM, int *eN, float *k1, float *k2, float *E, float *a, float *b){
  float cache;
  // Выбор метода
  printf("Введите номер способа, которым хотите решить это уравнение (1, 2)\n");
  scanf("%d", fM);
  if(*fM!=1 && *fM!=2){
    printf("Неверный номер, будет сгенерирован случайный\n");
    *fM = rand()%2+1;
    printf("Способ %d\n", *fM);
  }
  
  // Выбор уравнения
  printf("Введите номер уравнения (1, 2, 3 - уравнения 3, 5, 6 из заданий соответсвенно\n4, 5, 6 - мои уравнения)\n");
  scanf("%d", eN);
  if(*eN<1 || *eN>6){
    printf("Неверный номер, будет сгенерирован случайный\n");
    *eN = rand()%6+1; // переменной o присваивается случайное значение от 1 до 6 вклюичтельно
    printf("Будет решаться уравнение %d\n", *eN);
  }

  // Ввод k1, k2
  while(1){
    printf("Введите коэфиценты уравнение\n k1 = "); // Вывод строкт
    scanf("%f", k1); // Ввод числа с плавающей точкой с клавиатуры
    if(*k1!=0 || *eN!=1)
      break;
    printf("k1 не может равняться 0\n");
  }
  printf(" k2 = "); // Вывод строки
  scanf("%f", k2); // Ввод с клавиатуры
  
  // Ввод E
  printf("Введите точность решения уравнение E\n E = ");
  scanf("%f", E);

  // Ввод a, b
  if(*fM != 1){
    *a = -1;
    *b = -1;
  } else {
    while(1){
      printf("Введите a и b\n a = ");
      scanf("%f", a);
      printf(" b = ");
      scanf("%f", b);

      if(*a > *b){
	cache = *a;
	*a = *b;
	*b = cache;
      }

      if(*eN == 1 && (*k1<0 && (*a>=0 || *b>=0) || k2>0 && (*a<=0 || *b<=0))){
	printf("Должно соблюдаться условие:\nЕсли к1 < 0, a и б < 0\nЕсли к1 > 0, то а и б > 0\n");
	continue;
      }
      
      if(*a == *b){
	printf("Они не могут быть равны\b");
	continue;
      }
	
      if((f(*eN, *k1, *k2, *a) > 0 && f(*eN, *k1, *k2, *b) > 0) || (f(*eN, *k1, *k2, *a) < 0 && f(*eN, *k1, *k2, *b) < 0)){
	printf("Неподходящие а, b\n");
	continue;
      }

      break;
    }
  }
}
