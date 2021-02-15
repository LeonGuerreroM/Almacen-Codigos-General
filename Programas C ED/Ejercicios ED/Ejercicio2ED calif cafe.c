#include<stdio.h>

int main(){

int alumnos[21];
int a[11]={0};
int i=0;
for(i=1;i<21;i++){
	scanf("%d",&alumnos[i]);
	if(alumnos[i]>10 || alumnos[i]<1){
		printf("Calificacion no valida");
		break;
	}
	if(alumnos[i]==1){
	a[1]++;
	}else if(alumnos[i]==2){
	a[2]++;
	}else if(alumnos[i]==3){
	a[3]++;
	}else if(alumnos[i]==4){
	a[4]++;
	}else if(alumnos[i]==5){
	a[5]++;
	}else if(alumnos[i]==6){
	a[6]++;
	}else if(alumnos[i]==7){
	a[7]++;
	}else if(alumnos[i]==8){
	a[8]++;
	}else if(alumnos[i]==9){
	a[9]++;
	}else if(alumnos[i]==10){
	a[10]++;
	}
}
	
	for(i=1; i<11; i++){
		printf("El numero de personas que votaron %d ",i);
		printf("Es %d\n",a[i]);
	}
/*for(i=0;i<15;i++){
	p += prom[i];
}
*/


	
return 0;	
}
