#include<stdio.h>
#include<stdlib.h>

#define clave 007

int main()
{
    int numero;
    for(;;) //bucle infinito
    {
        printf("\n\nIntroduce la clave XXX para salir: ");
        scanf("%d",&numero);
        if(numero==clave)
        {
            printf("\nLo has logrado\n");
            break;
        }
    }
    return 0;
}
