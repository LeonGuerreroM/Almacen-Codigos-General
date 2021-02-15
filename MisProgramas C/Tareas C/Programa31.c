#include<stdio.h>
#include<stdlib.h>

float entrada();

int main(){
    printf("Aprobado o Reprobado \n\n\n");
    printf("Introduzca una calificacion entre 0 y 10\n\n");
    float x=entrada();
    if(x>=6 && x<=10){
        printf("Calificacion Aprobatoria \n\n\n");
    }else if(x<0){
         printf("Valor fuera de los limites \n\n\n");
    }else if(x>10){
         printf("Valor fuera de los limites  \n\n\n");
    }else{
         printf("Calificacion reprobatoria \n\n\n");
    }
    return 0;
}

float entrada(){
    float n;
    scanf("%f",&n);
    return n;
}
