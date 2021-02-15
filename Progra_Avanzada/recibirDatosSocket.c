#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
  int socket_desc;
  struct sockaddr_in servidor;
  char *mensaje, server_reply[2000];
  //crear socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if(socket_desc == -1){
    printf("No se puede crear el socket");
  }
  servidor.sin_addr.s_addr=inet_addr("74.125.235.20");
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(80);
  //Conexion al servidor remoto
  if(connect(socket_desc, (struct sockaddr*)&servidor, sizeof(servidor))<0){
    puts("Error de conexion");
    return 1;
  }


}
