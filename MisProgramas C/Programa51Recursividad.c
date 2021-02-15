#include<stdio.h>
#include<stdlib.h>

long introduce_numero();
long calcula_factorial(long n);

int main()
{
    short opcion;
    long numero,resultado;
    do
    {
        printf("\n\nMenu de calculadora\n");
        printf("\n[1] Factorial ");
        printf("\n[2] Salir");
        printf("\n\nElige opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                numero=introduce_numero();
                resultado=calcula_factorial(numero);
                printf("\n\nEl resultado es: %ld",resultado);
                break;
            case 2:
                printf("\n\nAdios");
                break;
            default:
                printf("\n\nTe equivocaste de opcion");
        }
    }while(opcion!=2);
    return 0;
}

long introduce_numero()
{
    long numero;
    printf("\nIntroduce el numero: ");
    scanf("%ld",&numero);
    return numero;
}

long calcula_factorial(long n)
{
    if(n==0)
        return 1;
    else
        return n*calcula_factorial(n-1);
}
