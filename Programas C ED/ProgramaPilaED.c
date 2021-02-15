#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct s{
			int dato;
			float f;
			struct s *sig;		
}ElementoPila;

void error(void)
{
				printf("No hay memoria");
				exit(1);
}

ElementoPila * nuevoE()
{
	ElementoPila *q = (ElementoPila*)malloc(sizeof(ElementoPila));
				
				if(!q) 
				error();
				return q;
}

void Push(int n, ElementoPila **pila);
void Pop(ElementoPila **pila);
int main(){
	ElementoPila *p = NULL;
	ElementoPila *tope;
	p=nuevoE();
	p->sig=NULL;
	tope=p;	
	
	Push(10, &tope);
	Push(20, &tope);
	Pop(&tope);
	Pop(&tope);
	Pop(&tope);
	Push(100, &tope);
}

void Push(int n, ElementoPila **pila){
	ElementoPila *p = *pila;
	ElementoPila *q = nuevoE();
	q->dato=n;
	q->sig=p;
	p=q;
	*pila = p;
}

void Pop(ElementoPila **pila){
	ElementoPila *p=*pila;
	printf("%d \n", p->dato);
	*pila=p->sig;
	free(p);
}




		
