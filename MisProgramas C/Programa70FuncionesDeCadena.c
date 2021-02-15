#include<stdio.h>
#include<stdlib.h>
#include<string.h> //funciones de cadena

int main()
{
    char linea[80]="Esta es una cadena larga";
    char cadena[80];
    char cadena2[80];
    char *c=linea;
    printf("\nLa variable linea tiene: %s",linea);
    printf("\nLa variable cadena tiene: %s",cadena);
    strcpy(cadena,linea);
    printf("\nLa variable cadena tiene: %s",cadena);
    strncpy(cadena2,linea,11);
    printf("\nLa variable cadena2 tiene: %s",cadena2);
    c+=12;
    strncpy(cadena2,c,7);
    printf("\nLa variable cadena2 tiene: %s",cadena2);
    printf("\nEl tamano de cadena2 es: %d\n",strlen(cadena2));
    return 0;
}
