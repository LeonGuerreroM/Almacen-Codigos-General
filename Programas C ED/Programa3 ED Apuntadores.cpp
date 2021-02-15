#include<stdio.h>

int main(){

int a;
int *p; //declaracion de un apuntador
printf("El valor de a es: %d \n",a);
printf("La direccion de a es: %.4x \n",&a); //Con el & mandas a llamar a la direccion

printf("El valor de p es: %d \n",p);
printf("La direccion de p es: %.4x \n",&p); //direccion normal de p

//formas de p como apuntador
p=&a; //P apunta a la direccion de a
printf("El valor de p es: %d \n",p); //Valor de p que es igual a la DIRECCION DE A
printf("La direccion de p es: %.4x \n",&p); //direccion NORMAL de p
printf("El valor de a es: %d \n",*p); //como esta apuntando a A entonces poniendole mandas a llamar al VALOR DE A

return 0;	
}

