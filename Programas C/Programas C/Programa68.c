#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//getchar solo lee un caracter
int main()
{
    char caracter;
    int i=0;
    printf("\nIntroduce una cadena: ");
    while((caracter=getchar())!='\n')
    {
        i++;
        putchar(toupper(caracter)); //putchar se utiliza para escribir caracter a caracter en pantalla, y toupper es para convertir a mayuscula
    }
    printf("\nEl numero de letras de tu cadena es: %d",i);
    return 0;
}
