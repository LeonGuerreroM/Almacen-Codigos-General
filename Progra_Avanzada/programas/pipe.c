#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#define MAX 256
int main(){
	int tuberia[2];
	int pid;
	char mensaje[MAX];
	// creacion de la tuberia (pipeline) sin nombre
	if(pipe(tuberia)==-1){
		perror("pipe");
		exit(-1);
		}
	// creacion del proceso hijo
	if((pid=fork())==-1){
		perror("Proceso fork");
		exit(-1);
		}
		else if(pid==0){
			//pcodigo del proceso hijo
		//el proceso hijo (receptor) se encarga de leer mensajes de la tuberia y presentarlos en pantalla. 
		//EL ciclo de lectura y presentacion  termina al leer el mensaje "FIN\n"
		while(read(tuberia[0],mensaje,MAX)>0 && strcmp(mensaje,"FIN\n")!=0)
		printf("PROCESO RECEPTOR, MENSAJE: %s\n",mensaje);
		close(tuberia[0]);
		close(tuberia[1]);
		exit(0);
		}else{
			//codigo proceso padre
			//el proceso padre emisor
			while(printf("PROCESO EMISOR, MENSAJE: %s \n",mensaje)!=0 &&fgets(mensaje,sizeof(mensaje),stdin)!=NULL&& write(tuberia[1],mensaje,strlen(mensaje)+1)>0 && strcmp(mensaje,"FIN\n")!=0)

			close(tuberia[0]);
			close(tuberia[1]);
			exit(0);	
			}
	}		
