#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(){
printf("Uso del Pause %d\n",getpid());
//Señal de usuario
  void manejadorSIGUSR1();
//Señal de termino
  void manejadorSIGTERM();

  signal(SIGUSR1, manejadorSIGUSR1);
  signal(SIGTERM, manejadorSIGTERM);

  while(1){
    pause();
  }
}

//Imprime un mensaje y termina el proceso
void manejadorSIGTERM(int senial){
  printf("rec_Senialterm; %d \n",senial);
  printf("Terminacion de proceso %d a peticion del usuario \n",getpid());
  exit(-1);
}


//Presentara un numero aleatorio
void manejadorSIGUSR1(int senial){
  printf("senial del manejador: %d \n",senial);
  signal(senial,SIG_IGN);
  printf("Numero random %d\n",rand());
  signal(senial,manejadorSIGUSR1);
}
