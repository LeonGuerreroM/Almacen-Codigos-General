#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float vel, ang, aux, dist;

    printf("Calculadora de la distancia de un proyectil \n");
    printf("Por favor ingrese la velocidad inicial \n");
    scanf("%f",&vel);
    printf("Por favor ingresew el valor del angulo en grados\n");
    scanf("%f",&ang);

    aux=((ang*M_PI)/180);

    dist=((pow(vel,2)*sin(aux*2))/9.81);

    printf("El valor de la distancia es %.3f \n",dist);

    return 0;
}
