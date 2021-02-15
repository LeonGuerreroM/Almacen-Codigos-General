#include<stdio.h>
#include<stdlib.h>

int main(){
    int p=10, q=0; //en c cualquier valor diferente de 0 es verdadero
    printf("El valor de p&&q es %d\n\n\n",p&&q); // %d porque solo son resultados 0 y 1, enteros
    printf("El valor de p||q es %d\n\n\n",p||q);
    printf("El valor de !p es %d\n\n\n",!p);
    system("pause");
    return 0;

}
