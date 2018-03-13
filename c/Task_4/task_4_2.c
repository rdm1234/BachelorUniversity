// Рождественский, Вариант 15, задание 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funct(int[][2]);

int main()
{
    int A[4][2], i, i2;
    for(i=0;i<4;i++)
    {
        for(i2=0;i2<2;i2++)
            scanf("%d", &A[i][i2]);
    }

    for(i=0;i<4;i++)
    {
        for(i2=0;i2<2;i2++)
            printf("%d\n", A[i][i2]);
    }

    funct(A);
    return 0;
}

int funct(int A[][2])
{
    int max=0, i, i2,sum, num;
    for(i=0;i<4;i++){
        sum=0;
        for(i2=0;i2<2;i2++){
            sum+=A[i][i2];
        }
        if(abs(sum)>max){
            max=abs(sum);
            num=i;
        }
    }
    printf("num = %d\n%d %d\n", num, A[num][0],A[num][1]);
    return num;
}
