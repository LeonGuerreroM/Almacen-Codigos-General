#include<stdio.h>
#include<stdlib.h>

int main()
{
    int opcion;
    do
    {
        printf("\n\nEste es un menu simple\n");
        printf("\n[1] Opcion 1");
        printf("\n[2] Opcion 2");
        printf("\n\nCual es la opcion que deseas? ");
        scanf("%d",&opcion);
    }while(opcion<1 || opcion>2);
    return 0;
}

