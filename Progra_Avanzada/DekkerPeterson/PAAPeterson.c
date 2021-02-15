#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct Nodo{
  //@autor leonm;
  int id;
  char titulo[50];
  char autor[50];
  int precio;
  struct Nodo *sig;
	struct Nodo *ant;
}Lista;

pthread_mutex_t gate;

Lista *libros=NULL; //recurso compartido
int numHilosA,numHilosB; //cantidad de altas y bajas
int condiciones[100]; //variables de condicion
int cadenero;
int sumador=0;
int seguirR=0;
int seguirB=0;

void* Registro(void *parametros);
void* Baja(void *parametros);
Lista* Crear(char titul[], char aut[], int precio,int id);
Lista* AltaFinal(Lista *top, char titul[], char aut[], int precio, int id);
Lista* bajaFinal(Lista *top);
void mostrarLista(Lista *top);
int Conteo(Lista *top);

int main(){
  int i;
  system("clear");
  srand(getpid());
  printf("Cuantos hilos de alta se ejecutaran?\n");
  scanf("%d",&numHilosA);
  printf("Cuantos hilos de baja se ejecutaran?\n");
  scanf("%d",&numHilosB);
  pthread_t hilosA[numHilosA];
  pthread_t hilosB[numHilosB];

  pthread_mutex_init(&gate,NULL);
  pthread_mutex_lock(&gate);

  for(i=0;i<numHilosA;i++){ //se crean los hilos de escritura
    pthread_create(&hilosA[i],NULL,Registro,&i); //se le envia el i, pues es tambien la casilla de la variable de condicion (del arreglo de condiciones) que le corresponde a ese hilo
    //pthread_create(&hilosB[i],NULL,Baja,&i);
  }

  for(i=0;i<numHilosB;i++){ //se crean los hilos de baja
    pthread_create(&hilosB[i],NULL,Baja,&i);
  }

  for(i=0;i<numHilosA;i++){
    pthread_join(hilosA[i],NULL);
  }

  for(i=0;i<numHilosB;i++){
    pthread_join(hilosB[i],NULL);
  }

  mostrarLista(libros);
  return 0;
}


void* Registro(void *parametros){
  char autor[1];
  char titulo[1];
  int i=*(int*)parametros;
  int j;
  while(sumador<6){
    sumador++;
    int id=((rand()%101)+sumador);
    int precio=((rand()%1000)+sumador+id);
    autor[0]=id+'0';
    titulo[0]=(id+rand()%10)+'0';
    cadenero=rand()%11;
    if(cadenero<5){
      condiciones[i]=0; //lo mismo que en el algoritmo anterior, pero mandandole el parametro i de la casilla que le corresponde
    }else{
      condiciones[i]=1;
      for(j=0;j<numHilosA;j++){ //hace que los demas sean 0, solo mandando uno mas del i
        if(j!=i){
          condiciones[j]=0;
          seguirR=1;
        }
        //condiciones[j]=0;
        seguirR=1;
      }
    }

    if(condiciones[i]==1 && seguirR==1){
      printf("Alta\n");
      libros=AltaFinal(libros,titulo,autor,precio,id);
      pthread_mutex_unlock(&gate);
    }
  }
}

void* Baja(void *parametros){
  pthread_mutex_lock(&gate);
  int i=*(int*)parametros;
  int j;

  while(sumador<4){
    cadenero=rand()%11;
    if(cadenero<5){
      condiciones[i]=0;
    }else{
      condiciones[i]=1;
      for(j=0;j<numHilosB;j++){
        if(j!=i){
          condiciones[j]=0;
          seguirR=1;
        }
        //condiciones[j]=0;
        seguirR=1;
        //condiciones[j]=0;
        //seguirB=1;
      }
    }
    if(condiciones[i]==1 && seguirB==1){
      printf("Baja\n");
      libros=bajaFinal(libros);
    }
  }
}


Lista* Crear(char titul[], char aut[], int precio,int id){
	Lista *nuevo;
	nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->id=id;
	strcpy(nuevo->autor,aut);
	strcpy(nuevo->titulo,titul);
	nuevo->precio=precio;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	return nuevo;
}

Lista* AltaFinal(Lista *top, char titul[], char aut[], int precio, int id){
	Lista *nuevo, *aux;
	aux=top;
	nuevo=Crear(titul,aut,precio,id);
	if(aux==NULL){
		return nuevo;
	}else{
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
		nuevo->ant=aux;
		return top;
	}
}

Lista* bajaFinal(Lista *top){
	int longitud=Conteo(top);
	int i;
	Lista *aux, *aux2;
	aux=top;
  //@autor leonm;
	if(top==NULL){
		printf("Lista vacia\n");
	}else{
		for(i=1;i<longitud-1;i++){
			aux=aux->sig;
		}
		aux2=aux->sig;
		aux->sig=NULL;
		free(aux2);
	}
	return top;
}

void mostrarLista(Lista *top){
    Lista *aux;
    aux=top;
    int x;
    char k;
    char j[1];
    if(aux==NULL){
        printf("Lista vacia\n");
    }else{
      printf("Id: %d\n",aux->id);
      printf("Titulo: %s\n",aux->titulo);
      printf("Autor: %s\n",aux->autor);
      printf("Precio: $%d\n",aux->precio);
       do{
       //@autor leonm;
        printf("Use las a/s para moverse en la lista. Para salir presione e \n");
        scanf("%1s",j);
        k=j[0];
        if(k=='s'){
            if(aux->sig!=NULL){
            aux=aux->sig;
            }
            printf("Id: %d\n",aux->id);
            printf("Titulo: %s\n",aux->titulo);
            printf("Autor: %s\n",aux->autor);
            printf("Precio: $%d\n",aux->precio);
        }else if(k=='a'){
            if(aux->ant!=NULL){
            aux=aux->ant;
            }
            printf("Id: %d\n",aux->id);
            printf("Titulo: %s\n",aux->titulo);
            printf("Autor: %s\n",aux->autor);
            printf("Precio: $%d\n",aux->precio);
        }
       }while(k!='e');
    }
}

int Conteo(Lista *top){
    int i=0;
    if(top==NULL){
        return 0;
    }else{
        while(top!=NULL){
            i++;
            top = top->sig;
        }
        return i;
    }
}
