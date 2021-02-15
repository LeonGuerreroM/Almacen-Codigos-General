#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int datos[100];
int contador=0,contador2=0;

void imprimir();

void *productor(void *parametros){
  while(contador<100){
    datos[contador]=(rand()%11)+1;
    printf("Productor en este caso: %d\n",datos[contador]);
    contador++;
  }
  imprimir();
  pthread_exit(0);
}

void *consumidor(void *parametros){
  while(contador>0){
    datos[contador2]=0;
    printf("Consumio");
    contador2++;
  }
  imprimir();
  pthread_exit(0);
}

int main(){
  printf("Productor Condumidor\n");
  pthread_t idHilo,idHilo2;
  pthread_create(&idHilo,NULL,productor,NULL);
  pthread_create(&idHilo2,NULL,consumidor,NULL);
  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);
  return 0;
}

void imprimir(){
  int i;
  for(i=0;i<contador;i++){
    printf("%d ",datos[i]);
  }
  printf("\n");
}
