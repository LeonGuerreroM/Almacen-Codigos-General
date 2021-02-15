#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a=10, b=3,c;
    float x=2.0,y;
    y=x+a;
    printf("El valor de y: %f\n\n",y);
    c=a/b;
    printf("El valor de c: %d\n\n",c);
    c=a%b;
    printf("El valor de c: %d\n\n",c);
    y=a/b;
    printf("El valor de y: %f\n\n",y);
    system("pause");
    return 0;
}
