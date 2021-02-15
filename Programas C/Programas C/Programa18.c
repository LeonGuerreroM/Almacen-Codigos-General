#include<stdio.h>
#include<stdlib.h>

int variableGlobal=10;

int main()
{
    int variableLocal=5, suma;
    suma=variableLocal+variableGlobal;
    printf("\nLa variable suma vale: %d\n",suma);
    return 0;
}
