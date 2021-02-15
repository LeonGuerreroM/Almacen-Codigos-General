#include<stdio.h>
#include<stdlib.h>

int entrada();


int main(){
    int x;
    printf("Este programa te ayudara a repetir una frase las veces que quieras \n\n\n");
    printf("La frase es: I will not sell miracle cures \n\n\n-");
    printf("Introduce el numero de veces que deseas repetir la frase \n\n\n");
    x=entrada();
    int i;
    for(i=0;i<x; i++){
        printf("I will not sell miracle cures \n");
    }
}

int entrada(){
    int n;
    scanf("%d",&n);
    return n;
}
