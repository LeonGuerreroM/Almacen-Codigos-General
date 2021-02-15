#include<stdio.h>
#include<stdlib.h>

int main()
{
    char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p;
    int i;
    p=&alfabeto[0];
    for(i=0;i<sizeof(alfabeto)-1;i++,p++)
        printf("\nLa letra es: %c",*p);
    printf("\n\nLa longitud de la cadena es es: %d",i);
    return 0;
}
