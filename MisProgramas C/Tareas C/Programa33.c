#include<stdio.h>
#include<stdlib.h>

float entrada();

int main(){
    printf("Mayor y Menor \n\n\n");
    printf("Introduzca los dos valores a evaluar\n\n");
    float x=entrada();
    float y=entrada();
    if(x>y){
        printf("EL numero mayor es %.2f\n\n\n",x);
        printf("EL numero menor es %.2f\n\n\n",y);
    }else if(x<y){
        printf("EL numero mayor es %.2f\n\n\n",y);
        printf("EL numero menor es %.2f\n\n\n",x);
    }else{
         printf("Los valores son iguales  \n\n\n");
    }
    return 0;
}

float entrada(){
    float n;
    scanf("%f",&n);
    return n;
}


