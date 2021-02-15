#include <stdio.h>
#include <stdlib.h>

typedef struct nuevo //con typedef lo llamo con primer nombre
{
	int n;
	float f;
	struct nuevo *sig;
	
}numero; //segundo nombre, sin typedef

void error();

numero* nuevo_elemento();

void llenar_nodo(numero *aux, int a, float b);

void imprimir(numero *aux);

int buscaN(numero *aux, int a);

void borrar (numero *aux, int p);

void nodoInicio(numero *inicio);

int main(){
 numero *nodo1 = NULL;
 numero *nodo = NULL; //con un nodo basta porque al final de la union se va a desechar
 numero *inicio = NULL;
 inicio=nuevo_elemento();
 inicio->sig=NULL;
 inicio->n=80;
 inicio->f=0.47;
 //printf("Entero n = %d \n",inicio->n);
 //printf("Float f = %f \n",inicio->f);
 nodo=nuevo_elemento();
 nodo->sig=inicio;
 inicio=nodo;
 nodo1=nuevo_elemento();
 nodo1->sig=inicio;
 inicio=nodo1;
 nodo1=nuevo_elemento();
 nodo1->sig=inicio;
 inicio=nodo1;
 nodo1=nuevo_elemento();
 nodo1->sig=inicio;
 inicio=nodo1;
 nodo=inicio;
 //llenar_nodo(inicio, 87, .26);
 llenar_nodo(nodo, 20, .7);
 nodo = nodo->sig;
 //llenar_nodo(inicio->sig, 54, .85); //porque es el 2, es el siguiente de la primera
 llenar_nodo(nodo, 40, .2);
 nodo = nodo->sig;
 //llenar_nodo(inicio->sig->sig, 54, .85);
 llenar_nodo(nodo, 100, .26);
 nodo = nodo->sig;
 llenar_nodo(nodo, 7, .81);
 nodo = nodo->sig;
 llenar_nodo(nodo, 10, 3.1416);
 /*imprimir(inicio);
 imprimir(inicio->sig);
 imprimir(inicio->sig->sig);*/
 nodo=inicio;
 imprimir(nodo);
 int x;
 int c;
 printf("Escribe el numero a buscar\n");
 scanf("%d",&x);
 nodo=inicio;
 c=buscaN(nodo, x);
 if(c!=0){
 printf("Esta en la posicion %d\n",c);
 }else{
 printf("Valor no encontrado");
 }
 nodo=inicio;
 borrar(nodo,c);
 nodo=inicio;
 imprimir(nodo);
 printf("------------------\n");
 nodoInicio(inicio);
 llenar_nodo(inicio, 8, .1);
 nodoInicio(inicio);
 llenar_nodo(inicio, 9, .11561);
 imprimir(inicio);
return 0;
}


void error(){
	printf("no hay memoria");
	exit(1); //salir de una funcion void

}


numero* nuevo_elemento(){
	numero *p = (numero*)malloc(sizeof(numero));
	if(!p){
		error();
	}else
	return p;
}

void llenar_nodo(numero *aux, int a, float b){
	aux->n=a;
	aux->f=b;
}

void imprimir(numero *aux){
	/*if(aux!=NULL){
		printf("Entero n = %d \n",aux->n);
        printf("Float f = %f \n",aux->f);
	}*/
	while(aux!=NULL){
		printf("Entero n = %d \n",aux->n);
        printf("Float f = %f \n",aux->f);
        aux=aux->sig;
	}
}

int buscaN(numero *aux, int a){
	int cont = 1;
	while(aux!=NULL){
		if(aux->n==a){
		return cont;
	}else{
		cont++;
        aux=aux->sig;
	}
	if(aux==NULL){
		return 0;
	}
}
}

void borrar (numero *aux, int p){
	numero *aux2;
	int i;
	for(i=0; i<p-2; i++){
		aux=aux->sig;
	}
	aux2 = aux->sig;
	aux->sig=aux2->sig;
	free(aux2);
}

void nodoInicio(numero *inicio){
	numero *q;
	q = nuevo_elemento();
	q->sig=inicio;
	inicio = q;
}


