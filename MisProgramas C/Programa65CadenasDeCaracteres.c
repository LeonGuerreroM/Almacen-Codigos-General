#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[]="ABCD";
    int i;
    for(i=0;i<sizeof(S)-1;i++) //sizeof para tamaño de la cadena. -1 por el fin de cadena
    {
        printf("\nEl valor de S[%d]= %c\n",i,S[i]); //accediendo a cada valor de la cadena
    }
    return 0;
}
