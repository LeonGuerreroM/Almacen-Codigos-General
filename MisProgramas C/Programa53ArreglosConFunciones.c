#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 10
//todo arreglo ya es apuntador porque su direccion apunte a su primera posicion
void introduce_valores(int a[]);
void muestra_valores(int *a); //recibir las cosas como apuntador

int main()
{
    int a[MAX];
    introduce_valores(a);
    muestra_valores(a);
    return 0;
}

void introduce_valores(int a[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("\nIntroduce el valor a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

void muestra_valores(int *a)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("\nValor de a[%d]: %d",i,a[i]);
    }
}
