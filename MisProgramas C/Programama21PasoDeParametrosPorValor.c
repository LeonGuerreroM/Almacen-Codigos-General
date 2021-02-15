#include<stdio.h>
#include<stdlib.h>
//En este paso de parametros no se cambia el valor en el hogar de la variable porque se esta creando otra variable
void funcion1(int b);

int main()
{
    int a=18;
    printf("El valor de a es %d\n\n\n",a);
    funcion1(a); //aqui es cuando mandoel parametro          //EL PARAMETRO A QUE ES EL QUE YO LE ESTOY MANDANDO SE ALMACENA EN LA VARIABLE QUE MI FUNCION TENGA QUE EJN ESTE CASO ES BA, O SEA, CAMBIA SU NOMBRE PERO LE PASO EL VALOR DE A
    printf("La variable en main sigue valiendo %d\n\n\n",a);
    system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}

void funcion1(int b){
    b=b+10; //modificacion con simple suma tipo contador
    printf("La variable que me mandaron, yo la modifique y ahora vale %d\n\n\n",b);
}
