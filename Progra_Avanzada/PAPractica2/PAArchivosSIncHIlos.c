#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

FILE *arch;
//pthread_t idHilo';

void *AbrirArchivo(void *parametros);
void *Escribir(void *parametros);

int main(){
  pthread_t idHilo2, idHilo;
  pthread_attr_t attr,attr2;

  pthread_attr_init(&attr);
  pthread_attr_init(&attr2);

  //pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
  //pthread_attr_setdetachstate(&attr2,PTHREAD_CREATE_JOINABLE);

  pthread_create(&idHilo,&attr,AbrirArchivo,NULL);
  pthread_join(idHilo,NULL);
  pthread_create(&idHilo2,&attr2,Escribir,NULL);
  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);

  return 0;
}

void *AbrirArchivo(void *parametros){
  

  arch=fopen("EjemH1.txt","w+");

  if(arch==NULL){
    printf("Error al abrir el archivo\n");
  }else{
    printf("Archivo abierto\n");
  }

  pthread_exit(0);
}

void *Escribir(void *parametros){
  char textito[] = "textito12";
  fputs(textito,arch);
  fclose(arch);

  pthread_exit(0);
}
