#include<stdio.h>
#include<stdlib.h>

#define MAX 100
//Metodo de la burbuja
int main()
{
    int arreglo[MAX],n,i,j,aux;
    printf("\n\nIntroduce cuantos numeros deseas que ordene de menor a mayor: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\nNumero %d: ",i+1); //no hay modificacion en i, solo imprime i ya con el 1 sumado
        scanf("%d",&arreglo[i]);
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(arreglo[i]>arreglo[j])
            {
                aux=arreglo[i];
                arreglo[i]=arreglo[j];
                arreglo[j]=aux;
            }
    printf("\n\nLos datos ordenados son: ");
    for(i=0;i<n;i++)
        printf("%d\t",arreglo[i]);
    return 0;
}
