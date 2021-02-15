#include <stdio.h>
#include <stdlib.h>

int main(){
int *p=NULL; //apuntador void
int aux=sizeof(int);
/*p=(int*)calloc(100,sizeof(int));*/ //como estas funciones devuelven void se hace el cast a int y pide 100 espacios en memoria del tamaño de cada int
p=(int*)calloc(100,aux); //x localidades de y espacio de bytes
if(p==NULL)
{
	printf("Espacio insuficiente en memoria\n");
	
}
printf("Se ha asignado la memoria requerida\n");


//si reservo memoria se queda guardada SOLO para este proceso
free(p); //esto libera la memoria referida al puntador p, lo desapunta

//calloc, malloc y realloc asignan memoria de forma dinamica durante la ejecucion del programa
return 0;
}
