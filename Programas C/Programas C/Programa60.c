#include<stdio.h>
#include<stdlib.h>

int funcion(int a);

int main()
{
    int a;
    int (*pf)(int); //Definiccion de un apuntador a funcion, el primer Int es por el tipo de dato que debe retornar la funcion y el segundo por el tipo de dato que tendra el apuntador
    a=10;
    pf=funcion; //apunta a la funcion. Como las funciones tienen direcciones implicitas entonces no se necesita el &
    printf("\n\nValor de pf= %p ",pf);
    printf("\nValor final de a= %d\n\n",pf(a)); //mandar a llamar funcion a traves del apuntador
    return 0;
}

int funcion(int a)
{
    a=400;
    return a;
}
