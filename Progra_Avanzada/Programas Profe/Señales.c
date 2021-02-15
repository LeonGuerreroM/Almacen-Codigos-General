#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

//Señal: interrumpcion a nivel de sistema operativo. Provoca diferentes respuestas segun el tipo de señal y es para comunicarse entre procesos

int main(){
  int procesoId;
  procesoId=fork(); //creamos el proceso Hijo
  if(procesoId==0){
    //si se crea correctamente hace lo siguiente
    while(1){
      printf("Hijo. PID=%d\n",getpid());
      //se duerme por un segundo
      sleep(1);
    }
  }
  sleep(10); //dormido 10 segundos. Cuando el padre despierta envia señal para matar al hijo. Recuerda que todo se ejecuta añl mismo tiempo
  printf("Padre. Terminacion del proceso %d\n",procesoId);
  kill(procesoId,SIGTERM);
  exit(0);
}
