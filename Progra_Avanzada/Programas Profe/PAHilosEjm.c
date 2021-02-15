#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_HILOS;
int I=0;

void *codigo_para_hilo(void *id_hilo){
  int i;
  for(i=0;i<5;i++){
    printf("Hilo %d: i=%d, I=%d\n",*(int*)id_hilo,i,I++);
  }
  pthread_exit(id_hilo);
}

int main(){
  int indice_hilos;
  pthread_t hilos [NUM_HILOS];
  int arr_id[NUM_HILOS]={1,2,3,4,5};
  int error;
  int *salida;

  for(indice_hilos=0;indice_hilos<NUM_HILOS;indice_hilos++){
    //Creamos los hilos
    error=pthread_create(&hilos[indice_hilos],NULL,codigo_para_hilo,&arr_id[indice_hilos]);
    //comprobamos si realizo correctamente la creacion
    if(error){
      fprintf(stderr,"Error %d: %s\n",error,sterror(error));
    }
  }
  for(indice_hilos=0;indice_hilos<NUM_HILOS;indice_hilos++){
    //creamos los hilos
    error=pthread_join(hilos[indice_hilos],(void**)&salida);
    //comprobamos si realizo correctamente la creacion
    if(error){
      fprintf(stderr,"Error %d: %s\n",error,sterror(error));
    }else{
      printf("Hilo %d terminado\n",*salida);
    }
  }
  return 0;
}
