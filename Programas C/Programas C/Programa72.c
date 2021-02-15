#include<stdio.h>
#include<stdlib.h>
//dependiendo de lo que pida el usuario asignaremos memoria
int main()
{
    int **apuntador; //apuntador doble para una matriz
    int **auxiliar; //para guardar la direccion despues de todas las operaciones
    int n,m,i,j;
    do
    {
        printf("\nCuantas filas tiene tu matriz? ");
        scanf("%d",&n);
    }while(n<1);
    apuntador=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        printf("\nCuantas columnas tiene la fila %d? ",i+1);
        scanf("%d",&m);
        apuntador[i]=(int*)malloc(m*sizeof(int));
        auxiliar=apuntador;
        for(j=0;j<m;j++)
        {
            printf("\nElemento [%d][%d]: ",i+1,j+1);
            scanf("%d",&apuntador[i][j]);
        }
    }
    apuntador=auxiliar;
    printf("\n\nLos elementos de tu matriz son:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",apuntador[i][j]);
        }
        printf("\n");
    }
    free(apuntador);
    return 0;
}
