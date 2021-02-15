#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>

#define FILEKEY "/bin/cat"
#define KEY 1300
#define MAXBUFF 10

int main(){
 //LLAVE PARA COMPARTIR MEMORIA
	int key = ftok(FILEKEY, KEY);
	if(key == -1){
		fprintf(stderr ,"Error con la llave \n");
		return -1;
	}
//Creamos la memoria compartida
	int id_zone = shmget(key, sizeof(int)*MAXBUFF, 0777 | IPC_CREAT);
	if(id_zone == -1){
		fprintf(stderr, "Error con la Memoria compartidad \n");
		return -1;
	}
	
	printf("ID Zona de memoria compartida: %i \n", id_zone);

	int *buffer; //buffer compartido
	buffer = shmat(id_zone, (char*)0,0);
	if(buffer == NULL){
		fprintf(stderr, "Error en reservar memoria compartida \n");
	return -1;
	}
	printf("puntero de buffer (memoria compartidad): %p\n", buffer);
	int i;
	for(i=0; i< MAXBUFF; i++)
		buffer[i]=i; //lo maneja como arreglo porque la zona reservada es en realidad un arreglo de direcciones de memoria
//se ejecuta hasta que se reciba una tecla
	char c;
	c= getchar(); //pide caracteres uno a uno desde consola

//Liberamos la memoria
	shmdt((char*)buffer); //Desata la zona de memoria, el buffer (o variable apuntador) deja de tener acceso a la memoria
	shmctl(id_zone, IPC_RMID, (struct shmid_ds*)NULL); //elimina la zona de memoria compartida. 1)Id de zona de memoria a borrar 2)Comp5ortamiento de borrado 3)Ponle 0

	return 0;

}
