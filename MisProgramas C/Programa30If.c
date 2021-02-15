#include<stdio.h>
#include<stdlib.h>

#define primo 1

int funcion_residuo(int numero, int i);

int main(){
    int bandera,numero, i;
    printf("Autenticacion de numero primo\n\n\n");
    printf("Indica el numero a comprobar\n\n\n");
    scanf("%d",numero);
    i=2;
    bandera=funcion_residuo(numero, i);
    if(bandera==primo)
        printf("El numero es primo");
    else
        printf("El numero no es primo");

    return 0;
}

int funcion_residuo(int numero, int i){

    int bandera;
    if(numero%i==0)
        bandera=primo;
    else if((numero/2)==i)
        bandera=~primo;
    else
        bandera=funcion_residuo(numero, ++i); //Esto es RECURSIVIDAD que es lo que llama a la funcion dentro de la misma funcion pero asignandole otros valores que es como crear otra funcion
//lo de la ++i hace que primero se aumente y luego lo mande, si fuera i++ lo manda y luego lo aumenta asi que no funcionaria.
    return bandera;

}
