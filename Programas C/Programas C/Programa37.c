#include<stdio.h>
#include<stdlib.h>

int main()
{
    int asteriscos;
    printf("\n\nCuantos asteriscos quieres imprimir? ");
    scanf("%d",&asteriscos);
    printf("\n");
    while(asteriscos>0)
    {
        printf("*");
        asteriscos--;
    }
    printf("\n");
    return 0;
}
