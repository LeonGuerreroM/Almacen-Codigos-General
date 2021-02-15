#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//Creación (Ejecución) de nuevos proceso, mediante la función exec()
//int execv(const char *path, char *const argv[])


int main(int argc, char *argv[]){
   char *args[] = { "/sbin/shutdown", NULL};
   execv("/sbin/shutdown", args);
   printf("Se ha producido un error al ejecutar execv \n");
  return 0;
}
