#include<stdio.h>
#include<stdlib.h>

int funcion();

int main()
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("\nLa variable estatica vale: %d\n\n",funcion());
    }
    return 0;
}

int funcion()
{
    static int i=0;
    printf("\nLa variable estatica vale: %d\n\n",i);
    i++;
    return i;
}
