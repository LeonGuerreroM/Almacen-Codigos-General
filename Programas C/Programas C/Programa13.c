#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a=1,b=10,c;
    c=a++;
    printf("El valor de c es %d\n\n",c);
    c=++a;
    printf("El valor de c es %d\n\n",c);
    c=--a;
    printf("El valor de c es %d\n\n",c);
    c=a--;
    printf("El valor de c es %d\n\n",c);
    c+=b;
    printf("El valor de c es %d\n\n",c);
    system("pause");
    return 0;
}
