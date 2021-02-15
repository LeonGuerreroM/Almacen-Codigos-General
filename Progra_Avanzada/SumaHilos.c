#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int suma;
void *mi_hijo(void *valor);

int main(int argc, char *argv[]){
  pthread_t id_hilo; //tipo de dato hilos
  pthread_attr_t atributo; //tipo de dato del atributo del hilo

  if(argc!=2){ //de los argumentos de entrada al ejecutar
    fprintf(stderr,"Uso: ./pthread <entero> \n");
    return -1;
  }

  pthread_attr_init(&atributo); //para definir los atributos del hilo por default. No espera despues de que el hilo termina para
  //crear un  nuevo hilo
  pthread_create(&id_hilo,&atributo,mi_hijo,argv[1]);  //direccion para que meta el id del hilo/atributos para el hilo definidos anteriormente/funcion que ejecutara el hilo/Argumentos a pasarle a la funcion que ejecutara el hilo
  pthread_join(id_hilo,NULL); //Espera la finalizacion del hilo cuyo id mandaste/ guarda en ese apuntador lo que retorno el hilo que estabas esperando. --En este caso lo usamos para que espere la terminacion del hilo antes de imprimir la suma
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
  pthread_exit(0); //Manda 0 para salir, indicando terminacion correcta del hilo
}
