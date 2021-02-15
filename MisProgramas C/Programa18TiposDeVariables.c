#include<stdio.h>
#include<stdlib.h>

int variableGlobal=10;

int main()
{
    int variableLocal=5, suma;
    suma=variableLocal+variableGlobal;
    printf("El valor de suma es %d\n\n\n",suma);
    system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}
