#include<stdio.h>
#include<stdlib.h>

float entrada();

int main(){
    printf("Numeros ordenados de menor a mayor \n\n\n");
    printf("Introduzca tres numeros\n\n");
    float x=entrada();
    float y=entrada();
    float z=entrada();
    if(x>z && x>y && y>z){
        printf("EL numero menor es %.2f\n\n\n",z);
        printf("EL numero intermedio es %.2f\n\n\n",y);
        printf("EL numero mayor es %.2f\n\n\n",x);
    }else if(x>z && x>y && y<z){
        printf("EL numero menor es %.2f\n\n\n",y);
        printf("EL numero intermedio es %.2f\n\n\n",z);
        printf("EL numero mayor es %.2f\n\n\n",x);
    }else if(y>z && x<y && x>z){
        printf("EL numero menor es %.2f\n\n\n",z);
        printf("EL numero intermedio es %.2f\n\n\n",x);
        printf("EL numero mayor es %.2f\n\n\n",y);
    }else if(y>z && x<y && x<z){
        printf("EL numero menor es %.2f\n\n\n",x);
        printf("EL numero intermedio es %.2f\n\n\n",z);
        printf("EL numero mayor es %.2f\n\n\n",y);
    }else if(y<z && z>x && x>y){
        printf("EL numero menor es %.2f\n\n\n",y);
        printf("EL numero intermedio es %.2f\n\n\n",x);
        printf("EL numero mayor es %.2f\n\n\n",z);
    }else if(y<z && z>x && x<y){
        printf("EL numero menor es %.2f\n\n\n",x);
        printf("EL numero intermedio es %.2f\n\n\n",y);
        printf("EL numero mayor es %.2f\n\n\n",z);
    }
    return 0;
}

float entrada(){
    float n;
    scanf("%f",&n);
    return n;
}
