#include<stdlib.h>
#include<stdio.h>


int main()
{
    FILE *archivo;
    int caracter;
    char *salida="Salida.txt";
    if((archivo=fopen(salida,"wt"))==NULL)
    {
        puts("\n\nError en la apertura\n\n");
        exit(-1);
    }
    while((caracter=getchar())!=0x0A)
    {
        putc(caracter,archivo);
    }
    fclose(archivo);
    return 0;
}
