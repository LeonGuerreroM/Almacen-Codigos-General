#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<errno.h>
#include<sys/shm.h>

#define FILEKEY "/bin/cat"
#define KEY 1300
#define MAXBUFF 10

int main()
{
	int key=ftok(FILEKEY, KEY);
	if(key==-1)
	{
		fprintf(stderr,"Error con la llave\n");
		return -1;
	}
	//Creamos la memoria comaprtida
	int id_zone =shmget(key, sizeof(int)*MAXBUFF,0777|IPC_CREAT);
	if(id_zone==-1)
	{
		fprintf(stderr, "Error con la memoria compartida\n");
		return -1;
	}
	printf("ID Zona de memoria compartida: %i \n", id_zone);
	int *buffer; //buffer compartido
	//declaramos la zona compartida
	buffer=shmat(id_zone,(char*)0,0);
	if(buffer==NULL)
	{
		fprintf(stderr, "Error en reservar memoria compartida \n");
		return -1;
	}
	printf("Apuntador del buffer compartido: %p \n",buffer);
	int i;
	for(i=0;i<MAXBUFF;i++)
		printf("%i\n",buffer[i]);
	return 0;
}

