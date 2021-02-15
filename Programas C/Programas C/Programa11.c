#include<stdio.h>
#include<stdlib.h>

int main()
{
    int p,q;
    float x=15, y=18, z=20;
    printf("El valor de p=x==y: %d\n\n",p=x==y);
    printf("El valor de q=(x<y)&&(y<=z): %d\n\n",q=(x<y)&&(y<=z));
    system("pause");
    return 0;
}
