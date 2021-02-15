#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float entrada();
float funcion1(float a);
float funcion2(float a);
float funcion3(float a);
float funcion4(float a);
float funcion5(float a, float b);

int main (){
    printf("Hola, a continuacion le presentaremos el resultado de algunas funciones trigonometricas, logaritmo y potencia\n\n\n");
    float x, y;
    printf("Por favor proporcione a y el numero al que se elevara a en la potencia (b)\n\n");
    x=entrada();
    y=entrada();
    printf("El seno de a es: ");
    funcion1(x);
    printf("El coseno de a es: ");
    funcion2(x);
    printf("El tangente de a es: ");
    funcion3(x);
    printf("El logaritmo de a es: ");
    funcion4(x);
    printf("El resultado de a a la b es: ");
    funcion5(x, y);

    printf("Hasta luego");
    return 0;
}

float entrada(){
    float f;
    scanf("%f\n",&f);
    return f;
}

float funcion1(float a){
    printf("%f",sin(a));
}
float funcion2(float a){
    printf("%f",cos(a));
}
float funcion3(float a){
    printf("%f",tan(a));
}
float funcion4(float a){
    printf("%f",log(a));
}
float funcion5(float a, float b){
    printf("%f",pow(a,b));
}
