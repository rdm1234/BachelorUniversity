// ��������������
// � ���� ����� ������� 3.6-3.11, �� 3.8 � ��������� ����� (��� ����������� ����)
// � ��������� �������� ����� long int ����� ����� ���� ��������� � ������� �����

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// ������, ��������� ����� � ��������� ����� (��������� ����� ������� �������);
void wnc(){
	printf("\n������� ����� ������� ��� �����������\n");
	system ("pause");
	system ("cls");
}

// ������� 3.6
void task3_6(){
	long int a;
	int i=0;
	printf("������� ����� ��� �������� ���������� ���� 7 � ��\n");
	scanf("%ld", &a);

	while(a>0){
		if(a%10 == 7)
			i++;
		a/=10;
	}
	printf("���� ����������� %d ���\n", i);
	wnc();
}

// ������� 3.7
void task3_7(){
	int a,b,c=0;
	printf("������� ����� � 10 ������� ���������\n");
	scanf("%d", &a);
	b = a;
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
    printf("����� � 2 �� = ");
    while (c<a){
        printf("%d", d[c]);
        c++;
    }

    wnc();

}

// ������� 3.9
void task3_9(){
	int a,b,c;
	printf("������� 3 ����� ��������� �����\n");
	scanf("%d%d%d", &a, &b, &c);

	a*=a;
	b*=b;
	c*=c;
	if (a == b+c || b == a+c || c == a+b)
		printf("����������� �������� �������������\n");
	else
		printf("����������� �� �������� �������������\n");
	wnc();
}

// ������� 3.10
long int fac(int n){
	long int f;
	f=n;

	while(n>1){
		f*=(n-1);
		n--;
	}

	return f;
}

// ������� 3.11
// � ������� �� ������� � ����� ���������, ������� ������ �� 1/10!
void task3_11(){
	int i=1;
	float e=1;

	while (i<=10){
		e = e + (1/(float)fac(i));
		i++;
	}
	printf("����� � �������� ����� %f\n", e);
	wnc();
}


int main(){
        long int a=2;
    while (1){
        printf("%ld, ", a++);
    }
    setlocale(LC_ALL, "Rus");
	int n;
	task3_6();
    task3_7();
	task3_9();
	printf("������� ����� ��� ���������� ����������\n");
	scanf("%d", &n);
	printf("��������� ����� n = %ld\n", fac(n));
	wnc();
	task3_11();

	return 0;
}
