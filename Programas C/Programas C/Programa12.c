#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a=0b11100111;
    printf("El valor de a es %d\n\n",a);
    printf("El valor de a & 00001111 es %d\n\n",a&0b00001111);
    printf("El valor de a | 00001111 es %d\n\n",a|0b00001111);
    printf("El valor de a >> 1 es %d\n\n",a>>1);
    system("pause");
    return 0;
}
