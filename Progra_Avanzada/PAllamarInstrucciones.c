#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int ii=0;
  int estado;
  int pid;

  while(ii<3){
    pid=fork();
    if(pid==-1){
      perror("Ha habido un problema: "); //impresion del error
      exit(-1); //salida
    }else if(pid==0 && ii==0){
      char *args[] = { "/bin/ls", NULL};
      execv("/bin/ls", args);
      exit(1);
    }else if(pid==0 && ii==1){
      char *args[] = { "/bin/pwd", NULL};
      execv("/bin/pwd", args);
      exit(1);
    }else if(pid==0 && ii==2){
      chdir("Documentos");
      char *args[] = { "/bin/pwd", NULL};
      execv("/bin/pwd", args);
      exit(1);
    }
    ii++;
  }

  ii=0;
  while(ii<10){
    pid=wait(&estado);
    ii++;
  }


}
