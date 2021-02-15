#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

#define CAPACIDAD 16

void *codigoParaHilo(void *parametros);
void yield(void);

//variables globales y compartidas
int buffer[CAPACIDAD];
pthread_mutex_t mutex;

int main(int argc, char *argv[]){
  printf("Entro al main");
  pthread_t hilo1, hilo2;
  pthread_attr_t atributos; //atributos para la creacion 
  int val[2]={4,8};
  int i;
  int error; //error para capturar 
  for(i=0;i<CAPACIDAD;i++){
    buffer[i]=0; //se llena el buffer con 0
  }
  pthread_mutex_init(&mutex, NULL);
  pthread_attr_init(&atributos);
  //printf("El valor parametro %d y %d\n", val[0], val[1]);
  error=pthread_create(&hilo1, NULL, codigoParaHilo,(void*)&val[0]);
  //verificamos si creo completamente el hilo
  if(error!=0){
    perror("NO se puede crear el hilo1");
    exit(-1);
  }
  error=pthread_create(&hilo2,NULL,codigoParaHilo,(void*)&val[1]);

  while(1){
    yield();
    //Bloqueamos la region critica
    pthread_mutex_lock(&mutex);
    for(i=0;i<CAPACIDAD;i++){
      //printf("Valores del buffer 1: %d -",buffer[i]);
      //assert, funcion que cumple que sea verdad
      assert(buffer[i]==buffer[0]);
      yield();
      //printf("Valores del buffer 2: %d -",buffer[i]);
    }
    //liberamos la region critica
    pthread_mutex_unlock(&mutex);
  }
}

void *codigoParaHilo(void *parametros){
	printf("Codigo para hilo");
	int val, i;
	val=(int*)parametros;
	while(1){
		yield();
		pthread_mutex_lock(&mutex);
		for(i=0;i<CAPACIDAD;i++){
			buffer[i]=val;
			yield();
		}
		pthread_mutex_unlock(&mutex);
		yield();
}


void yield(void){
  //Cambia el rand: 1 al 2
  int random = rand()%2;
  //printf("Entro al yield: %d\n",random);
  if(random){
	sched_yield(); //EL proceso o hilo que ejecuta dicha llamana interrumpe su ejecucion y se coloca a la cabeza de la lista de procesos listos. En el momento en que el proceso se interrumpe su ejecucion, el CPU le es asignado el proceso que estaba en la lista de procesos listos
  }
  //Se entiende que un hilo ejecuta una instruccion para despues dejar al cpu y permitir que otro hilo ejecute tambien una instruccion
}


