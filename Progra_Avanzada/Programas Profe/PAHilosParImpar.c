#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int *contPar, *contImpar;

void *pares(void *parametros){
  int i=1,contador=0;

  while(i<101){
    if(i%2==0){
      contador++;
    }
  }
  parametros=&contador;
  pthread_exit(parametros);
}

void *impares(void *parametros){
  int i=1,co
printfntador=0;

  while(i<101){
    if(i%2!=0){
      contador++;
    }
  }
  parametros=&contador;
  pthread_exit(parametros);
}

int main(){
  pthread_t idHilo,idHilo2;


  pthread_create(&idHilo,NULL,pares,NULL);
  pthread_join(idHilo,(void**)&contPar);
  printf("El numero de pares es: %d\n",*contPar);
  pthread_create(&idHilo,NULL,impares,NULL);
  pthread_join(idHilo2,(void**)&contImpar);
  printf("El numero de pares es: %d\n",*contImpar);

  return 0;
}
