#include <stdio.h>
#include <stdlib.h>

#define funcion1(x) ((x)<-1?-(x)*(x)-3:(x)+2)

int main (){
    printf("El resultado es: %f\n\n\n",funcion1(1.2)); //en lugar de pasar variables esta pasando valores
    return 0;

}
