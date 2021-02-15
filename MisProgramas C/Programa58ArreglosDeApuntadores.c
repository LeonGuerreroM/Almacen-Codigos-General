#include<stdio.h>
#include<stdlib.h>

int main()
{
    char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p;
    int i;
    p=&alfabeto[0];
    for(i=0;i<sizeof(alfabeto)-1;i++,p++) //aumentar p implica aumentar la direccion en 1, no es problema porque es arreglo y sus direcciones son consecutivas
        printf("\nLa letra es: %c",*p); //muestra el contenido de la direccion qy etenga p en ese momento
    printf("\n\nLa longitud de la cadena es es: %d",i);
    return 0;
}
