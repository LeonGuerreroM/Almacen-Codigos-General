#include <stdio.h>
#include <stdlib.h>

#define funcion1(x,y,z) (x*y-4*z+2)

int main (){
    printf("El resultado es: %f\n\n\n",funcion1(1.2,3.0,2.5)); //en lugar de pasar variables esta pasando valores
    return 0;

}
