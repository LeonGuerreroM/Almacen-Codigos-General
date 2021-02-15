#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo1{
	int n;
	struct nodo1 *izq;
	struct nodo1 *der;
}nodo;
nodo *nuevoNodo();
void error();
int comparar (int x, int y);
void procesar(nodo *p);
int insertar(int d, nodo **raiz);
void inorden (nodo *raiz);
int buscar(int d, nodo *raiz);
void preorden (nodo *raiz);
void postorden (nodo *raiz);
int borrar(int d, nodo **raiz);
int main(){
	//nodo *inicio=NULL;
	//nodo *aux;
	nodo*raiz = NULL;
	//int c;
	int d;
	//aux=nuevoNodo();
	/*aux->n=3;
	aux->izq=NULL;
	aux->der=NULL; //los mayores van a la derecha
	inicio=aux;
	printf("%d \n",aux->n);
	printf("%d \n",aux->izq);
	printf("%d \n",aux->der);
	
	if((c=comparar(5, inicio->n))==0){
		printf("El nodo ya existe");
	}else if((c=comparar(5, inicio->n))==-1){ //se ira a la derecha porque es mayor
		aux=nuevoNodo();
		aux->n;
		inicio->der=aux;
		aux->der=NULL;
		aux->izq=NULL;
	}else if((c=comparar(5, inicio->n))==1){ //se ira a la izquierda porque es menor
		aux=nuevoNodo();
		aux->n;
		inicio->izq=aux;
		aux->der=NULL;
		aux->izq=NULL;
	}
	
	printf("--- \n");
	printf("%d \n",inicio);
	printf("%d \n",inicio->der);
	printf("%d \n",inicio->izq);
  printf("%d \n",inicio->der->izq);
	printf("%d \n",inicio->der->der);
	printf("--- \n");*/
	
	d=insertar(97, &raiz);
	d=insertar(64, &raiz);
	d=insertar(180, &raiz);
	d=insertar(46, &raiz);
	d=insertar(74, &raiz);
	d=insertar(1, &raiz);
	d=insertar(50, &raiz);
	d=insertar(70, &raiz);
	d=insertar(86, &raiz);
	d=insertar(100, &raiz);
	d=insertar(240, &raiz);
	d=insertar(99, &raiz);
	d=insertar(110, &raiz);
	//printf("%d \n",raiz->n);
	
	//inorden(raiz);
	//int i;
	/*for(i=10;i>0;i--){
		d=insertar(i, &raiz);
	}*/
	inorden(raiz); //no depende de como metas los valores
	printf("----- \n");
	//i=buscar(70, &raiz);
	//printf("%d\n",i);
	//preorden(raiz); //si depende de como metas las valores
	//printf("----- \n");
	//postorden(raiz); //si depende de como metan los valores
	
	//printf("----- \n");
	borrar(86, &raiz);
	inorden(raiz); //no depende de como metas los valores
	printf("----- \n");
	preorden(raiz); //si depende de como metas las valores
	printf("----- \n");
	
	return 0;
}

nodo *nuevoNodo(){
	nodo*q	= (nodo*)malloc(sizeof(nodo));
	if(!q)error();
	return q;
}

void error(){
	printf("No hay memoria :( )\n");	
}

int comparar (int x, int y){
	if(x==y){
		return 0;
	}else if(x>y){
		return 1;
	}else{
		return -1;
	}
	
}

void procesar(nodo *p){
	printf("El contenido del nodo es: %d \n",p->n);
} 

int insertar(int d, nodo **raiz){
	nodo *nuevo = NULL;
	nodo *ultimo = NULL;
	nodo *actual=*raiz;
	
	int nComp=0;
	
	while(actual!=NULL){
		
		if((nComp=comparar(d, actual->n))==0){
			printf("El nodo ya existe \n");
			break;
		}else{
			ultimo=actual;
			if(nComp<0){
				actual = actual->izq;
			}else{
				actual = actual->der;
			}
		}
	}
	if(actual==NULL){
		nuevo=nuevoNodo();
		nuevo->n=d;
		nuevo->izq=NULL;
		nuevo->der=NULL;
		
		if(ultimo==NULL){
			*raiz=nuevo;
		}else if(nComp<0){
			ultimo->izq=nuevo;
		}else{
			ultimo->der=nuevo;
		}
		return 0;
	}else{
		return 2;
	}
}

void inorden (nodo *raiz){
	nodo *actual = raiz;
	if(actual!=NULL){
		inorden(actual->izq);
		procesar(actual);
		inorden(actual->der);
	}
}

int buscar(int d, nodo *raiz){
	nodo *actual = raiz;
	int nComp;
	
	while(actual!=NULL){
		if((nComp=comparar(d, actual->n))==0){
			return(actual->n);
		}else if(nComp<0){
			actual=actual->izq;
			}else{
				actual = actual->der;
			}
		}
	}
	
void preorden(nodo *raiz){
	nodo *actual = raiz;
	if(actual!=NULL){
		procesar(actual);
		preorden(actual->izq);
		preorden(actual->der);
	}
}

void postorden(nodo *raiz){
	nodo *actual = raiz;
	if(actual!=NULL){
		postorden(actual->izq);
		postorden(actual->der);
		procesar(actual);
	}
}

int borrar(int d, nodo **raiz){
	nodo *ultimo = NULL;
	nodo *actual = *raiz;
	nodo *marcado = NULL;
	nodo *sucesor = NULL;
	int AntComp = 0, nComp = 0;
	int aux;
	
	//busqueda para buscar al nodo con los datos que se quieren borrar
	while(actual!= NULL)
	{
		AntComp = nComp;		//resultado de la comparación anterior
		if((nComp=comparar(d, actual->n))==0)
			break; //ya se encontró el nodo
		else{
			ultimo=actual;
			if(nComp < 0) 
				actual = actual->izq;
			else
				actual = actual->der;
		}
	} //fin del bloque while (actual != NULL)
	if(actual != NULL)	//se encontró el nodo y es el que se va a borrar
	{
		marcado = actual;
		if((actual->izq)==NULL && ((actual->der)==NULL))
		//se trata de un nodo hoja, no tiene quien dependa de el 
			sucesor = NULL;
		else if (actual->izq == NULL) //nodo terminal del lado izquierdo
			sucesor = actual->der;
		else if (actual->der == NULL)
			sucesor = actual->izq;
		else{	//nodo que tienen hijo derecho e izquierdo
			//puntero al subarbol derecho del nodo a borrar;
			sucesor = actual = actual->der;
			/*Descender al nodo mas a la izquierda en el subarbol
			derecho de est nodo (el de valor mas pequeño) y hacer
			que el subarbol izquierdo del nodo a borrar o sea ahora 
			el subarbol izquierdo de este nodo
			*/	
			while(actual->izq != NULL)
				actual = actual->izq;
			actual->izq = marcado->izq;
		}
		//eliminar el nodo y rehacer los enlaces
		if(ultimo != NULL){
			if(AntComp < 0)
				ultimo->izq = sucesor;
			else 
				ultimo->der = sucesor;
		}
	else
		*raiz = sucesor;
		aux = marcado->n;
		free(marcado);
		return aux;		
	}
	else{
		printf("El nodo que buscas no se encuentra en la estructura");
		return NULL;
			
	}	
	}

