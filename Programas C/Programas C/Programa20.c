#include<stdio.h>
#include<stdlib.h>

int variableGlobal=10;
void funcion1(void);
void funcion2();

int main()
{
    int variableLocal=5;
    printf("\nMi variable local vale: %d\n",variableLocal);
    sleep(2);
    funcion1();
    sleep(3);
    funcion2();
    return 0;
}

void funcion1(void)
{
    puts("\nEsta es la funcion 1\n");
}

void funcion2()
{
    printf("\nEsta es la funcion 2\n");
    printf("\nLa variable global vale: %d\n",variableGlobal);
}
