#include <stdio.h>
#include <stdlib.h>

typedef struct ficha
{
char nombre[40];
char direccion[80];
long telefono;	
} tficha;
int ficha = 1;

int main (){
tficha var1;
char nombre[40]="javier";
printf("Nombre:");
gets(var1.nombre);
scanf("%d",&var1.telefono);
printf("%s\n",var1.nombre);
printf("%s\n",nombre);
printf("%d\n",ficha);
printf("%d\n",var1.telefono);


return 0;
}
