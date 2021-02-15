#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	FILE *fd;
	int dato,i;
	fd=fopen("Archivo_V4.txt","w+");
	for(i=0;i<5;i++)
	{
	   fwrite(&i,sizeof(dato),1,fd);
	}
	rewind(fd); //se cierra para que a la proxima se aounte el inicio del archivo. Rewind es para que no lo cierre pero regrese al inicio
	fread(&dato,sizeof(dato),1,fd);
	while(!feof(fd))
	   {
	   printf("Grabado en el archivo %d\n",dato);
	   fread(&dato,sizeof(dato),1,fd);
	   }
	fclose(fd);
	return 0;
}
