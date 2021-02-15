#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef enum {false, true} bool;
typedef int Elemento;


typedef struct node{
	Elemento dato;
	struct node *sig;
}*Nodo, nodo;

typedef struct encab{
	unsigned long longt;
	Nodo frente, ult ;
}*Cola, head;

bool creaCola(Cola *Q);
bool inserta(Cola Q, Elemento E);
bool elimina(Cola Q, Elemento *E);
bool vacia(Cola Q);
void destruye(Cola Q);
int frente(Cola Q);
void impCola(Cola Q);

int main(){
	int i=0;
	Elemento E=0;
	Cola Q=0;
	
	creaCola(&Q);
	
	for(i=0; i<10; i++){
		inserta(Q, i);
	}
	
	impCola(Q);
	
	for(i=0; i<10; i++){
		elimina(Q, &E);
	}
	
	destruye(Q);
return 0;	
}

bool creaCola(Cola *Q){
	*Q=(Cola)malloc(sizeof(head));
	
	if(*Q==NULL){
		return false;
	}
	
	(*Q)->longt=0;
	(*Q)->frente=NULL;
	//(*q)->frente->sig=NULL;
	(*Q)->ult=NULL;
	//(*q)->ult->sig=NULL;
	
	return true;
}


void destruye(Cola Q){
	Nodo aux = 0;
	if(vacia(Q)!=true){
		while(Q->frente!=NULL){
			aux=Q->frente;
			Q->frente=Q->frente->sig;
			free(aux);
		}
	}
	free(Q);
}

bool vacia(Cola Q){
	if(Q==NULL){
		return true;
	}
	
	if(Q->longt==0){
		return true;
	}
	
	return false;
	
}

int frente(Cola Q){
	if(Q->longt>0){
		return(Q->frente->dato);
	}
	return 0;
}

bool inserta(Cola Q, Elemento E){
	Nodo aux = 0;
	aux = (Nodo)malloc(sizeof(nodo));
	if(aux==NULL)
	return false;
	
	if(Q->longt>0)
	Q->ult->sig=aux;
	else
	Q->frente=aux;
	
	aux->sig=NULL;
	aux->dato=E;
	Q->ult=aux;
	Q->longt++;
	return true;
}

bool elimina(Cola Q, Elemento *E){
	Nodo aux = 0;
	
		if(Q==NULL){
		return false;
	}
	
	if(Q->longt==0){
		return false;
	}
	
	*E=Q->frente->dato;
	aux=Q->frente;
	Q->frente=Q->frente->sig;
	free(aux);
	Q->longt;
	
	if(Q->longt==0){
		Q->frente=NULL;
		Q->ult=NULL;
	}
	return true;
}

void impCola(Cola Q){
	Nodo aux = 0;
	
	aux=Q->frente;
	printf("<");
	while(aux!=NULL){
		printf("%d",aux->dato);
		if(aux->sig!=NULL){
		printf(",");
		aux=aux->sig;
	}
	printf(">");
	}
}

//el sistema operativo usa colas circulares
