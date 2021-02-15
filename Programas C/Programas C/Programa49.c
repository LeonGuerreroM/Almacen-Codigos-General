#include<stdio.h>
#include<stdlib.h>

#define clave -1

int main()
{
    int n,i;
    printf("\n\nIntroduce un numero: ");
    while(scanf("%d",&n))
    {
        if(n!=clave)
            printf("\n\nIntroduce un numero: ");
        else
            break;
    }
    return 0;
}
