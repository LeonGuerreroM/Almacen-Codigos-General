#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int suma;
void *mi_hijo(void* valor);

int main(int argc, char *argv[]){
  pthread_t id_hilo;
  pthread_attr_t atributo;

  if(argc!=2){
    fprintf(stderr,"Uso: ./pthread <entero>\n");
    return -1;
  }

  pthread_attr_init(&atributo);
  //crear un  nuevo hilo
  pthread_create(&id_hilo,_&atributo,mi_hilo_argv[1]);
  pthread_join()(id_hilo,NULL); //Espera la finalizacion
  printf("Suma total: %d\n",suma);
  return 0;
}

void *mi_hijo(void *valor){
  int i, ls;
  ls=atoi(valor);
  i=0, suma =0;
  while(i<=ls){
    suma+=(i++);
  }
  pthread_exit(0);
}
