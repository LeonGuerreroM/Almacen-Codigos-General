#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define FILEKEY "/bin/cat"
#define KEY 1300
#define MAXBUFF 10

int main(){
	 int key = ftok(FILEKEY, KEY); //La llave indica el grupo de semaforos al cual acceder. Genera una clave de tipo key_t
					//Los parametros son 1) Nombre de un fichero 2) variable entera 
	if( key == -1){
	   fprintf(stderr,"Error en la llave \n"); //stderr standar error. Archivo en donde escribir el error
		return -1;
	}
//Creamos la memoria compartida
	int id_zone = shmget(key, sizeof(int)*MAXBUFF, 0777 | IPC_CREAT); //shmget crea la memoria compartida y devuelve el id de la zona (id, no un apuntador directo a la zona)
	//1) Clave que se le dara a los procesos que quiera acceder a la zona. 2) Tamaño de la memoria compartida 3) Permisos 
	if(id_zone == -1){
		fprintf(stderr, "Error con la Memoria compartidad \n");
		return -1;
	}

printf("ID Zona de memoria compartida: %i \n", id_zone);

int  *buffer; //compartimos el buffer
//Declaramos la zona compartida
	buffer = shmat(id_zone, (char *)0, 0); //shmat regresa un apuntador a la memoria compartida para que se asocie con alguna variable de 		un proceso (apuntador) //1)Id de la memoria compartida 2)indica (el 0) si buscar en una direccion de memoria libre 3)flags
	if(buffer == NULL){
		fprintf(stderr, "Error al reservar la Memoria compartidad \n");
		return -1;
	}

	printf("Apuntador del buffer compartido: %p\n", buffer);
//Se escribe los valores a la memoria compartida
	int i;
	for(i=0; i< MAXBUFF; i++)
		printf("%i\n",buffer[i]);
	return 0;
}

//donde escribe
