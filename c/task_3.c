// Рождественский, 15 вариант
#include <stdio.h>
#include <stdlib.h>

float f(float, float);

int main()
{
    float x=-1, y=-2;
    printf("x\ty\tResult\n");
    while(x<1){
        printf("%.3f\t%.3f\t%.3f\n", x,y,f(x,y));
        if(y<2)
            y+=0.5;
        else{
            x+=0.2;
            y=-2;
        }
    }
}
float f(float x, float y){
    float f=(x*x+y*y)/(x*x*x-y*y*y);
    return f;
}
