/* Вариант 15 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){

	int a, b, g = 0;
	float d1, d2, J, K, L = 0;
	
	scanf("%d%d%d%f%f", &a, &b, &g, &d1, &d2);

	if (a != 0 && b != 0){
		J = pow(10, -2)*a*b+(2*a/(b*g))+(3*b*g/a);
		printf("J = %fn", J);
		if (d1 != 0)
		{
			K = (pow(10, -2)/(a+b))*(2/a+a/b-g/(b*d2));
			printf("K = %fn", K);
		}
		else
			printf("Выражение K не имеет смыслаn");
	}
	else
		printf("Выражения J и K не имеют смыслаn");
	
	if (d1 != -1 && d2 != -1)
	{
		L = a*b*g/(1+d1) + a*b*g/(1+d2) + 0.2;
		printf("L = %fn", L);
	}
	else
		printf("Выражение L не имеет смыслаn");
	
	system("pause");
	system("cls");
	
	return 0;
}
