#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

void manejador(void *ptr);
sem_t mutex;

//semaforo global
int contador; 	//variable compartida

int main()
{
	int i[2];
	pthread_t hilo_a,hilo_b;
//argumentos de los hilos
	i[0]=0;
	i[1]=1;
//semaforo binario
	sem_init(&mutex,0,1);
	pthread_create(&hilo_a,NULL,(void *)&manejador,(void  *)&i[0]);
	pthread_create(&hilo_b,NULL,(void *)&manejador,(void  *)&i[1]);

	pthread_join(hilo_a,NULL);
	pthread_join(hilo_b,NULL);
//se destruye el semaforo
	sem_destroy(&mutex);
	exit(0);
}

void manejador(void *ptr)
{
	int x;
	x= *((int*)ptr);
	printf("Hilo %d: Espera ingresar la región critica..\n",x);
	sem_wait(&mutex);	//Decrementa o bloquea 
	//inicia region critica
	printf("Hilo %d: Ahora en la seccion critica... \n",x);
	printf("Hilo %d: Valor del contador: %d",x,contador);
	printf("Hilo %d: Incrementa el contador...\n",x); contador++;
	printf("Hilo %d: Nuevo valor del contador: %d\n",x,contador);
	printf("Hilo %d: Saliendo de la seccion critica... \n",x);
	//Termina la seccion critica
	sem_post(&mutex);
	pthread_exit(0);
}

