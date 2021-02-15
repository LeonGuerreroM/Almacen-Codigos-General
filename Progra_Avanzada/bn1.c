#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>
typedef struct _matriz{
	int shmid;//identificador de la memoria compartida donde estara la matriz
	int filas, columnas,dato;
	int **coef;
} matriz;

int filas=10,columnas=10;

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

//Funciones de juego
void tirar();

int main(){
	int i=0,suma,validacionCasilla;
	int pequenos, medianos, grandes;
	int fil,col,ori;
	int numBarcos;
	matriz *m=NULL;

	//variables de servidor
	int confirmacionConfiguracion=1;

	if(confirmacionConfiguracion==1){
		//Deterina el tamaño de la matriz
		printf("Escriba el tamaño de la matriz\n");
		scanf("%d",&filas);
		filas=columnas;

		m=LlenarMatriz(); //esto va creado en el servidor

		//Escoge el numero de barcos
		printf("Batalla Naval\n");
		printf("Determine el numero de barcos\n");
		scanf("%d",&numBarcos);
	}

	//Determina la cantidad de barcos de cada tipo
	pequenos=numBarcos*(0.5);
	medianos=numBarcos*(0.3);
	grandes=numBarcos*(0.2);
	suma=pequenos+medianos+grandes;
	while(suma<numBarcos){
		pequenos++;
		suma=pequenos+medianos+grandes;
	}
 	//printf("%d %d %d\n",pequenos,medianos,grandes);

	//Posiciona los barcos
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
			m=ponerBarcoChico(fil-1,col-1,m);
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
			i++;
		}else{
			printf("Casilla no valida, intentalo de nuevo\n");
		}
	}

	jugar();


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

	m=crear_matriz(filas,columnas);
		for(i =0;i<filas;i++){
			for(j=0;j<columnas;j++){
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
	if(x<0 || y<0 || x>filas-1 || y>columnas-1){
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

void tirar(){
	int ataque[2]; //este metodo al terminar debe regresar la matriz para ver el resultado pero con el semafor bloqueado

	printf("Escriba las coordenadas de su ataque\nFilas\t");
	scanf("%d \n",&ataque[0]);
	printf("Columnas\t");
	scanf("%d \n",&ataque[1]);

	//enviar las coordenadas al servidor
	//el servidor compara el ataque y si fue exitoso marca la casilla enemiga y la tuya en la seccion del enemigo
	//se cambia el estado de repeticion de turno si atino, se valida en el main
	//se regresa el marcador y se muestra (dos variables del servidor de conteo de barcos que se calculan en el servidor a partir del numero de barcos)
	//se regresa la matriz para seguir jugando
	//el servidor descuenta por cada ataque exitoso 1 uno al numero de Barcos
	//cuando la repeticion de turno es 0, igual el servidor pasa el dato al cliente y el cliente avisa que termino el turno, cuando la terminacion de turno esta activa es lo u¡que condiciona el bloqueo de los semnaforos
	//antes de pasar el dato el servidor comprueba el numero de barcos, si es 0 el del rival, se acaba el juego
}

void jugar(){
	int ataqueExitoso=1; //Por el momento seran variables locales
	int turnoTerminado=0;
	int marcadorJ1=0, marcadorJ2=0;


	printf("Jugador 1: %d\tJugador 2: %d",marcadorJ1,marcadorJ2);
	if(ataqueExitoso==1){
		tirar();
	}else{
		//envia el turno terminado al servidor
		turnoTerminado=1;

	}



}
