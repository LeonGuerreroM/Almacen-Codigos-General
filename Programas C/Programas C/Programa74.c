#include<stdio.h>
#include<stdlib.h>

int main()
{
    float *apuntador;
    float *auxiliar;
    int n,i;
    do
    {
        printf("\nCuantas elementos tiene tu vector? ");
        scanf("%d",&n);
    }while(n<1);
    apuntador=(float*)calloc(n,sizeof(float));
    auxiliar=apuntador;
    for(i=0;i<n;i++)
    {
        printf("\nElemento [%d]: ",i+1);
        scanf("%f",&apuntador[i]);
    }
    apuntador=auxiliar;
    printf("\n\nLos elementos de tu vector son:\n\n");
    for(i=0;i<n;i++)
    {
       printf("%f\n",apuntador[i]);
    }
    free(apuntador);
    return 0;
}
