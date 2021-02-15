#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main(){
  void manejadorSIGINT();
  if(signal(SIGINT,manejadorSIGINT)==SIG_ERR){
    perror("Senial");
    exit(-1);
  }
  while(1){
    printf("En espera en Ctrl-C\n");
    sleep(999);
  }
}

//Metodo para el tratamiento de la Señal
void manejadorSIGINT(int senial){
  static int cnt=0;
  printf("Senial numero %d recibida \n",senial);
  if(cnt<5)
    printf("Contador=%d\n",cnt++);
  else
    exit(0);
  if(signal(SIGINT,manejadorSIGINT)==SIG_ERR){
    perror("signal");
    exit(-1);
  }
}
