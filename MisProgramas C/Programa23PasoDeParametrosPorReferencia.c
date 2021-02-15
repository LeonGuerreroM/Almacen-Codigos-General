#include<stdio.h>
#include<stdlib.h>
//En este paso de parametros no se cambia el valor en el hogar de la variable porque se esta creando otra variable
void funcion1(int *a);

int main()
{
    int a=18;
    printf("El valor de a es %d\n\n\n",a);
    funcion1(&a); //por el & (direccion de) le da la direccion de la variable (basicamente, este tipo de paso de parametro si cambia la variable)
    printf("La variable en main ahora vale %d\n\n\n",a);
    system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}

void funcion1(int *a){ //*a variable de direccion o APUNTADOR
    *a=*a+10;
    printf("La variable que me mandaron, yo la modifique y ahora vale %d\n\n\n",*a);
}
