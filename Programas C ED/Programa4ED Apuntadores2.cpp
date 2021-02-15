#include<stdio.h>

int main(){

/*int a = 10;
int *p;
p=&a; //que apunte a su direccion
*p=*p+3;
printf("Valor de a %d\n",*p);*/

/*int a;
int *p;
scanf("%d",p);
printf("%d",p); //como p es apuntador y por si solo marca a la direccion, entonces no hay que poner &
*/

//un arreglo es un apuntador
int *p;
int a[]={1,2,3};
*p=&a;
printf("%.4x\n",p+=1);
printf("%.4x\n",p+=1);
printf("%.4x\n",p+=1);


	
return 0;	
}

