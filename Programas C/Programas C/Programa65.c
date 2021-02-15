#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[]="ABCD";
    int i;
    for(i=0;i<sizeof(S)-1;i++)
    {
        printf("\nEl valor de S[%d]= %c\n",i,S[i]);
    }
    return 0;
}
