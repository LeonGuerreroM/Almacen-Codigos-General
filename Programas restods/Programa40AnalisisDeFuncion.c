#include<stdio.h>
#include<stdlib.h>

float entrada();


int main(){
    float x, y;
    printf("Este programa hace el analisis de una funcion en el intervalo que desees \n\n\n");
    printf("Introduce en que numero deseas comenzar a evaluar la funcion \n\n\n");
    x=entrada();
    printf("Introduce hasta que numero deseas evaluar la funcion \n\n\n");
    y=entrada();

    int i;
    for(i=x; i<=y; i++){
        printf("%f.2 \t",i);
        float r=(((2*i)+3)/5-i);
        printf("%f.2 \n",r);
    }

}

float entrada(){
    int n;
    scanf("%d",&n);
    return n;
}
