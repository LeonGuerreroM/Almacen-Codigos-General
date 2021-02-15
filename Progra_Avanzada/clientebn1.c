#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/shm.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

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
//Funciones de configuracion
int casillaExiste(int x, int y);
int casillaVacia(int x, int y, matriz *m);
int dobleCasillaVacia(int x, int y, int ori, matriz *m);
int tripleCasillaVacia(int x, int y, int ori, matriz *m);

int main(){
int sockfd;
int len;
struct sockaddr_in address;
int result;
char ch[1024];
char c[1024];
int buf;
int inicio = 0;
char cs[1024];
int bufs;
int ciclo =1;
char ipserver[10];
int puerto;
int i=0,fil,col,ori,validacionCasilla=0;

matriz *m=NULL;
int numBarcos[1];//,turnoId[1];
int posBarco[2], posBarco3[3], cantidadesBarcos[3];
int pequenos, medianos, grandes;

system("clear");

printf("ingrese la ip del servidor\n");
scanf("%s",ipserver);

printf("ingrese el puerto de conexion\n");
scanf("%d",&puerto);

sockfd = socket(AF_INET, SOCK_STREAM,0);
//llenado de la estructura de datos
address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr(ipserver);
address.sin_port = puerto;
len = sizeof(address);

//conectar con el server
result = connect(sockfd, (struct sockaddr *)&address, len); //metodo para que un proceso cliente haga una conexion con un servidor
//1)Descriptor del conector que da acceso al canal 2)estructura que guarda la direccion del servidor 3)longitud de la direccion en bytes
if(result ==-1){recv(sockfd, ch, 1024,0);
perror("ERROR EN LA CONEXION\n");
close(sockfd);
}

//validar el inicio de sesion
if(inicio==0){
printf("--------------- SESION INICIADA --------------\n");
recv(sockfd, ch, 1024,0);
printf("%s\n",ch);

recv(sockfd, filas, 4,0);
recv(sockfd, numBarcos, 4,0);
columnas[0]=filas[0];

m=LlenarMatriz();

printf("dimensiones = %d\n",filas[0]);
printf("numBarcos = %d\n",numBarcos[0]);

pequenos=numBarcos[0]*(0.5);
medianos=numBarcos[0]*(0.3);
grandes=numBarcos[0]*(0.2);
int suma=pequenos+medianos+grandes;
while(suma<numBarcos[0]){
	pequenos++;
	suma=pequenos+medianos+grandes;
}

cantidadesBarcos[0]=pequenos; cantidadesBarcos[1]=medianos; cantidadesBarcos[2]=grandes;

send(sockfd,cantidadesBarcos,12,0);
//turnoId[0]=1;
//Posiciona los barcos
//send(sockfd,turnoId,4,0);
printf("%d Barcos de 1 casilla\n",pequenos);
while(i<pequenos){
	printf("Digite las coordenadas para colocar barco %d...",i+1);
	printf("\n");
	printf("fila\t");
	scanf("%d",&fil);
	printf("\n");
	printf("columna\t");
	scanf("%d",&col);
	printf("\n");
	validacionCasilla=casillaVacia(fil-1,col-1,m);
	if(validacionCasilla==1){
		m=ponerBarcoChico(fil-1,col-1,m); //enviar arreglo
		posBarco[0]=fil-1;
		posBarco[1]=col-1;
		send(sockfd, posBarco, 8,0);
		i++;
	}else{
		printf("Casilla no valida, intentalo de nuevo\n");
	}
}

i=0;
printf("%d Barcos de 2 casillas\n",medianos);
while(i<medianos){
	printf("Digite las coordenadas para colocar (proa) barco %d...",i+1);
	printf("\n");
	printf("fila\t");
	scanf("%d",&fil);
	printf("\n");
	printf("columna\t");
	scanf("%d",&col);
	printf("\n");
	printf("Orientacion. 1)Horizontal 2)Vertical\t");
	scanf("%d",&ori);
	printf("\n");
	validacionCasilla=dobleCasillaVacia(fil-1,col-1,ori,m);
	if(validacionCasilla==1){
		m=ponerBarcoMediano(fil-1,col-1,ori,m);
		posBarco3[0]=fil-1;
		posBarco3[1]=col-1;
		posBarco3[2]=ori;
		send(sockfd, posBarco3, 12,0);
		i++;
	}else{
		printf("Casilla no valida, intentalo de nuevo\n");
	}
}

i=0;
printf("%d Barcos de 3 casillas\n",grandes);
while(i<grandes){
	printf("Digite las coordenadas para colocar (proa) barco %d...",i+1);
	printf("\n");
	printf("fila\t");
	scanf("%d",&fil);
	printf("\n");
	printf("columna\t");
	scanf("%d",&col);
	printf("\n");
	printf("Orientacion. 1)Horizontal 2)Vertical\t");
	scanf("%d",&ori);
	printf("\n");
	validacionCasilla=tripleCasillaVacia(fil-1,col-1,ori,m);
	if(validacionCasilla==1){
		m=ponerBarcoGrande(fil-1,col-1,ori,m);
		posBarco3[0]=fil-1;
		posBarco3[1]=col-1;
		posBarco3[2]=ori;
		send(sockfd, posBarco3, 12,0);
		i++;
	}else{
		printf("Casilla no valida, intentalo de nuevo\n");
	}
}




}

close(sockfd);

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
				imprimirMatriz(m,1);
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
					imprimirMatriz(m,1);
				}else if(ori==2){
					m->coef[i-1][j]=1;
					imprimirMatriz(m,1);
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
					imprimirMatriz(m,1);
				}else if(ori==2){
					m->coef[i-1][j]=1;
					m->coef[i-2][j]=1;
					imprimirMatriz(m,1);
				}
				return m;
			}
		}
	}
}

