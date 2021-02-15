#include<stdio.h>
#include<stdlib.h>
typedef struct ficha 
{
	char nombre[40];
	char direccion[80];
	long telefono;
}tficha;
int ficha=1;



int main(){
	tficha *nuevo;
	int *a;
	int m;
	a= &m;
	tficha aux;
	nuevo= &aux;
	long tel=220047;
	char n1[40]="nayeli";
	char n2[80]="febe 17";
	gets(nuevo->nombre);
	nuevo->telefono=tel;
	gets(nuevo->direccion);
	printf("nombre: %s\n",nuevo->nombre);	
	printf("%d\n",nuevo->telefono);
	printf("%Direccion:%s\n",nuevo->direccion);
	printf("%d\n",aux.telefono);
			tficha var1;
			char nombre[40]="Javier";
			printf("Nombre:");
			gets(var1.nombre);
			scanf("%d",&var1.telefono);
			printf("%s\n",var1.nombre);
			printf("%s\n",nombre);
			printf("%d\n",ficha);
			printf("%d\n",var1.telefono);
}
