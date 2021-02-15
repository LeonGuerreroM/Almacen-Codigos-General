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

//Problema: Guardar libros en una lista doblemente enlazada
//Dekker se encarga de que dos procesos acceda a un recurso sincronizandolos de manera correcta

Lista *libros=NULL; //recurso compartido

pthread_mutex_t gate;
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
  pthread_mutex_init(&gate,NULL);

  pthread_create(&idHilo,NULL,Registro,NULL);
  pthread_create(&idHilo2,NULL,Baja,NULL);

  pthread_join(idHilo,NULL);
  pthread_join(idHilo2,NULL);

  pthread_mutex_destroy(&gate);

  mostrarLista(libros);
  return 0;
}


void* Registro(void *parametros){
  char autor[1];
  char titulo[1];
  while(sumador<100){ //agrega libros a la lista hasta que contador llegue a 100
    sumador++;
    int id=((rand()%101)+sumador); //genera los datos del libro
    int precio=((rand()%1000)+sumador+id);
    autor[0]=id+'0';
    titulo[0]=(id+rand()%10)+'0';
    pthread_mutex_lock(&gate); //bloquea la region critica antes del alta
    printf("Alta\n");
    libros=AltaFinal(libros,titulo,autor,precio,id);
    pthread_mutex_unlock(&gate); //desbloquea despues del area
  }
}

void* Baja(void *parametros){
  while(sumador<50){ //borra mientras haya 50 (para que no borre todo)
    pthread_mutex_lock(&gate); //bloquea la region critica antes de borrar
    printf("Baja\n");
    libros=bajaFinal(libros);
    pthread_mutex_unlock(&gate);
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
