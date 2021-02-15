#include<stdio.h>
#include<stdlib.h>

int entrada();


int main(){
    int x;
    printf("Triangulo de Asteriscos \n\n\n");
    printf("Introduce de cuantos asteriscos desea que sea la base \n\n\n");
    x=entrada();
    int i;
    int j;
    /*for(i=0;i<=x; i++){
        for(j=i; j<x; j++){
            printf("* ");
        }
        printf("\n");
    }*/
    for(i=0;i<=x; i++){
        for(j=i; j<x; j++){
            printf("*");
        }
        printf("\n");
    }
}

int entrada(){
    int n;
    scanf("%d",&n);
    return n;
}
