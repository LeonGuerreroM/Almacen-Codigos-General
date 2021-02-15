#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE *fp;

    if((fp=fopen("salida.txt","rt"))==NULL)
    {
        printf("Error al abrir el archivo :""v\n");
        return -1;
    }
    while((c=getc(fp))!=EOF){
        printf("%c",c);
    }
    fclose(fp);
    return 0;
}
