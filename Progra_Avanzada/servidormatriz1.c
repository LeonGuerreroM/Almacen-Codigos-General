#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

typedef struct _matriz{
	int shmid;//identificador de la memoria compartida donde estara la matriz
	int filas, columnas,dato;
	int **coef;
} matriz;

matriz*crear_matriz(int filas, int columnas);
void imprimirMatriz(matriz*m,int jugador);
matriz* LlenarMatriz();

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
	matriz*aux=NULL;
	int i, j,a;
	int auxcolumna[10]={0,1,2,3,4,5,6,7,8,9};
	printf("\n");
	printf("\t\tBatalla Naval\n\t");
	for(a=0;a<10;a++){
		printf("%d ",auxcolumna[a]);
		}
		printf("\n\n\n");
	for(i=0; i<m->filas; i++){
			printf("%d",i);
			printf("\t");
		for(j=0; j<m->columnas; j++){
			printf("%d ", m->coef[i][j]);
		}
		printf("\n");
	}
}

matriz* LlenarMatriz(int filas,int columnas){
	int i,j,a;
	matriz*m;
	columnas=10;
	filas= 10;

	printf("\n\n\n");
	m=crear_matriz(filas,columnas);
		for(i =0;i<filas;i++){

			for(j=0;j<columnas;j++){
				m->coef[i][j]=0;
			}
		}
		return m;
}

int main(){
	sem_t mutex;
	matriz*m;
	int i,j;
	int k[10][10];
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			k[i][j]=1;
		}
	}
	int server_sockfd, client_sockfd; // descriptores de sockets
	int server_len, client_len; //tamaÃ±os de las estructuras
	struct sockaddr_in server_address; //declaracion de estructuras
	struct sockaddr_in client_address;
	int inicio = 0; //determina el inicio de sesion
	int ciclo = 1; //variable para ciclo de lectura escritura
	int puerto; //variable para el puerto
	sem_init(&mutex,0,1);
	system("clear");
	printf("La direccion del servidor es 127.0.0.1\n\n");
	printf("Por favor introduzca el puerto de escucha: \n\n");
	scanf("%d",&puerto);
		// se llena la estructura para el servidor con los datos necesarios
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = puerto;
	server_len = sizeof(server_address);

	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("ERROR de apertura de socket");
		exit(-1);
	}

	//avisamos al sistema operativo la creacion del socket
	if(bind(server_sockfd, (struct sockaddr *)&server_address, server_len)==-1){
	printf("error en bind()\n");
	exit(-1);
	}
	//decimos al server que quede escuchando
	if(listen(server_sockfd,5)==-1){
		printf("error en listen()\n");
		exit(-1);
	}
//habilita una cola asociada al conector descrito por sfd esta cola
				//se utiliza para alojar peticiones de conexion
	printf("SERVIDOR EN ESPERA...\n");
	while(ciclo){
		//acepta la conexion con el cliente actual
		sem_wait(&mutex);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		if(inicio ==0){
			printf("------SESION INICIADA------\n");
			printf("CLIENTE CONECTADO\n");
			printf("SERVIDOR CONECTADO...");
			send(client_sockfd,k,sizeof(int*100),0);//envia datos al conector
			printf("informacion enviada...\n");
			inicio = 1;
			}
			sleep(1);
			sem_post(&mutex);
			close(client_sockfd);
		}
	close(server_sockfd);
}
