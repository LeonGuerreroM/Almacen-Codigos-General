#include<stdio.h>
#include<stdlib.h>

typedef struct nodo1 {
	int n;
	struct nodo1 *izq;
	struct nodo1 *der;
}nodo;

int comparar (int x, int y){
	if (x < y)
		return -1; //-1 si el nuevo es menor
	else if (x == y)
		return 0;	//0 si son iguales
	else
		return 1;	//1 si son mayores
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
				ultimo->izq = sucesor;
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
int buscar(int datos, nodo *raiz){
	//La función buscar permite accede a un nodo determinado
	nodo *actual = raiz;
	int nComp;
	while(actual != NULL){
		if ((nComp = comparar(datos, actual->n))==0){
			return (actual->n);
		}
		else if(nComp < 0) {
			actual = actual->izq;			
		}
		else
		{
			actual = actual->der;
		}
		
	}
	
	
}
void error (void){
	printf("No hay suficiente memoria");
	//exit(1);
}
nodo *nuevoNodo(){
	nodo *q = (nodo *)malloc(sizeof(nodo));
	if (!q) error();
	return q;
}
void procesar (nodo *p){
	nodo *aux = p;
	printf("el valor del nodo es: %d \n", aux->n );
}

//inorden : función recursiva que recorre un arbol binnario utilizando la forma inorden

void inorden (nodo *raiz){
	/*La fUnción recursiva inorden visita los nodos del arbol
	utilizando la forma inorde; esto es, pimero visia 
	el subarbol izquierdo, después visita la raiz y por +ultimo el subarbol derecho*/
	nodo *actual = raiz;
	if(actual!=NULL)
	{	
		inorden(actual->izq); //visita al arbol izquierdo
		//procesar los datos del nodo visitado
		procesar(actual);
		inorden(actual->der);
	}
}
void preorden (nodo *raiz){
	nodo *actual = raiz;
	if(actual != NULL)
	{
		procesar(actual);
		preorden(actual->izq);
		preorden(actual->der);
	}
}
void postorden(nodo *raiz){
	nodo *actual = raiz;
	if(actual != NULL)
	{
		postorden(actual->izq);
		postorden(actual->der);
		procesar(actual);		
	}	
}
int insertar (int d, nodo **raiz){
	//la función insertar permite añadir un nodo que aun no esta en el árbol
	nodo *nuevo = NULL, *ultimo = NULL, *actual=*raiz;
	int nComp = 0;
	
	while(actual!=NULL)
	{
		if((nComp = comparar(d, actual->n))==0){
			printf("El nodo ya existe :/ \n\n");
			break;
		}
		else
		{
			ultimo=actual;
			if(nComp < 0) //buscar el en subarbol izquierdo
				actual = actual->izq;
			else
				actual = actual->der;
		}
	}
	if(actual==NULL)
	{
		nuevo = nuevoNodo();
		nuevo->n = d;
		nuevo->izq = NULL;
		nuevo->der=NULL;		
		
		/*El nuevo nodo pasará a ser la raíz del arbol total si 
		este esta vacio, del subarbol izquierdo de "ultimo" si la comparación 
		fue menor o del subarbol derecho de ultimo si la comparac´n fue mayor */
		if (ultimo==NULL) //arbol vacio
			*raiz = nuevo;
		else if (nComp <0)
			ultimo->izq = nuevo;
		else
			ultimo->der = nuevo;
		return 0;		
	}
		else
			return 2;
	}
	
	
int main (void){
	
	nodo *raiz = NULL;
	
	int a, p;
/*	for (int i = 10; i >0; i--)
	{
		a = insertar(i, &raiz);
	}*/
	a = insertar(5, &raiz);
	a = insertar(10, &raiz);
	a = insertar(1, &raiz);
	a = insertar(45, &raiz);
	a = insertar(2, &raiz);
	a = insertar(78, &raiz);
	a = insertar(3, &raiz);
	a = insertar(974, &raiz);
	
	printf("\nNodo raiz con dirección %d", raiz);
	printf("Recorrido en orden\n");
	inorden(raiz);
	printf("\n\n");
	
	
	p = borrar(45, &raiz);
	printf("El nodo borrado es: %d", p);
	printf("\nNodo raiz con dirección %d", raiz);
	printf("Recorrido en orden\n");
	inorden(raiz);
	printf("\n\n");
	
	
	/*printf("Después de haber borrado un nodo ...");
	printf("Recorrido en orden\n");
	inorden(raiz);
	printf("\n\n");*/
	
/*	printf("Recorrido en pre-orde\n");
	preorden(raiz);
	printf("\n\n");
	
	printf("Recorrido en post-orden \n");
	postorden(raiz);
	printf("\n\n");*/
	
	
	return 0;
}
