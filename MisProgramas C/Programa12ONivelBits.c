#include<stdio.h>
#include<stdlib.h>

int main(){
    int a=0b11100111, b;
    printf("El valor de a es %d\n\n\n",a);
    b=a & 00001111;
    printf("El valor de a & 00001111 es %d\n\n\n",b);
    b=a | 00001111;
    printf("El valor de a | 00001111 es %d\n\n\n",b);
    b=a>>1;
    printf("El valor de a>>1 es %d\n\n\n",b);
    system("pause");
    return 0;
}
