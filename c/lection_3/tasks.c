// Рождественский
// В этом файле задания 3.6-3.11, но 3.8 в отдельном файле (там бесконечный цикл)
// В некоторых заданиях делал long int чтобы можно было проверять и большие числа

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функци, ставящаяя паузу и очищающая экран (использую после каждого задания);
void wnc(){
	printf("\nНажмите любую клавишу для продолжения\n");
	system ("pause");
	system ("cls");
}

// Задание 3.6
void task3_6(){
	long int a;
	int i=0;
	printf("Введите число для проверки количества цифр 7 в нём\n");
	scanf("%ld", &a);

	while(a>0){
		if(a%10 == 7)
			i++;
		a/=10;
	}
	
	printf("Семь встречается %d раз\n", i);
	wnc();
}

// Задание 3.7
void task3_7(){
	int a,b,c=0;
	printf("Введите число в 10 системе счисления\n");
	scanf("%d", &a);
	b = a;
	// Считыается количество цифр двоичного кода для объявления массива
  while (a>0){
		c++;
		a/=2;
  }
  int d[c];
  a=c;
	
  c--;
  while (c>-1){
		if(b%2!=0){
			d[c]=1;
		  b--;
		}
    else
			d[c]=0;

    b=b/2;
		c--;
  }
	
  c=0;
	printf("Число в 2 СС = ");
  while (c<a){
  	printf("%d", d[c]);
  	c++;
  }
	wnc();
}

// Задание 3.9
void task3_9(){
	int a,b,c;
	printf("Введите 3 целых ненулевых числа\n");
	scanf("%d%d%d", &a, &b, &c);

	a*=a;
	b*=b;
	c*=c;
	if (a == b+c || b == a+c || c == a+b)
		printf("Треугольник является прямоугольным\n");
	else
		printf("Треугольник не является прямоугольным\n");
	wnc();
}

// Задание 3.10
long int fac(int n){
	long int f;
	f=n;

	while(n>1){
		f*=(n-1);
		n--;
	}

	return f;
}

// Задание 3.11
// В задании не указано с какой точностью, поэтому написа до 1/10!
void task3_11(){
	int i=1;
	float e=1;

	while (i<=10){
		e = e + (1/(float)fac(i));
		i++;
	}
	printf("Число е примерно равно %f\n", e);
	wnc();
}


int main(){
  setlocale(LC_ALL, "Rus");
	int n;
	
	printf("Задание 3.6\n");
	task3_6();
	
	printf("Задание 3.7\n");
  task3_7();
	
	printf("Задание 3.9\n");
	task3_9();
	
	printf("Задание 3.10\n");
	printf("Введите число для вычисления фактариала\n");
	scanf("%d", &n);
	printf("Факториал числа n = %ld\n", fac(n));
	wnc();
	
	printf("Задание 3.11\n");
	task3_11();

	return 0;
}
