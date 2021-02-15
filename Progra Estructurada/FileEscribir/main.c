#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE *pf;

    if((pf=fopen("Salida.txt","wt"))==NULL)
    {
        printf("Error al abrir el archivo :""v\n");
        return 1;
    }
    while((c=getchar())!=EOF){
        putc(c,pf);
    }
    fclose(pf);
    return 0;
}
