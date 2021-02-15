#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct nuevo{
			int n;
			float f;
			struct nuevo *sig;
			struct nuevo *ant;
			}numero;
			
numero * nuevoE()
{
			numero *aux;
			aux=(numero*)malloc(sizeof(numero));
				
				if(!aux/*=null*/) 
				{
				printf("No hay memoria");
				exit(1);
				return aux;
				}
}

void error(void)
{
				printf("No hay memoria");
				exit(1);
}

int imprimir(numero *p);
void imprimirA(numero *p);
int buscaN(numero *aux, int a);
//void crear_nodo(numero *p);
void borra(numero *aux, int p);
numero* borraI(numero *inicio);
numero* borraF(numero *final);
void borraLoQueSea(int c, numero *inicio, numero *final, int x);

int main(){
	numero *inicio,*final;
	numero *p,aux;
	
		p=nuevoE();
		p->sig=NULL;
		final=p;
		p->ant=NULL;
		inicio=p;
		p->n=40;
		p->f=3.14;
		
		
		p=nuevoE();
		p->sig=inicio;
		inicio->ant=p; 
		inicio=p;
		inicio->ant=NULL;
		inicio->n=430;
		inicio->f=4.14;
		
		p=nuevoE();
		p->sig=inicio;
		inicio->ant=p; 
		inicio=p;
		inicio->ant=NULL; 
		inicio->n=222;
		inicio->f=1.45;
		
		p=nuevoE();
		p->sig=inicio;
		inicio->ant=p; 
		inicio=p;
		inicio->ant=NULL;  
		
		inicio->n=3928;
		inicio->f=9.34;
		
		p=nuevoE();
		p->sig=inicio;
		inicio->ant=p; 
		inicio=p;
		inicio->ant=NULL;  
		
		inicio->n=1;
		inicio->f=5.78;
		/*printf("%d \n",p->n);
		printf("%f \n",p->f);
		printf("%d \n",inicio->n);
		printf("%f \n",inicio->f);*/
		/*printf("%x \n",inicio);
		printf("%x \n",inicio->ant);
		printf("%x \n",inicio->sig);
		printf("%x \n",final);
		printf("%x \n",final->ant);
		printf("%x \n",final->sig);*/
		
		int y=imprimir(inicio);
		printf("%d \n",y);
		//imprimirA(final);
		//crear_nodo(p->ant);
		int c=buscaN(inicio, 1);
		printf("%d \n",c);
		
		//borra(inicio, c);
		//borraI(inicio);
		
		//imprimirA(final);
		//inicio=borraI(inicio);
		//final=borraF(final);
		borraLoQueSea(c, inicio, final, y);
		//imprimirA(final);
		imprimir(inicio);
}

int imprimir(numero *p){
	numero *aux;
	aux=p;
	int x;
	while(aux!=NULL)
	{
		printf("%d \n",aux->n);
		printf("%f \n",aux->f);
	
	
	aux=aux->sig;
	x++;
	}
	return x;
}

void imprimirA(numero *p){
	numero *aux;
	aux=p;
	while(aux!=NULL)
	{
		printf("%d \n",aux->n);
		printf("%f \n",aux->f);
	
	
	aux=aux->ant;
	}
}

/*void crear_nodo(numero *p){
		p=nuevoE();
		p->sig=inicio;
		inicio->ant=p; 
		inicio=p;
		inicio->ant=NULL; 
}*/

int buscaN(numero *aux, int a){
	int cont = 0;
	while(aux!=NULL){
		if(aux->n==a){
		return cont;
	}else{
		cont++;
        aux=aux->sig;
	}
	/*if(aux==NULL){
		return 0;
	}*/
}
}

void borra(numero *aux, int p){
	numero *aux2;
	int i;
	for(i=0; i<p-1; i++){
		aux=aux->sig;
	}
	aux2 = aux->sig;
	aux->sig=aux2->sig;
	aux2->sig->ant=aux;
	free(aux2);
}
numero* borraI(numero *inicio){
	numero *aux;
	aux=inicio;
	inicio=aux->sig;
	inicio->ant=NULL;
	free(aux);
	return inicio;
}
numero* borraF(numero *final){
	numero *aux;
	aux=final;
	final=aux->ant;
	final->sig=NULL;
	free(aux);
	return(final);
}

void borraLoQueSea(int c, numero *inicio, numero *final, int x){
	if(c==0){
		inicio=borraI(inicio);
	}else if(c>0 && c<x-1){
		borra(inicio, c);
	}else if(c==x-1){
		final=borraF(final);
	}
	
	
	
}

