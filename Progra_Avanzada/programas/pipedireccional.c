#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

#define MAX 256

int main(){
	int tuberia_em_re[2]; //emisor receptor
	int tuberia_re_em[2]; //receptor emisor
	int pid;
	char mensaje[MAX];
	// creacion de tuberias de comunicación 
	if(pipe(tuberia_em_re) == -1 || pipe(tuberia_re_em) ==-1){
		perror("pipe");
		exit(-1);
		}
	//creacion de proceso hijo
	if((pid=fork())==-1){
		perror("Proceso fork");
		exit(-1);
		}
		else if(pid==0){
			//pcodigo del proceso hijo
		//el proceso hijo (receptor) se encarga de leer mensajes de la tuberia y presentarlos en pantalla. 
		//EL ciclo de lectura y presentacion  termina al leer el mensaje "FIN\n"
		while(read(tuberia_em_re[0],mensaje,MAX)>0 && strcmp(mensaje,"FIN\n")!=0)
		printf("PROCESO RECEPTOR, MENSAJE: %s\n",mensaje);
		//Enviamos al proceso emisor un mensaje para indicar que estamos listos para recibir otro mensaje
		strcpy(mensaje,"LISTO");
		write(tuberia_re_em[1],mensaje,strlen(mensaje)+1);
		close(tuberia_em_re[0]);
		close(tuberia_em_re[1]);
		close(tuberia_re_em[0]);
		close(tuberia_re_em[1]);
		exit(0);
		}else{
		//codigo del proceso padre
		//el proceso padre(emisor) se encarga de leer un mensaje de la entrada estandar y acto seguido  escribirlo en la tuberia, para que 
		//lo reciba el proceso hijo. Al escribir el mensaje "FIN \n acaban los dos procesos"
		while(printf("PROCESO EMISOR, MENSAJE: ")!=0 && fgets(mensaje,sizeof(mensaje),stdin)!=NULL && write(tuberia_em_re[1],mensaje, strlen(mensaje)+1)>0 && write(tuberia_em_re[1],mensaje,strlen(mensaje)+1)>0 && strcmp(mensaje,"FIN\n")!=0)
			//nos ponemos a esperar al mensaje "LISTO" procedente del proceso receptor
			do{
				read(tuberia_re_em[0],mensaje,MAX);
				}while(strcmp(mensaje,"LISTO\n")!=0);
			close(tuberia_em_re[0]);
			close(tuberia_em_re[1]);
			close(tuberia_re_em[0]);
			close(tuberia_re_em[1]);
			exit(0);
		}
	}
