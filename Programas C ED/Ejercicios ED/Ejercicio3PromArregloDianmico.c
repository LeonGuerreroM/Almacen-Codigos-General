#include<stdio.h>

int main(){

int tam;
int *p=NULL;
scanf("%d",&tam);
p=(int*)calloc(tam,sizeof(int));
int i;
for(i=0; i<tam; i++){
	scanf("%d",p+i);
}
int r = 0;
for(i=0;i<tam;i++){
	r += *p;
}

float q = r/tam;
printf("%f",q);





/*int prom[15];
int i;
int p = 0;
for(i=0;i<15;i++){
	scanf("%d",&prom[i]);
    //printf("array[%d] = %d\n",i,array[i]);
	//printf("%d",array[i]);	
}

for(i=0;i<15;i++){
	p += prom[i];
}
float q = p/15;
printf("%f",q);
*/


	
return 0;	
}

