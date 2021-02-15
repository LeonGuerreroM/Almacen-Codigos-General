#include<stdio.h>
#include<stdlib.h>
enum logico {falso, verdadero}; //Globales, sirven para todo el programa //Usamos llave
enum logico interruptor;

int main(){
    interruptor = falso;
    printf("El valor interruptor vale %d\n\n\n",interruptor); //estamos poniendo %d asi que imprimira su valor numerico
    system("pause");
    return 0;

}
