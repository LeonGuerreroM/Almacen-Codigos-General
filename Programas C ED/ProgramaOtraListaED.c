#include<stdio.h>
#include<stdlib.h>
typedef struct s {
	int n;
	struct s *sig;
}numero;

void error(void);
numero * nuevoElemento();
int tamanio(numero *lista);
int anadir(int i, int n, numero **lista);
int nodoInicio(int n, numero **lista);
int nodoFinal(int n, numero **lista);
void imprimir(numero *lista);
void borrarInicio (numero **lista);
void borrarFinal(numero **lista);
void borrarNodo(int i, numero **lista);
void obtener(int i, numero *lista);
	
void error(void){
	printf("Error, no hay memoria");
	exit(1);
}

numero * nuevoElemento(){
	numero *p = (numero *) malloc(sizeof(numero));
	if(!p) error();
	return p;
}

int tamanio(numero *lista){
	numero *q = lista;
	int n = 0;
	while(q!=NULL){
		n++;
		q = q->sig;
	}
	return n;
}


int anadir(int i, int n, numero **lista){
	int m = 0;
	numero *q = NULL; 
	numero *p = *lista; 	//lista es la cabecera
	numero *anterior = p;
	numero *actual = p;	
	//elemento en la posición i
	int numElementos = tamanio(p);
	
	if(i>numElementos || i<0){
	
		printf("El indoce esta fuera de los elementos \n");
		return 0;		//el índice está fuera de los limites
	//crear el elemento a añadir
}
	q=nuevoElemento();
	q->n = n;
	q->sig = NULL;
	
	//si la lista a la que apunta p esta vacía, hay que añadirlo y comenzar una lista
	if(numElementos == 0){
		*lista = q;
		return 1;
	}
	//si la lista si contiene elementos, entonces hay que buscar el lugar en donde se va a insertar el nodo
	//hay que movernos al elemento
	for (n=0; n<i; n++)
	{
		anterior = actual;
		actual = actual->sig;
	}
	//tenemos dos casos
	//1. insertar al principio
	//2. Insertar después del anterior

	if(anterior == actual)
	{
		q->sig = p;
		p = q;
	}
	else //insertar después del anterior{
	{
		q->sig = actual;
		anterior->sig = q;
	}
	*lista = p;
	return 1;
}

int nodoInicio(int n, numero **lista){
	return anadir(0,n,lista);
}

int nodofinal(int n, numero **lista){
	return anadir(tamanio(*lista),n,lista);
}

void imprimir(numero *lista){
	numero *p = lista;
	int i = 0;
	while(p!=NULL){
		printf("Elemento %d: %d \n",i, p->n);
		p = p->sig;
		i++;
	}
}

void borrarInicio (numero **lista){
	borrarNodo(0,lista);	
}

void borrarFinal(numero **lista){
	borrarNodo(tamanio(*lista)-1, lista);
}

void borrarNodo(int i, numero **lista){
	int n = 0;
	numero *p = *lista; //cabecera
	numero *anterior = p, *actual = p;
	int num;
	float f;
	//borrar elemento de la posición i
	int numElementos = tamanio(p);
	if(i>=numElementos || i <0){
		//return NULL; //el indice está fuera de los límites
		printf("El elemento que quiere borrar no existe");
	}
	//entrar en la lista y encontrar el indice del elemento que se va a borrar
	//posicionarse en el elemento i
	for(n=0; n<i; n++)
	{
		anterior = actual;
		actual = actual->sig;
	}
	//dos casos
	//1. borrar el primer elemento de la lista
	//2. borrar el siguiente al elemento anterior
	if(actual == p) //1
		p=p->sig; //cabecera
	else	//2
		anterior->sig = actual->sig;
		num = actual->n; //solo si quieres guardar el contenido de ese nodo
		free(actual);
		*lista = p;	
}

void obtener(int i, numero *lista){
	
}

int main (void){
	/*numero *lista = NULL;
	int a = nodoInicio(123, &lista);
	nodoInicio(90, &lista);
	nodofinal(8904,&lista);
	anadir(2,7891,&lista);
	anadir(2,79,&lista);
	anadir(1,9,&lista);
	nodofinal(8,&lista);
	imprimir(lista);
	
	//borrando el nodo del final
	borrarFinal(&lista);
	printf("se borró el nodo del final\n");
	imprimir(lista);
	
	printf("se borró el nodo del inicio\n");
	borrarInicio(&lista);
	imprimir(lista);
	
	borrarNodo(2,&lista);
	printf("se borró otro nodo \n");
	imprimir(lista);*/
	
	numero *lista = NULL;
	int a;
	a=nodoInicio(4, &lista);
	a=nodofinal(10101010, &lista);
	anadir(1,234,&lista);
	anadir(2,324,&lista);
	anadir(3,435,&lista);
	anadir(4,546,&lista);
	anadir(5,567,&lista);
	imprimir(lista);
	printf("------------------\n");
	borrarInicio(&lista);
	imprimir(lista);
	printf("------------------\n");
	borrarNodo(3, &lista);
	imprimir(lista);
	printf("------------------\n");
	borrarFinal(&lista);
	imprimir(lista);
	
	return 0;
}
