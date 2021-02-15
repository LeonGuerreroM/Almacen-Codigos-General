#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char bufer[20],opcion[3];
    int archivo,i,cuenta=0,contador=0;
    archivo=open("Archivo_V3.txt",O_WRONLY|O_CREAT,S_IWRITE|S_IREAD);
    while(1)
    {
        printf("\nEscribe una cadena: ");
        scanf("%s",bufer);
        write(archivo,bufer,sizeof(bufer));
        fflush(stdin);
        printf("\nQuieres escribir mas en el archivo [si/no]?");
    	scanf("%s",opcion);
    	cuenta++;
    	if(strcmp(opcion,"no")==0)
    	{
    	    break;
    	}
    }
    close(archivo);
    archivo=open("Archivo_V3.txt",O_RDONLY);
    while(1)
    {
        read(archivo,bufer,sizeof(bufer));
    	printf("\nLa cadena leida es: %s",bufer);
    	contador++;
    	if(contador==cuenta)
    	{
    		break;
    	}
    }
    printf("\n\n");
    close(archivo);
    return 0;
}

