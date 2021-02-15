#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

int main()
{
    float l1, l2, l3;
    float a1, a2, a3, aux;

    printf("Calculadora de angulos \n Bienvenido, por favor ingrese los lados del triangulo \n");
    scanf("%f %f %f",&l1, &l2, &l3);
    aux=acos((pow(l1,2)+pow(l2,2)-pow(l3,2))/(2*l1*l2)); //ley de cosenos
    a1=((aux*180)/M_PI); //conversion a grados
    aux=acos((pow(l2,2)+pow(l3,2)-pow(l1,2))/(2*l2*l3));
    a2=((aux*180)/M_PI);
    aux=acos((pow(l3,2)+pow(l1,2)-pow(l2,2))/(2*l3*l1));
    a3=((aux*180)/M_PI);
    printf("Angulo 1=%f, Angulo 2=%f, Angulo 3=%f", a1, a2, a3);
    return 0;
}


