#include <stdio.h>
#include <stdlib.h>
#include "funci.h"

int main()
{
    int a,b;
    printf("Ingrese a\n");
    scanf("%d",&a);
    printf("Ingrese b\n");
    scanf("%d",&b);
    printf("Maximo: %d\n",maximo(a,b));
    printf("Minimo; %d\n",minimo(a,b));
    printf("mcd: %d\n",mcd(a,b));
    printf("mcm: %d\n",mcm(a,b));








    return 0;
}
