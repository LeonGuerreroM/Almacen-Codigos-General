#include<stdio.h>
#include<stdlib.h>

float areaRectangulo(float a, float b);
float entrada();
void salida(float area);

int main()
{
    float area,a,b;
    printf("\nCuanto vale a? ");
    a=entrada();
    printf("\nCuanto vale b? ");
    b=entrada();
    area=areaRectangulo(a,b);
    salida(area);
    return 0;
}

float entrada()
{
    float lado;
    scanf("%f",&lado);
    return lado;
}

float areaRectangulo(float a,float b)
{
    return a*b;
}

void salida(float area)
{
    printf("\nEl resultado es: %f\n\n",area);
}
