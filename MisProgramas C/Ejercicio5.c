#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    float x; //variables en C solo despues de una llaved
    float y;
    printf("Calculo de funciones \n\n\n");
    printf("Indique x \n\n\n");
    scanf("%f",&x);
    printf("Indique y \n\n\n");
    scanf("%f",&y);
    printf("El seno de x es: %f\n\n\n",sin(x));
    printf("El coseno de x es: %f\n\n\n",cos(x));
    printf("El tangente de x es: %f\n\n\n",tan(x));
    printf("El potencia de los numeros es: %f\n\n\n",pow(x, y));
    printf("El logaritmo de x es: %f\n\n\n",log(x));
    return 0;

}
