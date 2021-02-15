#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
//utiliza parejas de write read open. Fputs, fgets. fscan,f orintf.
int main()
{
    char bufer[20],opcion[3];
    int archivo,i,cuenta=0,contador=0;
    archivo=open("Archivo_V3.txt",O_WRONLY|O_CREAT,S_IWRITE|S_IREAD); //permisos de open
    while(1) //bucke infinito
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
        read(archivo,bufer,sizeof(bufer)); //el arreglo no lleva &
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

