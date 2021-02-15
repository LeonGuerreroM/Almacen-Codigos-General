#include<stdio.h>
#include<stdlib.h>

extern void leerReal(void);

float f;

int main()
{
    leerReal();
    printf("\nEl valor de f es: %f\n\n",f);
    return 0;
}
