#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[80], *a;
    int i=1;
    printf("\nIntroduce una cadena: ");
    gets(S);
    printf("\nLa cadena introducida es: %s\n",S);
    printf("\nIntroduce otra cadena: ");
    a=gets(S);
    printf("\nLa cadena introducida es: %s\n",a);
    while((*a)!=NULL)
    {
        if(*a==' ')
            i++;
        a++;
    }
    printf("\nEl numero de palabras de tu cadena es: %d",i);
    return 0;
}
