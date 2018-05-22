#include <stdio.h> // Стандартная библиотека ввода/вывода итд stdio.h
#include <stdlib.h> // Подключение библиотеки stdlib.h
#include <math.h> // Библиотека с математическими функциями math.h, для работы некоторых функций нужно компилировать с ключом -lm
#include <time.h> // Подключение библиотеки time.h

double method_1(int, double, double, double, double, double); // Прототип функции вычисляющей корни по заданному методу
double method_2(int, double, double, double, double);
double f(int, double, double, double); // Прототип функции, возвращающей резульаты уравнения
double df(int, double, double, double);
void inputAndFails(int *, int *, double *, double *, double *, double *, double *, double *); 

main(){
  srand(time(NULL)); // Генерация случайных чисел будет зависеть от времени
  
  int findMethod, eqNum;
  double k1, k2, E, a, b, result, xn;

  inputAndFails(&findMethod, &eqNum, &k1, &k2, &E, &a, &b, &xn);
  if(findMethod == 1)
    result = method_1(eqNum, k1, k2, E, a, b);
  else
    result = method_2(eqNum, k1, k2, E, xn);
  printf("b = %f a = %f k1 = %f k2 = %f E = %f\nx = %f\n", b,a,k1,k2,E,result);
  
  return 0;  
}

double method_1(int eN, double k1, double k2, double E, double a, double b){

  double c, fc,fa;
  int iter=0;
  do{
    c=(a+b)/2;
    if(c == a || c == b)
      break;
    
    fc=f(eN, k1, k2, c);
    fa=f(eN, k1, k2, a);
    if(fc>=0 && fa>=0 || fc<=0 && fa<=0)
      a=c;
    else
      b=c; 
    iter++;
    if(iter==200)
      return -1;
  } while(fabs(b-a) > E);
  printf("iter = %d\n", iter);
  return c;
}
 
double method_2(int eqNum, double k1, double k2, double E, double xn){
  double ifEnd, x,rx[3];
  int iter=0;
  
  do{
    x = xn - f(eqNum, k1, k2, xn)/df(eqNum, k1, k2, xn);
    
    rx[0]=fabs(x-xn);
    rx[1]=fabs(f(eqNum, k1, k2, xn-E));
    rx[2]=fabs(f(eqNum, k1, k2, xn+E));
    if(rx[0]<E && (rx[1]>0 && rx[2]>0) || (rx[1]<0 && rx[2]<0))
      E/=10;
    if(iter==200)
      return -1;
    xn=x;
    iter++;
  }while(rx[0]>E);
  printf("iter = %d\n", iter);
  return x;
}

double df(int eqNum, double k1, double k2, double x){
  switch(eqNum){
  case 1:
    return 1/(x*log(2));
  case 2:
    return 4*powf(x,3)+k1*3*x*x-k2;
  case 3:
    return 5*powf(x,4)+2*k1*x;
  case 4:
    return 2*x+k1;
  case 5:
    return 2/(x*log(2));
  case 6:
    return 3*x*x+k1;
  default:
    return -1;
  }
}

double f(int eqNum, double k1, double k2, double x){
  
  switch(eqNum){ // Оператор switch обрабатывает 
  case 1:
    return log2f(k1*x) - k2;
  case 2:
    return powf(x,4) + k1*powf(x,3) - k2*x;
  case 3:
    return powf(x,5) + k1*powf(x,2) - k2;
  case 4:
    return powf(x, 2) + k1*x + k2;
  case 5:
    return log2f(x*x*k1) + k2;
  case 6:
    return powf(x,3)+k1*x+k2;
  default:
    return -1;
  }
  
}

void inputAndFails(int *fM, int *eN, double *k1, double *k2, double *E, double *a, double *b, double *xn){
  double cache;
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
    scanf("%lf", k1); // Ввод числа с плавающей точкой с клавиатуры
    if(*k1==0 && (*eN==1 || *eN == 5)){
      printf("k1 не может равняться 0\n");
    }
    else
      break;
  }
  printf(" k2 = "); // Вывод строки
  scanf("%lf", k2); // Ввод с клавиатуры
  
  // Ввод E
  printf("Введите точность решения уравнение E\n E = ");
  scanf("%lf", E);
  *E = fabs(*E);

  // Ввод a, b
  if(*fM == 2){ 
    printf("Введите xn\n");
    scanf("%lf", xn);
  } else {
    
    while(1){
      printf("Введите a и b\n a = ");
      scanf("%lf", a);
      printf(" b = ");
      scanf("%lf", b);

      if(*a > *b){
	cache = *a;
	*a = *b;
	*b = cache;
      }

      if(*eN == 1 && (*k1<0 && (*a>=0 || *b>=0) || *k1>0 && (*a<=0 || *b<=0))){
	printf("Должно соблюдаться условие:\nЕсли к1 < 0, a и б < 0\nЕсли к1 > 0, то а и б > 0\n");
	continue;
      }
      
      if(*a == *b){
	printf("Они не могут быть равны\b");
	continue;
      }
	
    if((f(*eN, *k1, *k2, *a) > 0 && f(*eN, *k1, *k2, *b) > 0) || (f(*eN, *k1, *k2, *a) < 0 && f(*eN, *k1, *k2, *b) < 0)){
      printf("Неподходящие а, b, либо уравнение не имеет решений\n");
      continue;
    }

    break;
  }
 }

}
