#include<stdio.h>
#include<stdlib.h>

#define primo 1

int funcion_residuo(int numero, int i);

int main()
{
    int bandera,numero,i;
    printf("\n\nCual es el numero del que quieres saber si es primo? ");
    scanf("%d",&numero);
    i=2;
    if(numero==1){
        printf("\n\nEl numero no es primo");
    }else if(numero==2){
        printf("\n\nEl numero es primo");
    }else if(numero==3){
        printf("\n\nEl numero es primo");
    }else if(numero<0){
        printf("\n\nNo hay numeros primos negativos");
    }else{
    bandera=funcion_residuo(numero,i);
    if(bandera==primo)
        printf("\n\nEl numero es primo");
    else
        printf("\n\nEl numero no es primo");
    return 0;
}
}

int funcion_residuo(int numero, int i)
{
    int bandera;
    if(numero%i==0)
        bandera=~primo;
    else if((numero/2)==i)
        bandera=primo;
    else
        bandera=funcion_residuo(numero,++i);
    return bandera;
}
