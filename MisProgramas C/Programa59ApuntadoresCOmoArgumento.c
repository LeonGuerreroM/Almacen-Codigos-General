#include<stdio.h>
#include<stdlib.h>

int funcion(int a, int *b);

int main()
{
    int a, *b, c;
    a=10;
    c=20;
    b=&c;
    printf("\n\nValores iniciales de a= %d b=%d c=%d\n",a,*b,c);
    a=funcion(a,b);
    printf("\n\nValores finales de a= %d b=%d c=%d\n",a,*b,c);
    return 0;
}

int funcion(int a, int *b)
{
    a=400;
    *b=1000;
    return a;
}
