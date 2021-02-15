#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcion1(float a);
float funcion2(float a);
float funcion3(float a);
float funcion4(float a);
float funcion5(float a, float b);
float salida(float resp);

int main (){
    printf("Hola, a continuacion le presentaremos el resultado de algunas funciones trigonometricas, logaritmo y potencia\n\n\n");
    float x, y;
    float r;
    printf("Por favor proporcione a y el numero al que se elevara a en la potencia (b)\n\n");
    scanf("%f",&x);
    scanf("%f",&y);
    r=funcion1(x);
    printf("El seno de a es: ");
    salida(r);
    printf("El coseno de a es: ");
    r=funcion2(x);
    salida(r);
    printf("El tangente de a es: ");
    r=funcion3(x);
    salida(r);
    printf("El logaritmo de a es: ");
    r=funcion4(x);
    salida(r);
    printf("El resultado de a a la b es: ");
    r=funcion5(x, y);
    salida(r);

    printf("Hasta luego");
    return 0;
}


//TODAS LAS FUNCIONES DEBEN DE RETORNAR ALGO!!!!!
float funcion1(float a){
    return sin(a);
}
float funcion2(float a){
    return cos(a);
}
float funcion3(float a){
    return tan(a);
}
float funcion4(float a){
    return log(a);
}
float funcion5(float a, float b){
    return pow(a,b);
}

float salida(float resp){
    printf("%f\n\n",resp);
    return 0;
}
