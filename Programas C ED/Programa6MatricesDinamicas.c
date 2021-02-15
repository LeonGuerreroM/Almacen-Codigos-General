#include<stdio.h>
#include<stdlib.h>

int main(){

int **p;
int **q;
int **r;
int filas, columnas;
int i, j;

printf("Dame las filas \n");
scanf("%d",&filas);
printf("Dame las columnas \n");
scanf("%d",&columnas);

p=(int**)calloc(filas,sizeof(int*)); //como es arreglo de apuntadores int* calcula el tamaño de un apuntador de entero
for(i=0;i<columnas;i++){
	p[i]=(int*)calloc(columnas,sizeof(int));
}

printf("Dame los valores \n");
for(i=0;i<filas;i++){
	for(j=0;j<columnas;j++){
		scanf("%d",&p[i][j]); //o p[i]+j & porque lo gaurad en direccion de p... aunque sea apuntador
	}
}

for(i=0;i<filas;i++){
	printf("\n");
	for(j=0;j<columnas;j++){
		printf("%d ",p[i][j]);
	}
}





q=(int**)calloc(filas,sizeof(int*)); //como es arreglo de apuntadores int* calcula el tamaño de un apuntador de entero
for(i=0;i<columnas;i++){
	q[i]=(int*)calloc(columnas,sizeof(int));
}
printf("\nDame los valores \n");
for(i=0;i<filas;i++){
	for(j=0;j<columnas;j++){
		scanf("%d",&q[i][j]); //o p[i]+j & porque lo gaurad en direccion de p... aunque sea apuntador
	}
}

for(i=0;i<filas;i++){
	printf("\n");
	for(j=0;j<columnas;j++){
		printf("%d ",q[i][j]);
	}
}





r=(int**)calloc(filas,sizeof(int*)); //como es arreglo de apuntadores int* calcula el tamaño de un apuntador de entero
for(i=0;i<columnas;i++){
	r[i]=(int*)calloc(columnas,sizeof(int));
}

for(i=0;i<filas;i++){
	for(j=0;j<columnas;j++){
		r[i][j]=p[i][j]+q[i][j]; //o p[i]+j & porque lo gaurad en direccion de p... aunque sea apuntador
	}
}
printf("\nLa matriz con suma es: \n");
for(i=0;i<filas;i++){
	printf("\n");
	for(j=0;j<columnas;j++){
		printf("%d ",r[i][j]);
	}
}






	
return 0;	
}

