#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Protoripos
float entradaLey();

float leyG(float m1, float m2, float d);

float salida(float f1);


//main
int main(){
printf("Hola. Bienvenido, a continuacion utilizaremos algunas leyes para obtener ciertos valores \n\n\n");
printf("Ley de gravitacion universal \n\n");
printf("Ecuacion: F=(G*((m1*m2)/d^2)) \n");
float masa1;
float masa2;
float distancia;
float fuerzaGrav;
printf("Introduzca los valores requeridos para calcular el valor de la fuerza \n");
printf("La masa 1\n");
masa1=entradaLey();
printf("La masa 2\n");
masa2=entradaLey();
printf("La separacion entre los cuerpos\n");
distancia=entradaLey();
fuerzaGrav=leyG(masa1, masa2, distancia);
salida(fuerzaGrav);

























system("pause");
 return 0;
}

//Inicializaciones de funcion
float entradaLey(){
    float l;
    scanf("%f",&l);
    return l;
}

float leyG(float m1, float m2, float d){
    const float g = 6.67E-11;
    return (g*((m1*m2)/pow(d,2)));
}

float salida(float f1){
    printf("El valor de la fuerza de gravitacion es: %e\n\n\n",f1);
}

