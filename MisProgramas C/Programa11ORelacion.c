#include<stdio.h>
#include<stdlib.h>

int main(){
    int p, q;
    float x=15, y=18, z=20;
    p=(x==y);
    printf("El valor de p=(x==y) es %d\n\n\n",p); // Esta forma de pedir el resultado es ineficiente
    q=((x<y)&&(y<=z));
    printf("El valor de q=((x<y)&&(y<=z)) es %d\n\n\n",q);
    system("pause");
    return 0;
}
