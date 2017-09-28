#include <stdio.h>

int main(){

	int a, b, g = 0;
	float d1, d2, L, K, S = 0;
	
	while ((a == 0) || (b == 0) || (g == 0) || (d2 == 0)){
		printf("Введите целые a, b, g, отличные от 0 и действиельные d1 и d2 не равное 0\n");
		scanf("%d\n%d\n%d\n%f\n%f\n", &a, &b, &g, &d1, &d2);
	}

	L = 0.5*((a*b/g) + (b/(a*g)));
	K = d1 + (((1/a)+(1/b)+(1/g))*d2*0.01);
	S = 0.6 + (d1/d2*(a+b+g));
	printf ("L = %f\nK = %f\nS = %f\n", L, K, S);
	
	system("pause");
	system("cls");
	return 0;
}
