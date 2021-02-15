#include <stdio.h>
#include <stdlib.h>
//el extern significa que lo puedes usar en cualquier otro lado

void leerReal(void){

    extern float f;
    printf("Introduce el valor de f \n\n\n");
    scanf("%f",&f);
}

