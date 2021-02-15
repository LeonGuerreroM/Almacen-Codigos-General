#include <stdio.h>
#include <stdlib.h>

int main(){
	
/*int n;
int array [n];
scanf("%d",&n);
printf("La diraccion de array es %.4x",&array);

int i;

for(i=0;i<n;i++){
	scanf("%d",&array[i]);
}*/
//arrays dinamicos o hechos con memoria
int tam;
int *p=NULL;
scanf("%d",&tam);
p=(int*)calloc(tam,sizeof(int));
int i;
for(i=0; i<tam; i++){
	scanf("%d",p+i);
}

for(i=0; i<tam; i++){
	printf("%d \n",*p+i);
}

return 0;	
}
