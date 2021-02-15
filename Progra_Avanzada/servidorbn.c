#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/ipc.h>
#include <semaphore.h>

typedef struct _matriz{
	int shmid;//identificador de la memoria compartida donde estara la matriz
	int filas, columnas,dato;
	int **coef;
} matriz;

int filas[1], columnas[1];

matriz*crear_matriz(int filas, int columnas);
void imprimirMatriz(matriz*m,int jugador);
matriz* LlenarMatriz();

matriz* ponerBarcoChico(int x, int y,matriz *m);
matriz* ponerBarcoMediano(int x, int y, int ori, matriz *m);
matriz* ponerBarcoGrande(int x, int y, int ori, matriz *m);
int ajusteTurno(int turnoActivo);

int main(){
sem_t mutex;
int server_sockfd, client_sockfd, client2_sockfd; //descriptores de sockets
int server_len, client_len, client2_len; //tamaÃ±os de las estructuras
struct sockaddr_in server_address; //declaracion de estructuras
struct sockaddr_in client_address;
struct sockaddr_in client2_address;
char c[1024]; //cadena del cliente
char ch[1024]; //cadena del servidor
int inicio = 0; //determina el inicio de sesion
char cs[1024]; //cadena del servidor
int bufs; //almacenamiento del tamanio cadena server
int puerto; //variable para el puerto
matriz *m=NULL,*m2=NULL;
int vivos1, vivos2; //numero de barcos restantes
int marcador1, marcador2; //marcador de cada uno
int repetirTiro;
int turnoActivo=1;

int i=0,conectados=0,config1=0,config2=0;
int confirmacionConfiguracion[]={0},numBarcos[0];
int posBarco[2], posBarco3[3], cantidadesBarcos[3];

system("clear");
printf("La direccion del servidor es 127.0.0.1\n\n");
printf("Por favor introduzca el puerto de escucha: \n\n");
scanf("%d",&puerto);

server_sockfd = socket(AF_INET, SOCK_STREAM, 0); //Crea un punto terminal para conectarse a un canal de comunicacion
//1)Familia de direcciones 2)Manera de comunicacion para el conector 3)Protocolo en 0 lo decide el sistema
//Devuelve un descriptor que es como un Id de Socket
//se le asigna una familia de direcciones pñero no una direccion en especifico

// se llena la estructura para el servidor con los datos necesarios
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
server_address.sin_port = puerto;
server_len = sizeof(server_address);

//avisamos al sistema operativo la creacion del socket
bind(server_sockfd, (struct sockaddr *)&server_address, server_len); //une una terminal (socket) a una direccion de red
//1)sfd es el decriptor del socket (id) que se va a enlazar con (2)addr se debe usar el sockaddr adecuado 3)Indica el tamaño de la direccion
//bind(server_sockfd, (struct) conm una direccion)

//decimos al server que quede escuchando
listen(server_sockfd,5); //indica que esta disponible para recibir peticiones
//listen habilita una cola asociada al conector (socket) identificado por 1)sfd, esta cola
//se utiliza para alojar peticiones de conexion procedentes de los clientes, la longitud de la cola se da en el argumento (2
printf("SERVIDOR EN ESPERA...\n");
//while(ciclo){
//acepta la conexion con el cliente actual
client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
client2_sockfd = accept(server_sockfd, (struct sockaddr *)&client2_address, &client2_len);
//este metodo sirve para leer peticiones de servicio. Extrae la primera peticion de la cola de peticiones de listen. Crea un nuevo socket
//con la mismas propiedades que el del id y reserva un nuevo descriptor de fichero nsfd (nuevo socket)
//mientras no halla peticiones en la cola, accept sigue activo
//1)id del socket ya unido a una direccion 2)Direccion del cliente 3)tamaño de la direccion
//Basicamente aqui se conecta
//cliente_sockfd guarda el socket ya conectado
if(inicio ==0){
printf("------SESION INICIADA------\n");
printf("CLIENTE CONECTADO\n");
strcpy(ch,"SERVIDOR CONECTADO...");
send(client_sockfd, ch, 1024,0); //Escribe en el conector
send(client2_sockfd, ch, 1024,0);
//1)Descriptor en el que se va a escribir 2)Puntero a la zona de memoria donde estan los datos que se desean enviar
//3)len numero de bytes en esa zona de memoria

printf("Escriba el tamaño de la matriz\n");
scanf("%d",&filas[0]);
send(client_sockfd,filas, 4,0);
send(client2_sockfd,filas, 4,0);
columnas[0]=filas[0];

m=LlenarMatriz();
m2=LlenarMatriz();

//Escoge el numero de barcos
printf("Batalla Naval\n");
printf("Determine el numero de barcos\n");
scanf("%d",&numBarcos[0]);
send(client_sockfd,numBarcos, 4,0);
send(client2_sockfd,numBarcos, 4,0);
inicio = 1;

printf("dimensiones = %d\n",filas[0]);
printf("numBarcos = %d\n",numBarcos[0]);

recv(client_sockfd,cantidadesBarcos,12,0);

printf("Barcos c %d\t",cantidadesBarcos[0]);
printf("Barcos m %d\t",cantidadesBarcos[1]);
printf("Barcos g %d\n",cantidadesBarcos[2]);
}

while(conectados<2){
	//sem_wait(&mutex);
	//recv(client_sockfd,turnoActivo,4,0);
	if((config1==0 && turnoActivo==1) || (config2==0 && turnoActivo==2)){
	while(i<cantidadesBarcos[0]){
		if(turnoActivo==1){
			recv(client_sockfd,posBarco,8,0);
		}else if(turnoActivo==2){
			recv(client2_sockfd,posBarco,8,0);
		}
		if(turnoActivo==1){
			ponerBarcoChico(posBarco[0],posBarco[1],m);
		}else if(turnoActivo==2){
			ponerBarcoChico(posBarco[0],posBarco[1],m2);
		}
		i++;
	}

	i=0;
	while(i<cantidadesBarcos[1]){
		if(turnoActivo==1){
			recv(client_sockfd,posBarco3,12,0);
		}else if(turnoActivo==2){
			recv(client2_sockfd,posBarco3,12,0);
		}

		if(turnoActivo==1){
			ponerBarcoMediano(posBarco3[0],posBarco3[1],posBarco3[2],m);
		}else if (turnoActivo==2){
			ponerBarcoMediano(posBarco3[0],posBarco3[1],posBarco3[2],m2);
		}
		i++;
	}
	i=0;
	while(i<cantidadesBarcos[2]){
		if(turnoActivo==1){
			recv(client_sockfd,posBarco3,12,0);
		}else if(turnoActivo==2){
			recv(client2_sockfd,posBarco3,12,0);
		}

		if(turnoActivo==1){
			ponerBarcoGrande(posBarco3[0],posBarco3[1],posBarco3[2],m);
		}else if (turnoActivo==2){
			ponerBarcoGrande(posBarco3[0],posBarco3[1],posBarco3[2],m2);
		}
		i++;
	}

	if(turnoActivo==1){
		config1++;
	}else if(turnoActivo==2){
		config2++;
	}

	printf("matriz jugador 1\n");
	imprimirMatriz(m,1);
	printf("matriz jugador 2\n");
	imprimirMatriz(m2,1);

	turnoActivo=ajusteTurno(turnoActivo);
	conectados++;
	}
	//+sem_post(&mutex);
}



/*recv(client_sockfd, cs, 1024,0); //lee de un conector
//1)id del socket en el que se lee 2)Puntero a la memoria donde se escribiran los datos leidos
//3)numero maximo de bytes que se escriben en la memoria guardada por len
			recv(client2_sockfd,posBa
printf("El cliente dijo: %s\n",cs);

printf("ingrese una cadena: \n");
scanf("%*c%[^\n]",c);
send(client_sockfd, c, 1024,0);*/

close(client_sockfd); //cierra las conexiones
//}

close(server_sockfd);

}

