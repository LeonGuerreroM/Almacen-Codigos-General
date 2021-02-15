#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char linea[80];
    printf("\nIntroduce una cadena: ");
    gets(linea);
    printf("\nLa linea que introdujiste fue: ");
    puts(linea); //pone una cadena de caracteres hasta el fin de linea
    return 0;
}
