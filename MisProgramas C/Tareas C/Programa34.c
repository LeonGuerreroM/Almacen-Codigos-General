#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float entrada();
float funcion1(float a, float b, float c);
float funcion2(float a, float b, float c);
float salida(float resp);

int main(){
    float x, y, z;
    float r, s;
    printf("Calculadora de ecuaciones de segundo grado\n\n\n");
    printf("Ingrese a, b y c de la ecuacion\n");
    x=entrada();
    y=entrada();
    z=entrada();
    if((sqrt(pow(y,2)-(4*x*z)))>=0){
    r=funcion1(x, y, z);
    r=funcion1(x, y, z);
    salida(r);
    salida(s);
    }else{
    printf("Los resultados obtenidos son imaginarios");
    }
    return 0;
}

float entrada(){
    float n;
    scanf("%f",&n);
    return n;
}

float funcion1(float a, float b, float c){
   float q;
   q=((-b+sqrt(pow(b,2)-(4*a*c)))/2*a);
   return q;
}

float funcion2(float a, float b, float c){
   float q;
   q=((-b-sqrt(pow(b,2)-(4*a*c)))/2*a);
   return q;
}

float salida(float resp){
    printf("El resultado es: %f\n\n\n",resp);
}


