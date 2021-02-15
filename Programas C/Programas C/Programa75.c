#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *apuntador;
    int tam;
    tam=(strlen("\nEsta es una cadena ")+1)*sizeof(char);
    apuntador=(char*)malloc(tam); //tantos bloques como tamaño acabo de calcular
    //La segunda parte del malloc calcula cuantis bliques de memoria tengo que reservar
    strcpy(apuntador,"Esta es una cadena ");
    puts(apuntador);
    tam+=(strlen("de prueba\n")+1)*sizeof(char);
    apuntador=(char*)realloc(apuntador,tam);
    strcat(apuntador,"de prueba\n");
    puts(apuntador);
    free(apuntador);
    return 0;
}
