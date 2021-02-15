#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex; //sem_t declaracion de mutex

void* thread(void * arg){
       //wait
	sem_wait(&mutex); //bloqueo de la seccion critica
	printf("\nIngreso...\n");
       //seccion critica
	sleep(4);
	//signal
	printf("\n Justamente Saliendo... \n");
	sem_post(&mutex); //desbloqueo de la seccion critica
}

int main(){
//sem_init(sem_t *sem, int pshared, unsigned int value);
//sem : Especifica el semaforo que sera inicializado
//pshared: El argumento especifica si es inicializado un nuevo semaforo. Un valor distinto a 0 significa que el semaforo sera compartido entre procesos. Cuando es igual a 0 significa que sera compartido entre hilos
//value: especifica el valor que se le asgina al iniciar el semaforo
	sem_init(&mutex, 0, 1);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread, NULL);
	sleep(2);
	pthread_create(&st2, NULL, thread, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}
