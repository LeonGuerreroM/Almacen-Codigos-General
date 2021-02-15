#include<stdio.h>
#include<stdlib.h>

void funcion1(int *a);

int main()
{
    int a=18;
    printf("\nLa variable a en main vale: %d\n\n",a);
    funcion1(&a);
    printf("\nLa variable a en main ahora vale: %d\n\n",a);
    return 0;
}

void funcion1(int *a)
{
    *a=*a+10;
    printf("\nLa variable a en funcion1 vale: %d\n\n",*a);
}
