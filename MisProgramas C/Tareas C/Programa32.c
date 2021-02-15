#include<stdio.h>
#include<stdlib.h>

float entrada();

int main(){
    printf("Mayor, menor o igual \n\n\n");
    printf("Introduzca un numero\n\n");
    float x=entrada();
    if(x>0){
        printf("Numero mayor a 0 \n\n\n");
    }else if(x<0){
         printf("Numero menor a 0 \n\n\n");
    }else{
         printf("Igual a 0 \n\n\n");
    }
    return 0;
}

float entrada(){
    float n;
    scanf("%f",&n);
    return n;
}
