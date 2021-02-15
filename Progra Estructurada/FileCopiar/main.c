#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Origen[20];
    char Destino[20];

    FILE *po;
    FILE *pd;

    printf("Ingresa el nombre del archivo origen\n");
    scanf("%s",Origen);
    printf("Ingresa el nombre del archivo destino\n");
    scanf("%s",Destino);

    po=fopen(Origen,"rt");
    pd=fopen(Destino,"wt");
    if((po==NULL)||(pd==NULL)){
        printf("No se puede realizar la copia");
        return 1;
    }

    int c;

    while((c=getc(po))!=EOF){
        putc(c,pd);
    }

    fclose(po);//se cierran para asegurar que el bud¿ffer de escritura se metio completo en el archivo
    fclose(pd);

    return 0;
}
