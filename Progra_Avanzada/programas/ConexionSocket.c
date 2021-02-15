#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
	int descriptor_socket;//descriptor del socket
	struct sockaddr_in servidor; //direccion del servidor 
	//creamos socket
	descriptor_socket = socket(AF_INET,SOCK_STREAM,0);
	if(descriptor_socket == -1){
		printf("No se puede crear el socket");
		}
	//permite recibir una ip del servidor al que uno desea conectarse 
	servidor.sin_addr.s_addr=inet_addr("216.58.217.14 ");
	servidor.sin_family=AF_INET;
	servidor.sin_port=htons(80);
	
	//conexion al servidor remoto
	if(connect(descriptor_socket,(struct sockaddr*)&servidor,sizeof(servidor))>0){
	puts("error de conexion\n");
	return 1;
	}
	puts("conectado\n");
	return 0;
}
