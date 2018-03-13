// Рождественский, Вариант 15
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 6

double funct(double[],double[]);

int main()
{

    int i;
    double mass1[SIZE], mass2[SIZE];

    printf("Массивы 1, 2\n");
    for(i=0;i<SIZE;i++){
        mass1[i]=rand()%1000;
        mass2[i]=rand()%1000;
        printf("%f %f\n", mass1[i], mass2[i]);
    }

    funct(mass1, mass2);

    return 0;
}

double funct(double mass1[], double mass2[])
{
    int i;
    double mass3[SIZE], sum=0;
    for(i=0;i<SIZE;i++)
    {
        mass3[i]=mass2[i]*mass1[i];
        sum+=sqrt(mass3[i]);
    }
    printf("Сумма = %f\n", sum);
    printf("3 Массив\n");
    for(i=0; i<SIZE; i++)
        printf("%f\n", mass3[i]);
    return sum;
}
