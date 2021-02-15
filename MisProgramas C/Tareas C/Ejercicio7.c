#include<stdio.h>
#include<stdlib.h>

float tecleaNumero();
int tecleaNumero1();
float multRecursiva(float x, int y);

int main(){
    printf("Bienvenido. A continuacion se calculara una multiplicacion de manera recursiva\n\n\n");
    printf("Primero, digite A\n\n\n");
    float a;
    a=tecleaNumero();
    printf("Ahora teclee B\n\n\n");
    float b;
    b=tecleaNumero1();
    float c;
    c=multRecursiva(a,b);
    printf("El resultado de la multiplicacion es: %.2f\n\n\n",c);
    printf("Hasta Luego");
    return 0;
}

float tecleaNumero(){
    float x;
    scanf("%f", &x);
    return x;
}

int tecleaNumero1(){
    int x;
    scanf("%d", &x);
    return x;
}

float multRecursiva(float x, int y){
    if(x==0 || y==0)
        return 0;
    else{
        /*int i;
        int z=(y-1);
        for(i=1;i<=z;i++)*/
       return x+multRecursiva(x,(y-1));
    }

}
