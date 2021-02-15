#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Protoripos
float entradaLey();

float leyG(float m1, float m2, float d, float g);
float leyOhm(float val, float res);

float salida(float f1);


//main
int main(){
printf("Hola. Bienvenido, a continuacion utilizaremos algunas leyes para obtener ciertos valores \n\n\n");
printf("Ley de gravitacion universal \n\n");
printf("Ecuacion: F=(G*((m1*m2)/d^2)) \n");
float masa1;
float masa2;
float distancia;
const float g = 6.67E-11;
float fuerzaGrav;
printf("Introduzca los valores requeridos para calcular el valor de la fuerza \n");
printf("La masa 1\n");
masa1=entradaLey();
printf("La masa 2\n");
masa2=entradaLey();
printf("La separacion entre los cuerpos\n");
distancia=entradaLey();
fuerzaGrav=leyG(masa1, masa2, distancia, g);
salida(fuerzaGrav);


printf("Ley de Coulomb \n\n");
printf("Ecuacion: F=(k*((q1*q2)/d^2)) \n");
float car1;
float car2;
float separacion;
const float k = 9E9;
float fuerzaC;
printf("Ingrese los valores requeridos para calcular la fuerza resultante con la ley de Coulomb \n");
printf("La q1: \n");
car1=entradaLey();
printf("La q2: \n");
car2=entradaLey();
printf("La separacion: \n");
separacion=entradaLey();
fuerzaC=leyG(car1, car2, separacion, k);
salida(fuerzaC);


printf("Ley de Ohm \n\n");
printf("Ecuacion: I=(V/R) \n");
float v;
float r;
float i;
printf("Por favor ingrese los valores requeridos para calcular la intensidad de corriente: \n");
printf("El voltaje  : \n");
v=entradaLey();
printf("La resistencia: \n");
r=entradaLey();
i=leyOhm(v,r);
salida(i);

printf("Hasta la proxima! \n\n\n");

system("pause");
 return 0;
}

//Inicializaciones de funcion

//Usamos una funcion para cada calculo porque se hace algo con los parametros, algo diferente utilizando diferentes valores (como las constamtes) u operaciones
//A menos que la operacion tenga la misma forma, aqui aunque las constantes son diferentes, podemos hacerla una variable que se envie con valor determinado desde el main, asi en uno se puede
//Ninguna funcion, al menos de estas, se queda con valores, solo hace lo que debe hacer y retorna, asi que son reutilizables porque no se les quedan valores definidios, son como simples procedimientos de MySQL
//Para la entrada usamos la misma funcion porque solo lee y regresa, no se queda con esos valores
//Para la salida solo toma en su parametro e imprime, tampoco se queda con esos valores, asi que se usa 1
float entradaLey(){
    float l;
    scanf("%f",&l);
    return l;
}

float leyG(float m1, float m2, float d, float c){
    return (c*((m1*m2)/pow(d,2)));
}

float leyOhm(float vel, float res){
    return vel/res;
}

float salida(float f1){
    printf("El resultado es: %.2e\n\n\n",f1);
}

