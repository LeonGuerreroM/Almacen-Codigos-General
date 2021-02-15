#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pr;
    FILE *ps;
    char primero[20];
    char segundo[20];
    char a, b;
    char c,d;
    int contador=1;

    printf("Ingresa el nombre del primer archivo\n");
    scanf("%s",primero);
    printf("Ingresa el nombre del segundo archivo\n");
    scanf("%s",segundo);

	pr = fopen(primero,"rt");
    ps = fopen(segundo,"rt");

    if((pr==NULL)||(ps==NULL)){
        printf("Los archivos no pueden compararse");
        return 1;
    }

	    while ((((c=getc(pr))!=EOF) && ((d=getc(ps))!=EOF))||(((c=getc(pr))!=EOF) || ((d=getc(ps))!=EOF)))
	    {
            if (c!=d)
            {
                printf("%d %c %c\n",contador,c,d);
                contador++;
            }
	    }

    fclose(pr);//se cierran para asegurar que el bud¿ffer de escritura se metio completo en el archivo
    fclose(ps);

    return 0;
}
