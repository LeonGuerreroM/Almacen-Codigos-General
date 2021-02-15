#include <stdio.h>
#include <stdlib.h>

int fibos (int ant1, int ant2, int n);
int fibosV2(int n);


int main()
{
    int n;
    printf("Ingrese un numero");
    scanf("%d",&n);
    printf("El elemento %d de la secuencia de Fibonacci es %d",n,/*fibos(1,0,n)*/fibosV2(n));
    return 0;
}

int fibos (int ant1, int ant2, int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return ((ant1,ant2)+fibos(ant2,ant1+ant2,n-1));
}

int fibosV2(int n){
    if(n==1)
        return 0;
    if(n==2){
        return 1;
    }
    else
        return (fibosV2(n-1)+fibosV2(n-2));

}
