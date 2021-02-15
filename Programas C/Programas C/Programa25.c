#include<stdio.h>
#include<stdlib.h>

#define funcion1(x,y,z) (x*y-4*z+2)

int main()
{
    float valor=1.8, resultado;
    printf("\nEl resultado es: %f\n\n",funcion1(1.2,3.0,2.5));
    return 0;
}