matriz*crear_matriz(int filas, int columnas){
	int shmid, i;
	matriz*m;

	//peticion de memoria compartida
	shmid =shmget(IPC_PRIVATE,sizeof(matriz)+filas*sizeof(int*)+filas*columnas*sizeof(int),IPC_CREAT|0600); //obteniendo el id para realizar futuras llamadas al sistema para controlar la memoria compartida
	if(shmid==-1){
		perror("MEMORIA... memoria_matriz(shmget)");
		exit(-1);
	}
	//atando memoria..
	if((m = (matriz*)shmat(shmid,0,0))==(matriz*)-1){
		perror("memoria_matriz (shmdt)");
		exit(-1);
	}
	//inicializacion de la matriz
	m->shmid = shmid;
	m->filas= filas;
	m->columnas=columnas;
	//formateamos la memoria para poder direccionar los coeficientes de la matriz
	m->coef=((int**)&m->coef+sizeof(int**));
	for(i=0;i<filas;i++)
		m->coef[i]=(int*)&m->coef[filas]+i*columnas*sizeof(int);
	return m;
}


void imprimirMatriz(matriz*m,int jugador){
	int i, j;
	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			printf("%d", m->coef[i][j]);
		}
		printf("\n");
	}
}

matriz* LlenarMatriz(){
	int i,j;
	matriz*m;

	m=crear_matriz(filas[0],columnas[0]);
		for(i =0;i<filas[0];i++){
			for(j=0;j<columnas[0];j++){
				m->coef[i][j]=0;
			}
		}
	imprimirMatriz(m,1);
		return m;
}

matriz* ponerBarcoChico(int x, int y,matriz *m){
	int i, j;
	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				m->coef[i][j]=1;
				//imprimirMatriz(m,1);
				return m;
			}
		}
	}
}

matriz* ponerBarcoMediano(int x, int y, int ori, matriz *m){
	int i, j;
	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				m->coef[i][j]=1;
				if(ori==1){
					m->coef[i][j-1]=1;
					//imprimirMatriz(m,1);
				}else if(ori==2){
					m->coef[i-1][j]=1;
					//imprimirMatriz(m,1);
				}
				return m;
			}
		}
	}
}

matriz* ponerBarcoGrande(int x, int y, int ori, matriz *m){
	int i, j;
	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				m->coef[i][j]=1;
				if(ori==1){
					m->coef[i][j-1]=1;
					m->coef[i][j-2]=1;
					//imprimirMatriz(m,1);
				}else if(ori==2){
					m->coef[i-1][j]=1;
					m->coef[i-2][j]=1;
					//imprimirMatriz(m,1);
				}
				return m;
			}
		}
	}
}

/*void tirar(){
	int ataque[2]; //este metodo al terminar debe regresar la matriz para ver el resultado pero con el semafor bloqueado

	printf("Escriba las coordenadas de su ataque\nFila\t");
	scanf("%d \n",&ataque[0]);
	printf("Columna\t");
	scanf("%d \n",&ataque[1]);
	send(sockfd,ataque,8,0);

}*/

int ajusteTurno(int turnoActivo){
	turnoActivo++;
	if(turnoActivo%2==0){
		return 2;
	}else{
		return 1;
	}
}
