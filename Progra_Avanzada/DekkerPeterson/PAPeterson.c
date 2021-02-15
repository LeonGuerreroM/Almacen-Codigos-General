#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define N_HILOS 2

typedef struct Nodo{
  //@autor leonm;
  int id;
  char titulo[50];
  char autor[50];
  int precio;
  struct Nodo *sig;
	struct Nodo *ant;
}Lista;

Lista *libros=NULL; //recurso compartido

int condiciones[N_HILOS]; //condiciones de entrada (variables de estado)
int cadenero; //condicional
int sumador=0;

void* Registro(void *parametros);
void* Baja(void *parametros);
Lista* Crear(char titul[], char aut[], int precio,int id);
Lista* AltaFinal(Lista *top, char titul[], char aut[], int precio, int id);
Lista* bajaFinal(Lista *top);
void mostrarLista(Lista *top);
int Conteo(Lista *top);

int main(){
  system("clear");
  pthread_t idHilo, idHilo2;
  srand(getpid());

  pthread_create(&idHilo,NULL,Registro,NULL);
  pthread_create(&idHilo2,NULL,Baja,NULL);

  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);


  mostrarLista(libros);
  return 0;
}


void* Registro(void *parametros){
  char autor[1];
  char titulo[1];
  while(sumador<100){
    sumador++;
    int id=((rand()%101)+sumador);
    int precio=((rand()%1000)+sumador+id);
    autor[0]=id+'0';
    titulo[0]=(id+rand()%10)+'0';
    cadenero=rand()%11; //cadenero es una condicion random para saber si se ejecuta o no
    if(cadenero<5){
      condiciones[0]=0; //la casilla de condicion que corresponde a este hilo se pone en 0, no se ejcuta
    }else{
      condiciones[0]=1; //1, si se ejecuta
      condiciones[1]=0; //el otro no se ejecuta
    } //usa condicionales para cuando no se arma

    if(condiciones[0]==1 && condiciones[1]==0){ //comprobacion de las condiciones para la ejecucion
      //pthread_mutex_lock(&gate);
      printf("Alta\n");
      libros=AltaFinal(libros,titulo,autor,precio,id);
      //pthread_mutex_unlock(&gate);
    }
  }
}

void* Baja(void *parametros){
  while(sumador<50){
    cadenero=rand()%11;
    if(cadenero<5){
      condiciones[0]=0;
    }else{
      condiciones[0]=1;
      condiciones[1]=0;
    }
    //pthread_mutex_lock(&gate);
    if(condiciones[0]==1 && condiciones[1]==0){
      printf("Baja\n");
      libros=bajaFinal(libros);
      //pthread_mutex_unlock(&gate);
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
