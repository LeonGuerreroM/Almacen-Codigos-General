#include <stdio.h>
#include <stdlib.h>

#define funcion1(x,y) ((3.1416*pow(x,2)*y)/3)

int main (){
    float r; //variables en C solo despues de una llave
    float h;
    printf("Calculo del volumen de un cono \n\n\n");
    printf("Indique el radio del cono \n\n\n");
    scanf("%f",&r);
    printf("Indique la altura del cono \n\n\n");
    scanf("%f",&h);
    printf("El resultado es: %.2f\n\n\n",funcion1(r, h));
    return 0;

}
