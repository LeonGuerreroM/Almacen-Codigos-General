#include<stdio.h>
#include<stdlib.h>

#define filas 3
#define columnas 4

int main()
{
    float sistema_ecuaciones[filas][columnas];
    int i,j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("\nIntroduce fila %d columna %d: ",i,j);
            scanf("%f",&sistema_ecuaciones[i][j]);
        }
    }
    printf("\n\n");
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("%f\t",sistema_ecuaciones[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}
