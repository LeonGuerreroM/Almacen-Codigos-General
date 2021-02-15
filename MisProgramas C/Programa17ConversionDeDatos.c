#include<stdio.h>
#include<stdlib.h>

int main(){
    long a =2;
    u-nsigned char b=67;
    int c=23;
    float d=2.3;
    int f;
    f = a+b+c+d; //aunque la suma es un float lo convierte a int porque el tipo del resultado es int, lo importante es el tipo del resultado
    printf("El valor de f es %d\n\n\n",f);
   system("pause"); //este es para finalizar ejecucuion, solo en dev c hace falta
   return 0;
}
