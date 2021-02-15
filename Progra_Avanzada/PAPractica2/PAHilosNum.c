#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int arreglo[10];


void* generador(void *parametros);
void* ordenador(void *parametros);
void* impresor(void *parametros);

int main(){
  pthread_t idHilo, idHilo2, idHilo3;
  int i;

  pthread_create(&idHilo,NULL,generador,NULL);

  pthread_join(idHilo,NULL);

  printf("Desordenado:\n");
  for(i=0;i<10;i++){
    printf("%d ",arreglo[i]);
  }
  printf("\n");

  pthread_create(&idHilo2,NULL,ordenador,NULL);

  pthread_join(idHilo2,NULL);

  pthread_create(&idHilo3,NULL,impresor,NULL);

  pthread_join(idHilo3,NULL);

  return 0;
}

void* generador(void *parametros){
  int i;
  srand(getpid());

  for(i=0;i<10;i++){
    arreglo[i]=rand()%101;
  }

  pthread_exit(0);
}

void* ordenador(void *parametros){
  int i,j,a;

  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      if(arreglo[j+1]<arreglo[j]){
        a=arreglo[j+1];
        arreglo[j+1]=arreglo[j];
        arreglo[j]=a;
      }
    }
  }

  pthread_exit(0);
}

void* impresor(void *parametros){
  int i;

  printf("ordenado\n");

  for(i=1;i<11;i++){
    printf("%d ",arreglo[i]);
  }

  pthread_exit(0);
}
