#include<stdio.h>

int main(){

int array[50] = {0};
int i, aux;
for(i=0;i<50;i++){
	//printf("array[%d] = %d\n",i,array[i]);
	//array[i] = i-4;
	scanf("%d",aux);
	array [i]=aux;
    printf("array[%d] = %d\n",i,array[i]);
	//printf("%d",array[i]);
	
}


	
return 0;	
}

