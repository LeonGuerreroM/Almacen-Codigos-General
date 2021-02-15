#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	FILE *archivo;
	int regr;
	archivo=fopen("Archivo_V8.txt","r");
	fscanf(archivo,"%d",&regr);
	while(!feof(archivo))
	   {
			printf("Numero guardado: %d\n",regr);
			fscanf(archivo,"%d",&regr);
	   }
	fclose(archivo);
	return 0;
}
