#include<stdio.h>
#include<stdlib.h>

#define funcion1(x) (x*x-4*x+2)

float funcion2(float valor);

int main()
{
    float valor=1.8, resultado;
    printf("\nAl evaluar %f en la funcion 1 el resultado es: %f\n\n",valor, funcion1(valor));
    printf("\nAl evaluar %f en la funcion 2 el resultado es: %f\n\n",valor, funcion2(valor));
    valor=1.2;
    resultado=funcion2(valor);
    printf("\nAl evaluar %f en la funcion 2 el resultado es: %f\n\n",valor, resultado);
    return 0;
}

float funcion2(float x)
{
    return (x*x-4*x+2);
}
