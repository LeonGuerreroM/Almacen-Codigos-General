#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>


int compara (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(){
    printf("Bienvenido. Utilizaremos la funcion qsrot()\n\n\n");
    printf("Esta funcion sirve para ordenar los numeros de un arreglo de menor a mayor. LLene el arreglo \n\n\n");
    int numeros[10];
    int i;
    for(i=0;i<10;i++){
        printf("Introduce la posicion %d\n\n",i);
        scanf("%d",&numeros[i]);
    }
    printf("El orden en el que escribiste los numeros fue: \n\n");
    for(i=0;i<10;i++){
        printf("%d\n\n",numeros[i]);
    }
    qsort(numeros, 10, sizeof(int), compara);
    printf("\n\nAhora se mostraran ordenados \n\n");
    Sleep(3000);

    for(i=0;i<10;i++){
        printf("%d\n\n",numeros[i]);
    }

    qsort(numeros, 10, sizeof(int), compara);
    printf("El valor mayor es: %d\n\n",numeros[9]);
    printf("El valor menor es: %d\n\n",numeros[0]);
    printf("Hasta Luego");
    return 0;
    }
