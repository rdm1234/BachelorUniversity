// ��������������, ������� 15

#include <stdio.h>
#include <math.h>
#include <locale.h>

// ������� 1
void num1(){
    printf("������� 1\n");
    float a,b,c,S,P,G;

    printf("������� ������� ������������\n");
    scanf("%f%f%f",&a,&b,&c);

    if(a==b && b==c){
        S=(sqrt(3)*a*a)/4;
        printf("������� ������������ = %f\n", S);
    }
    else {
        if (a==b || a==c || b==c){
            P=a+b+c;
            printf("�������� ������������ = %f\n", P);
            if (a==b)
                G=acos((2*a*a-c*c)/(2*a*a));
            if (a==c)
                G=acos((2*a*a-b*b)/(2*a*a));
            if (b==c)
                G=acos((2*b*b-a*a)/(2*b*b));
            printf("���� ����� ������� ��������� = %f\n", G);
        }
        else
            printf("� ������������ ��� ���������� ������\n");
    }

}

// ������� 2
void num2(){
    printf("������� 2\n");
    float a,b,c, x[3], y[3], R, p;

    for (int i=0; i<3; i++){
        printf("������� �%d � �%d\n", i+1,i+1);
        scanf("%f%f", &x[i], &y[i]);
    }

    a=sqrt(pow(x[1]-x[0],2)+pow(y[1]-y[0],2));
    b=sqrt(pow(x[2]-x[1],2)+pow(y[2]-y[1],2));
    c=sqrt(pow(x[0]-x[2],2)+pow(y[0]-y[2],2));

    p=(a+b+c)/2;
    R=(a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)));

    printf("������ ��������� ���������� = %f\n", R);
}

// ������� 3
// ����� 3 ����� �� ���� ������ ������ �� �������� ��� -1<x<1 (����� inf), �������� ����� ��������
void num3(){
    printf("������� 3\n");
    double S=0,x=0,N=0;
    int k=1;

    printf("������� �������� �, �����, ��� -1 < x < 1\n");
    scanf("%lf", &x);
    do {
        N=(1/powf(10,k))*((x+2)/powf(x, k+1));
        S+=N;
        k++;
    } while(N < 0.0001 && N > -0.0001);
    printf("�������������� ����� = %f\n", S);
}


int main(){
    setlocale(LC_ALL, "Rus");

    num1();
    num2();
    num3();

    return 0;
}
