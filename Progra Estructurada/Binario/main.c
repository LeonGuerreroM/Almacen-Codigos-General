#include <stdio.h>
#include <stdlib.h>

struct Ejemplo{
    int Entero;
    double real;
}typedef Ejemplo;

int main()
{
    Ejemplo E1;
    Ejemplo E2;
    E1.Entero=10;
    E2.Entero=10.0;
    FILE *fp;

    if((fp=fopen("Numeros.bin","ab+"))==NULL){
        printf("Error al abrir el archivo");
        return 1;
    }
    fseek(fp,0,SEEK_END); //lleva el apuntador que existe en toda estructura/archivo hasta el ultimo elemento (por el seek_end)
    printf("El tamaño del archivo es %ld bytes",ftell(fp)); //cuantos bytes tiene desde el inicio hasta la posicion actual
    //fread(&E2,sizeof(Ejemplo),1,fp);
    fclose(fp);

    printf("$d %f",E2.Entero,E2.real);
    return 0;

}
