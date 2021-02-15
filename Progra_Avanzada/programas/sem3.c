#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

char mensaje[1000];
sem_t semaphore;
void *leer_mensaje();
void *escribir_mensaje();

int main()
{
	pthread_t thread_r, thread_w;
	int resultado1, resultado2;
	
	sem_init(&semaphore,0,0);
	resultado1= pthread_create(&thread_r,NULL,leer_mensaje,NULL);
	if(resultado1==0)
	{
		printf("\n Se creo el hilo 1\n");
	}
	else
	{
		perror("No se creo el hilo 1\n");
		exit(EXIT_FAILURE);
	}
	resultado2=pthread_create(&thread_w,NULL,escribir_mensaje,NULL);
	if(resultado2==0)
	{
		printf("\n Se creo el hilo 2\n");
	}
	else
	{
		perror("No se creo el hilo 2\n");
		exit(EXIT_FAILURE);
	}
	pthread_join(thread_r,NULL);
	pthread_join(thread_w,NULL);
	return 0;
}

void *leer_mensaje()
{
	while(1)
	{
		printf("\nEntrar el mensaje: ");
		scanf("%s",&mensaje);
		//sem_post incrementa o libera el semaforo
		sem_post(&semaphore);
	}
}

void *escribir_mensaje()
{
	while(1)
	{
	//sem_wait decrementa o bloquea el semaforo
		sem_wait(&semaphore);
		printf("\nMensaje: ");
		printf("%s",mensaje);
		printf("\n");
	}
}
