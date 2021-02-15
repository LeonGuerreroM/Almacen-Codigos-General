#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=sizeof(int); //solo indicas el numero de bytes que se usan para guardar esto
    int f=sizeof(float);
    int s=sizeof(short);
    int c=sizeof(short);
    int d=sizeof(double);
    printf("el tamaño de i es %d\n\n\n",i); //me va a imprimir un numero entero todo pórque son los bytes que guarda cada tipo de dato
    printf("el tamaño de f es %d\n\n\n",f);
    printf("el tamaño de s es %d\n\n\n",s);
    printf("el tamaño de c es %d\n\n\n",c);
    printf("el tamaño de d es %d\n\n\n",d);

   system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}
