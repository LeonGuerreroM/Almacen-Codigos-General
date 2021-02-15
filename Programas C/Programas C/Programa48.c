#include<stdio.h>
#include<stdlib.h>

#define clave -1

int main()
{
    int n,i;
    printf("\n\nIntroduce un numero: ");
    scanf("%d",&n);
    for(i=0; i<100; i++)
    {
        if(n==clave)
            continue;
            printf("\n\nIntroduce un numero: ");
         scanf("%d",&n);
    }
    return 0;
}
