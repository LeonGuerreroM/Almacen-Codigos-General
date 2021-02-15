#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void multiplicar(int tabla)
{
  int cont;
  for(cont=1;cont<11;cont++){
    printf("%d por %d = %d\n",tabla,cont,tabla*cont);
  }

}


int main()
{
  pid_t pid;
  int ii=1;
  int estado;

  while(ii<11){
    pid=fork();
    if(pid==-1){
      perror("Ha habido un problema: "); //impresion del error
      exit(-1); //salida
    }else if(pid==0){
      multiplicar(ii);
      exit(ii);
    }
    ii++;
  }

  ii=0;
  while(ii<10){
    pid=wait(&estado);
    ii++;
  }

}
