#include<stdio.h>
#include<stdlib.h>

#define funcion(x) ((x)<-1?-(x)*(x)-3:(x)+2)

int main()
{
    printf("\nEl resultado es: %f\n\n",funcion(1.2));
    return 0;
}
