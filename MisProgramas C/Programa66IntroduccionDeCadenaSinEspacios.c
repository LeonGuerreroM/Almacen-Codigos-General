#include<stdio.h>
#include<stdlib.h>
//gets para espacios, pero sin numeros
int main()
{
    char S[20];
    float i;
    printf("\nIntroduce una cadena: ");
    gets(S);
    printf("\nLa cadena introducida es: %s\n",S);
    printf("\nIntroduce un numero: ");
    gets(S);
    i=(float)S;
    printf("\nEl numero introducida es: %d\n",S);
    return 0;
}
