#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t lleno;
pthread_cond_t vacio;
int datos[100];
int contador=0,contador2=0;

void imprimir();

void *productor(void *parametros){
  while(contador<100){
    datos[contador]=(rand()%11)+1;
    printf("Productor en este caso: %d\n",datos[contador]);
    contador++;
    pthread_mutex_lock(&mutex);
	  while(contador == 100){
	     pthread_cond_wait(&lleno, &mutex);
	  }
    pthread_cond_signal(&vacio);
    pthread_mutex_unlock(&mutex);
  }
  
  pthread_exit(0);
}

void *consumidor(void *parametros){
  while(contador>0){
    datos[contador2]=0;
    printf("Consumio");
    contador2++;
    pthread_mutex_lock(&mutex);
		while(contador ==0){
       pthread_cond_wait(&vacio,&mutex);
    }
    pthread_cond_signal(&lleno);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(0);
}

int main(){
  printf("Productor Condumidor\n");
  pthread_t idHilo,idHilo2;
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&lleno, NULL);
  pthread_cond_init(&vacio, NULL);
  pthread_create(&idHilo,NULL,productor,NULL);
  pthread_create(&idHilo2,NULL,consumidor,NULL);
  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&lleno);
  pthread_cond_destroy(&vacio);
  return 0;
}
