#include<stdio.h>
#include<stdlib.h>

int main(){
    char sigma='\xE4'; //usamos codigo ASCII, la x me indica que es un hexadecimal. Declaracion de variable
    printf("La constante sigma es: %c\n\n\n",sigma); //%c pide que ahi aparezca el valor de la variable que se pone ",x" despues de que se cierran las comillas
                                                     //%c se pone porque usamos un char
    system("pause");
    return 0;
}
