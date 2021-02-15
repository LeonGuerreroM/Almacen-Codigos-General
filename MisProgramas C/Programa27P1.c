#include <stdio.h>
#include <stdlib.h>
//guardar valores en el procesador hace el programa mucho mas rapido
extern void leerReal(void); //extern hace todo de manera externa

float f;

int main (){
    leerReal();
    printf("El resultado es: %f\n\n\n",f);
    return 0;

}
