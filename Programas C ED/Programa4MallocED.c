#include <stdio.h>
#include <stdlib.h>

int main(){
int *p=NULL; //apuntador void
int nbytes=100;
p=(int*)malloc(nbytes); //hace cast a int del apuntador void y luego le da a malloc 100 posiciones para que las reserve
if(p==NULL)
{
	printf("Espacio insuficiente en memoria\n");
	
}
printf("Se ha asignado la memoria requerida\n");
printf("%.4x \n",p);
int i;
/*for(i=0;i<99;i++){
	p++;
	printf("%.4x \n",p);
}*/

//si reservo memoria se queda guardada SOLO para este proceso
free(p); //esto libera la memoria referida al puntador p, lo desapunta
printf("%.4x \n",p);

return 0;
}
