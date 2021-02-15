#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
printf("Hola. Bienvenido, a continuacion utilizaremos algunas leyes para obtener ciertos valores \n\n\n");
printf("Ley de gravitacion universal \n\n");
printf("Ecuacion: F=(G*((m1*m2)/d^2)) \n");
const float g = 6.67E-11;
float m1 = 6.5;
float m2= 4.6;
float d = 50.1;
printf("Se mostrara el resultado de la fuerza f teniendo como valores: \n");
printf("Constante G: %.2e\n",g);
printf("La masa 1:  %.2f\n",m1);
printf("La masa 2:  %.2f\n",m2);
printf("La separacion entre los cuerpos:  %.2f\n",d);

float f = (g*((m1*m2)/pow(d,2)));
printf("El valor de la fuerza F es igual a:  %e\n\n\n",f);



printf("Ley de Coulomb \n\n");
printf("Ecuacion: F=(k*((q1*q2)/d^2)) \n");
const float k = 9E9;
float q1 = 4837.92;
float q2= 39282.34;
float d1 = .34;
printf("Se mostrara el resultado de la fuerza f teniendo como valores: \n");
printf("Constante K: %.2e\n",k);
printf("La q1:  %.2f\n",q1);
printf("La q2:  %.2f\n",q2);
printf("La separacion:  %.2f\n",d1);

float f1 = (k*((q1*q2)/pow(d1,2)));
printf("El valor de la fuerza F es igual a:  %e\n\n\n",f1);



printf("Ley de Ohm \n\n");
printf("Ecuacion: I=(V/R) \n");
float v = .23937;
float r= .0000123;
printf("Se mostrara el resultado de la Intensidad de corriente teniendo como valores: \n");
printf("El voltaje:  %f\n",v);
printf("La resistencia:  %f\n",r);
float i = v/r;
printf("El valor de la Intensidad de Corriente es igual a:  %f\n\n\n",i);

printf("Hasta la proxima! \n\n\n");

system("pause");
return 0;
}

