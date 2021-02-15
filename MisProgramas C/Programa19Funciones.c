#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//cuando las funciones se ponen ariba de main se estan definiendo y declarando las funciones al mismo tiempo
int variableGlobal=10;

void funcion1 (void){ //al indicar parametro le puedo poner vooid o no, al inicio siempre
    puts("Esta es la funcion 1"); //pribntf sin formato
}

void funcion2 (){
    printf("\n\n\nEsta es la funcion 2\n\n\n");
    printf("La variable global vale %d\n\n\n",variableGlobal);
}


int main()
{
    int variableLocal=5;
    printf("Mi variable local vale %d\n\n\n",variableLocal);
    Sleep(2000); //sleep es que se espere, se cuenta en milisegundos
    funcion1();
    Sleep(3000);
    funcion2();
    system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 50000; //puedo poner en lugar del 0 lo que quiera, es el valor de retorno, pero como nunca lo mando a llamar, no lo imprime en pantalla
}
