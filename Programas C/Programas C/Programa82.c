#include<stdlib.h>
#include<stdio.h>

int leer(double x[5]);
void desplegar(double m);

int main()
{
    double nums[5];
    double promedio=0;
    char prueba[100];
    int j,i;
    j=leer(nums);
    if(j==1)
    {
        for(i=0; i<3;i++)
            {
                promedio= promedio + nums[i];
            }
            promedio = promedio/5;
            desplegar(promedio);
    }
    return 0;
}

int leer(double x[5])
{
    FILE *archivo;
    char m[100];
    char *c;
    int j=0,i=0;
    if((archivo = fopen("Archivo_V8.txt", "r"))== NULL)
    {
        printf("El archivo no existe\n");
        return 0;
    }
    else
    {
        for(i=0;i<3;i++)
        {
            c = fgets(m, 100, archivo);
            x[j]=atof(m);
            printf("\n%lf", x[j]);
            j++;
        }
        fclose(archivo);
        return 1;
    }
}
void desplegar(double m)
{
    printf("\nEl promedio de los numeros es: %lf",m);
}
