#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=sizeof(int); //solo indicas el numero de bytes que se usan para guardar esto
    int f=sizeof(float);
    int s=sizeof(short);
    int c=sizeof(short);
    int d=sizeof(double);
    printf("el tama�o de i es %d\n\n\n",i); //me va a imprimir un numero entero todo p�rque son los bytes que guarda cada tipo de dato
    printf("el tama�o de f es %d\n\n\n",f);
    printf("el tama�o de s es %d\n\n\n",s);
    printf("el tama�o de c es %d\n\n\n",c);
    printf("el tama�o de d es %d\n\n\n",d);

   system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}
