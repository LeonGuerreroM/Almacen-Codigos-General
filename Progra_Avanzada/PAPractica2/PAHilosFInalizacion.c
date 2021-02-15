#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>

int contadorGeneral=0;
int x=1,x2=1,x3=1,x4=1,x5=1;
pthread_t idHilo, idHilo2, idHilo3,idHilo4,idHilo5;

void* hilo(void *parametros);
void* hilo2(void *parametros);
void* hilo3(void *parametros);
void* hilo4(void *parametros);
void* hilo5(void *parametros);
int funcSIGUSR1(unsigned long direccion);
void impresion(int cont);

int main(){
  int contadorActivos = 5;
  unsigned long eleccion;
  //pthread_t idHilo, idHilo2, idHilo3,idHilo4,idHilo5;

  printf("Lista de ID's de hilos. Digite el que desea eliminar\n");


  pthread_create(&idHilo,NULL,hilo,NULL);
  pthread_create(&idHilo2,NULL,hilo,NULL);
  pthread_create(&idHilo3,NULL,hilo,NULL);
  pthread_create(&idHilo4,NULL,hilo,NULL);
  pthread_create(&idHilo5,NULL,hilo,NULL);

  while(contadorActivos>0){
    scanf("%lu",&eleccion);
    signal(SIGUSR1,funcSIGUSR1(eleccion));
    contadorActivos--;
  }

  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);
  pthread_join(idHilo3,NULL);
  pthread_join(idHilo4,NULL);
  pthread_join(idHilo5,NULL);



  return 0;
}

void* hilo(void *parametros){
  printf("ID: %lu\n",pthread_self()); //imprime el id de un hilo
  while(1){
    x++;
  }

  pthread_exit(0);
}
void* hilo2(void *parametros){
  printf("ID: %lu\n",pthread_self()); //imprime el id de un hilo
  int i;
  while(1){
    x2++;
  }

  pthread_exit(0);
}
void* hilo3(void *parametros){
  printf("ID: %lu\n",pthread_self()); //imprime el id de un hilo
  int i;
  while(1){
    x3++;
  }

  pthread_exit(0);
}
void* hilo4(void *parametros){
  printf("ID: %lu\n",pthread_self()); //imprime el id de un hilo
  int i;
  while(1){
    x4++;
  }

  pthread_exit(0);
}
void* hilo5(void *parametros){
  printf("ID: %lu\n",pthread_self()); //imprime el id de un hilo
  int i;
  while(1){
    x5++;
  }

  pthread_exit(0);
}

void funcSIGUSR1(unsigned long direccion){
  if(direccion==idHilo){
    contadorGeneral=x;
    impresion(contadorGeneral);
  }else if(direccion==idHilo2){
    contadorGeneral=x2;
    impresion(contadorGeneral);
  }else if(direccion==idHilo3){
    contadorGeneral=x3;
    impresion(contadorGeneral);
  }else if(direccion==idHilo4){
    contadorGeneral=x4;
    impresion(contadorGeneral);
  }else if(direccion==idHilo5){
    contadorGeneral=x5;
    impresion(contadorGeneral);
  }
}

void impresion(int cont){
  printf("El hilo llego al %d\n",cont);
}
