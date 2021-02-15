#include<stdio.h>
#include<stdlib.h>

void convierte_mayusculas(char cadena[]);

int main()
{
    char a[]="esta es la cadena en minusculas";
    printf("\n%s\n",a);
    convierte_mayusculas(a);
    printf("\n%s\n",a);
    return 0;
}

void convierte_mayusculas(char cadena[])
{
    int i=0;
    int intervalo='a'-'A';
    while(cadena[i])
    {
        cadena[i]=(cadena[i]>='a' && cadena[i]<='z')? cadena[i]-intervalo:cadena[i];
        i++;
    }
}
