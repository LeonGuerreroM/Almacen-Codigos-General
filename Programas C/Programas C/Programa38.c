#include<stdio.h>
#include<stdlib.h>

int main()
{
    int numero,bandera=1,i,seguir=1;
    while(seguir==1)
    {
        printf("\n\nIntroduce un numero natural y yo te digo si es primo ");
        scanf("%d",&numero);
        for(i=2;i<=numero+1; i++)
            if(numero%i==0)
            {
                bandera=0;
                break; //el break rompe el for para que detenga las iteraciones
            }
        if(bandera==1)
            printf("\nEl numero por definicion no es primo\n");
        else
            printf("\nEl numero es primo\n");
        printf("\n\nQuieres hacerlo otra vez si[1]/no[0]? ");
        scanf("%d",&seguir);
    }
    return 0;
}
