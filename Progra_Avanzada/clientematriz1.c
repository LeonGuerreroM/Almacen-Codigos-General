#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <unistd.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
typedef struct _matriz{
	int shmid;//identificador de la memoria compartida donde estara la matriz
	int filas, columnas,dato;
	int **coef;
} matriz;
sem_t mutex;
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

int main(){
	int sockfd;
	int len;
	struct sockaddr_in address;//
	int result;

	//char ch[1024];
	//char c[1024];
	matriz*m;
	int buf,i,j;
	int k[10][10];
	int inicio = 0;
	int bufs;
	int ciclo =1;
	char ipserver[10];
	int puerto;
	sem_init(&mutex,0,1);
	system("clear");

	printf("ingrese la ip del servidor\n");
	scanf("%s",ipserver);

	printf("ingrese el puerto de conexion\n");
	scanf("%d",&puerto);

	while(ciclo){
		sockfd = socket(AF_INET, SOCK_STREAM,0);
		//llenado de la estructura de datos
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr(ipserver);
		address.sin_port = puerto;
		len = sizeof(address);

		//conectar con el server
		sem_wait(&mutex);
		result = connect(sockfd, (struct sockaddr *)&address, len);// establece conexion con el servidor
		if(result ==-1){
			perror("ERROR EN LA CONEXION cliente\n");
			close(sockfd);//cierre de canal
			}

		//validar el inicio de sesion
		if(inicio==0){
			printf("--------------- SESION INICIADA --------------\n");
			recv(sockfd,m->coef, sizeof(int*100),0);//es para leer de un socket
			printf("desde cliente: \n");
			imprimirMatriz(m,1);
				printf("\n");
			sleep(1);
			//imprimirMatriz(m,1);
			sem_post(&mutex);

			inicio = 1;
		}
		//sleep(1);
	}
	close(sockfd);

	}
