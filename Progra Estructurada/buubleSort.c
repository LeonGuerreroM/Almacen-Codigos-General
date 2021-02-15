#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamano, aux;
    int i, j, k;
    int array[100];

    printf("Bienvenido al Ordenamiento Burbuja\n");
    printf("Ingrese el tamaño del arreglo (maximo 100)\n");
    scanf("%d",&tamano);



    for(i=0;i<tamano;i++){
        printf("Ingresa el elemento %d\n",i);
        scanf("%d",&array[i]);
    }


    for(i=0;i<tamano;i++){
        printf("La poicion %d del arreglo es %d\n",i,array[i]);
    }

    printf("\n\n");
    for(j=0;j<tamano-1;j++){
            for(i=0;i<tamano;i++){
                    printf(" arreglo: %d ",array[i]);
                }
                printf("\n\n\n");
        for(i=0;i<tamano-(1+j);i++){
            if(array[i]>array[i+1]){
                aux = array[i+1];
                array[i+1]=array[i];
                array[i]=aux;


            }
        }
    }


    printf("\n\n\n");

    for(i=0;i<tamano;i++){
        printf("\La posicion %d del arreglo ordenado es %d\n",i,array[i]);
    }




    return 0;
}
