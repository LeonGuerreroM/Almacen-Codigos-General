#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//malloc Asignacion de memoria
//memoria dinamica
//asigna bloques de memoria. 1 Bloque = 1 Byte. Devuelve direccion
int main()
{
    char cadena[80];
    char *apuntador;
    int longitud;
    puts("\nIntroduce una linea: ");
    gets(cadena);
    longitud=strlen(cadena);
    apuntador=/*como malloc devuelve void, este char es para convertir el apuntador a tipo char y asignar a apuntador*/(char*)malloc((longitud+1)/*multiplicado*/*sizeof(char));//sizeof char es igual a 1
    strcpy(apuntador,cadena);
    printf("\nEl apuntador tiene: %s",apuntador);
    free(apuntador); //free es para liberar la memoria que me da mlloc
    return 0;
}
