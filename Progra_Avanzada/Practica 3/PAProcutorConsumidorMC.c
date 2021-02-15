#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t gate;
pthread_cond_t full;
pthread_cond_t empty;
int contenido=0;
char buffer[10000];

void* Productor(void *parametros);
void* Consumidor(void *parametros);
void llenadoSeguro();

int main(){
	 system("clear");
   pthread_t idhilo1, idhilo2;
   pthread_mutex_init(&gate,NULL);
   pthread_cond_init(&full, NULL);
   pthread_cond_init(&empty, NULL);
	 llenadoSeguro();
   pthread_create(&idhilo1, NULL, Productor, NULL);
   pthread_create(&idhilo2, NULL, Consumidor, NULL);
   pthread_join(idhilo1, NULL);
   pthread_join(idhilo2, NULL);
   pthread_mutex_destroy(&gate);
   pthread_cond_destroy(&full);
   pthread_cond_destroy(&empty);
   exit(0);
}

void* Productor(void *parametros){
	for(contenido=0;contenido<10000;contenido++){
		pthread_mutex_lock(&gate);
		buffer[contenido]=contenido+'0';
		printf("Producion\n");
		if(contenido == 100){
			pthread_cond_wait(&full, &gate); //se bloquea
		}
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&gate);
	}
	  pthread_exit(0);
}

void* Consumidor(void *parametros){
   int i;
	for(i=0;i<10000;i++){
	  pthread_mutex_lock(&gate);
	  buffer[i]='\0';
		contenido--;
		if(contenido ==0){
      pthread_cond_wait(&empty,&gate);
		}
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&gate);
		printf("Consume %c \n", i);
		}
    pthread_exit(0);
}

void llenadoSeguro(){
	int i;
	for(i=0;i<10;i++){
		buffer[i]='0'+i;
	}

}
