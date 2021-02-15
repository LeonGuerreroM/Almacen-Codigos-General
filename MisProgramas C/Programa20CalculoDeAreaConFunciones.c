//Toda programacion estructurada debe de estar compuesta de entrada, procesamiento y salida

#include<stdio.h>
#include<stdlib.h>

float areaRectangulo(float a, float b);
float entrada();
void salida (float area);

int main(){
    float area, a, b;
    printf("Cual es el valor del lado?\n\n\n");
    a=entrada();
    printf("Cual es el valor de la altura?\n\n\n");
    b=entrada();
    area=areaRectangulo(a, b);
    salida(area);
    return 0;
}

float entrada(){
    float x;
    scanf("%f",&x); //el & es para que lo guarde en la ram
    return x;
}

float areaRectangulo(float a, float b){
    return a*b;
}

void salida(float area){
    printf("El area es: %f\n\n\n",area);
}