//Funciones de configuracion
int casillaExiste(int x, int y){
	if(x<0 || y<0 || x>filas[0]-1 || y>columnas[0]-1){
		return 0;
	}else{
		return 1;
	}
}

int casillaVacia(int x, int y, matriz *m){
	int i, j,r;

	if((r=casillaExiste(x,y))==0){
		return 0;
	}

	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				if(m->coef[i][j]==0){
					return 1;
				}else{
					return 0;
				}
			}
		}
	}
}

int dobleCasillaVacia(int x, int y, int ori, matriz *m){
	int i, j,r;

	if((r=casillaExiste(x,y))==0){
		return 0;
	}

	if(x==0 && y==0){
		return 0;

	}

	if(x==0 && ori==2){
		return 0;
	}

	if(y==0 && ori==1){
		return 0;
	}

	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				if(ori==1){
					if(m->coef[i][j]==0 && m->coef[i][j-1]==0){
						return 1;
					}else{
						return 0;
					}
				}else if(ori==2){
					if(m->coef[i][j]==0 && m->coef[i-1][j]==0){
						return 1;
					}else{
						return 0;
					}
				}
			}
		}
	}
}

int tripleCasillaVacia(int x, int y, int ori, matriz *m){
	int i, j,r;

	if((r=casillaExiste(x,y))==0){
		return 0;
	}

	if((x==0 && y==0)||(x==0 && y==1)||(x==1 && y==0)||(x==1 && y==1)){
		return 0;
	}

	if((x==0 || x==1)&& ori==2){
		return 0;
	}

	if((y==0 || y==1) && ori==1){
		return 0;
	}

	for(i=0; i<m->filas; i++){
		for(j=0; j<m->columnas; j++){
			if(x==i && y==j){
				if(ori==1){
					if(m->coef[i][j]==0 && m->coef[i][j-1]==0 && m->coef[i][j-2]==0){
						return 1;
					}else{
						return 0;
					}
				}else if(ori==2){
					if(m->coef[i][j]==0 && m->coef[i-1][j]==0 && m->coef[i-2][j]==0){
						return 1;
					}else{
						return 0;
					}
				}
			}
		}
	}
}
