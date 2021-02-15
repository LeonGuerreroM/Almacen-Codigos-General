#include <stdio.h>
#include <stdlib.h>

double Factorial (double n);


int main()
{
    double n;
    printf("Ingrese un numero");
    scanf("%lf",&n);
    if(n<0){
        printf("Ingrese un numero positivo 2Bv");
    }else{
    printf("El factorial de %lf es %lf",n,Factorial(n));
    }
    return 0;
}
double Factorial (double n){
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    }else{
        return n*Factorial(n-1);

    }






}
