#include<stdio.h>
#include<stdlib.h>


void burbuja(int *a, int x);

int main(){
	int x=4;
	int array[]={1,2,3,4};
	int i, j, aux;
	int *a;
	
	for(i=0; i<x-1; i++){
		for(j=0; j<(x-(i+1)); j++){
			if(array[j]>array[j+1]){
			aux=array[j+1];
			array[j+1]=array[j];
			array[j]=aux;
				}
			}
	}
	
	for(i=0; i<x; i++){
	printf("%d\n",array[i]);
}
	
	printf("-----------\n");
	printf("Indique el numero de casillas del arregalo\n");
	scanf("%d",&x);
	a=(int *)malloc(sizeof(int)*x);
	
	printf("LLene el arreglo\n");
	
		for(i=0; i<x; i++){
		printf("Posicion array[%d]",i);
		scanf("%d",&a[i]);
}
	
	for(i=0; i<x-1; i++){
		for(j=0; j<(x-(i+1)); j++){
			if(a[j]>a[j+1]){
			aux=a[j+1];
			a[j+1]=a[j];
			a[j]=aux;
				}
			}
	}
	
	for(i=0; i<x; i++){
	printf("%d\n",a[i]);
}
	printf("--------\n");
	int *y;
	printf("Indique el numero de casillas del arregalo\n");
	scanf("%d",&x);
	y=(int *)malloc(sizeof(int)*x);
	
	printf("LLene el arreglo\n");
	
		for(i=0; i<x; i++){
		printf("Posicion array[%d]",i);
		scanf("%d",&y[i]);
}
	burbuja(y, x);
	
	
	
	
	return 0;
}

void burbuja(int *a, int x){
	int i, j, aux;
	for(i=0; i<x-1; i++){
		for(j=0; j<(x-(i+1)); j++){
			if(a[j]>a[j+1]){
			aux=a[j+1];
			a[j+1]=a[j];
			a[j]=aux;
				}
			}
	}
	
	for(i=0; i<x; i++){
	printf("%d\n",a[i]);
}
	
}
