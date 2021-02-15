#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=sizeof(int);
    int f=sizeof(float);
    int s=sizeof(short);
    int c=sizeof(char);
    int d=sizeof(double);
    printf("El tamaño de i es %d\n\n",i);
    printf("El tamaño de f es %d\n\n",f);
    printf("El tamaño de s es %d\n\n",s);
    printf("El tamaño de c es %d\n\n",c);
    printf("El tamaño de d es %d\n\n",d);
    system("pause");
    return 0;
}
