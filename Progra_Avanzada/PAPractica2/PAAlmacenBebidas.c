#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>


typedef struct NodoL{
	int idProducto;
	char nombreProducto[100];
	int precioProducto;
	struct NodoL *sig;
	struct NodoL *ant;
}ListaBebidas;

typedef struct NodoP{
		int idProducto;
		char nombreProducto[100];
		int precioProducto;
    struct NodoP *siguiente; //siguiente es el elemento que esta abajo
}PilaBebidas;

ListaBebidas *bebidas=NULL;
PilaBebidas *respaldo=NULL;

//funciones de estructuras
PilaBebidas* CrearP(int id, char np[100], int pp);
PilaBebidas* AltaP(int id, char np[100], int pp, PilaBebidas *top);
ListaBebidas* CrearL(int id, char np[100], int pp);
ListaBebidas* AltaFinalL(ListaBebidas *top, int id, char np[100], int pp);
//funciones de complemento
ListaBebidas* llenarLista(ListaBebidas *bebidas);
void mostrarLista(ListaBebidas *top);
void Consulta(PilaBebidas *top);
//funciones de hilo
void* Recuperar(void *parametros);
void* Imprime(void *parametros);

int main(){
	pthread_t idHilo2, idHilo;
	char *devuelto=NULL;

	bebidas=llenarLista(bebidas);
	//mostrarLista(bebidas);

	pthread_create(&idHilo,NULL,Recuperar,NULL);
	pthread_join(idHilo,(void**)&devuelto);
	printf("%s \n",devuelto);
	pthread_create(&idHilo2,NULL,Imprime,NULL);
	pthread_join(idHilo2,NULL);

	//Consulta(respaldo);
	return 0;
}

PilaBebidas* CrearP(int id, char np[100], int pp){
    PilaBebidas *nuevoNodo;
    nuevoNodo =(PilaBebidas*)malloc(sizeof(PilaBebidas)); //No es necesario el cast ya, pero es una buena precaucion
    nuevoNodo->idProducto=id;
		strcpy(nuevoNodo->nombreProducto,np);
		nuevoNodo->precioProducto=pp;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

PilaBebidas* AltaP(int id, char np[100], int pp, PilaBebidas *top){
    PilaBebidas *nuevo;
    nuevo=CrearP(id,np,pp);
    if(top!=NULL){
        nuevo->siguiente=top;
    }
    return nuevo;
}

ListaBebidas* CrearL(int id, char np[100], int pp){
	ListaBebidas *nuevo;
	nuevo=(ListaBebidas*)malloc(sizeof(ListaBebidas));
	nuevo->idProducto=id;
	strcpy(nuevo->nombreProducto,np);
	nuevo->precioProducto=pp;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	return nuevo;
}

ListaBebidas* AltaFinalL(ListaBebidas *top, int id, char np[100], int pp){
	ListaBebidas *nuevo, *aux;
	aux=top;
	nuevo=CrearL(id, np, pp);
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

ListaBebidas* llenarLista(ListaBebidas *bebidas){
	bebidas=AltaFinalL(bebidas,01,"Agua",15);
	bebidas=AltaFinalL(bebidas,02,"Leche",27);
	bebidas=AltaFinalL(bebidas,03,"Refresco",18);
	bebidas=AltaFinalL(bebidas,04,"Jugo",18);
	bebidas=AltaFinalL(bebidas,05,"Cerveza",45);
	return bebidas;
}

void mostrarLista(ListaBebidas *top){
    ListaBebidas *aux;
    aux=top;
    int x,y;
		char nom[100];
    char k;
    char j[1];
    if(aux==NULL){
        printf("Lista vacia\n");
    }else{
			x=aux->idProducto;
			strcpy(nom,aux->nombreProducto);
			y=aux->precioProducto;
			printf("idProducto: %d \t Nombre: %s \t Precio %d\n",x,nom,y);
       do{
        printf("Use las a/s para moverse en la lista. Para salir presione e \n");
        scanf("%1s",j);
        k=j[0];
        if(k=='s'){
            if(aux->sig!=NULL){
            aux=aux->sig;
            }
            x=aux->idProducto;
						strcpy(nom,aux->nombreProducto);
						y=aux->precioProducto;
            printf("idProducto: %d \t Nombre: %s \t Precio %d\n",x,nom,y);
        }else if(k=='a'){
            if(aux->ant!=NULL){
            aux=aux->ant;
            }
						x=aux->idProducto;
						strcpy(nom,aux->nombreProducto);
						y=aux->precioProducto;
            printf("idProducto: %d \t Nombre: %s \t Precio %d\n",x,nom,y);
        }
       }while(k!='e');
    }
}


void* Recuperar(void *parametros){ //almacena la "base" en la pila
  ListaBebidas *aux;
	int contadorAuxiliar=1;
	aux=bebidas;

	if(aux==NULL){
			printf("Lista vacia\n");
	}

	while(aux!=NULL){
		respaldo=AltaP(aux->idProducto,aux->nombreProducto,aux->precioProducto,respaldo);
		aux=aux->sig;
	}

  pthread_exit((void*)"Guardado");
}

void* Imprime(void *parametros){ //almacena la "base" en la pila
	int x,y,i=1;
	char nom[100];
	PilaBebidas *top;
	top=respaldo;
	if(top==NULL){
			printf("La pila esta vacia\n");
	}else{
			while(top!=NULL){
					x=top->idProducto;
					strcpy(nom,top->nombreProducto);
					y=top->precioProducto;
					printf("Pila %d: idProducto: %d \t Nombre: %s \t Precio %d\n",i,x,nom,y);
					i++;
					top=top->siguiente;
			}
	}
	printf("esta fue la ejecucion del segundo hilo\n");
  pthread_exit(0);
}
