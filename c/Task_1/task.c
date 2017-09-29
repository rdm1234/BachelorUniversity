/* Вариант 15 */

#include <stdio.h>
#include <math.h>

int main(){

	int a, b, g = 0;
	float d1, d2, J, K, L = 0;
	
	while ((a == 0) || (b == 0) || (g == 0) || (d2 == 0)){
		printf("Введите целые a, b, c, отличные от 0 и действиельные A и B не равное 0\n");
		scanf("%d\n%d\n%d\n%f\n%f\n", &a, &b, &g, &d1, &d2);
	}

	J = pow(10, -2)*a*b+(2*a/(b*g))+(3*b*g/a);
	K = (pow(10, -2)/(a+b))*(2/a+a/b-g/(b*d2));
	L = a*b*g/(1+d1) + a*b*g/(1+d2) + 0.2;
	printf ("J = %f\nK = %f\nL = %f\n", J, K, L);
	
	return 0;
}
