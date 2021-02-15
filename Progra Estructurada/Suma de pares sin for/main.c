#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, s;
    printf("Suma de numeros pares hasta cierto par\n Por favor ingrese un numero (par) que sera el limite de la suma \n");
    scanf("%d",&n);
    s=(((n+2)*n)/4);
    printf("La suma es %d",s);
    return 0;
}
