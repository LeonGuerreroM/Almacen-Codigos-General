#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int ii=0,x=1;
  int estado;
  int pid;

  while(x==1){
    printf("Opciones\n1. Crear la carpeta\n2. Crear el documento\n3. Escribir el mensaje en el documento\n");
    fflush(stdin);
    scanf("%d",&ii);
    fflush(stdin);
    pid=fork();
    if(pid==-1){
      perror("Ha habido un problema: "); //impresion del error
      exit(-1); //salida
    }else if(pid==0 && ii==1){
      char *args[] = { "/bin/mkdir","Ejemplo",NULL}; //el args guarda todos los parametros que se han de enviar a la instruccion
      execv("/bin/mkdir", args);
      exit(1);
    }else if(pid==0 && ii==2){
      char *args[] = { "/bin/touch", "ejemplo.txt", NULL};
      chdir("Ejemplo");
      execv("/bin/touch", args);
      exit(1);
    }else if(pid==0 && ii==3){
      FILE *arch;
  	    char escrito[] = "Mensaje de prueba";
      chdir("Ejemplo");
  	    arch = fopen ( "ejemplo.txt", "r+" );
  	    fputs(escrito, arch);
  	    fclose (arch);
      exit(1);
    }
    printf("Repetir?[S=1,N=2]\n");
    fflush(stdin);
    scanf("%d",&x);
    fflush(stdin);
  }

  pid=wait(&estado);

}
