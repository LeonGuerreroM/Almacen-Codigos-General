#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    int numero;
    printf("\n\nIntroduzca un numero: ");
    scanf("%d",&numero);
    printf("\n");
    while(numero>0)
    {
        printf("%d ...\n\n",numero);
        Sleep(3000);
        numero--;
    }
    printf("\n");
    return 0;
}
