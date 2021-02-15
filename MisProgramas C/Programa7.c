#include<stdio.h>
#include<stdlib.h>

int main(){
    volatile int meses = 12; //el volatile hace que la constante pueda ser modificada en algunas ocasiones. Per las variables si se guardan en registros, estas no
    printf("El valor de meses es %d\n\n\n",meses);
    system("pause");
    return 0;

}
