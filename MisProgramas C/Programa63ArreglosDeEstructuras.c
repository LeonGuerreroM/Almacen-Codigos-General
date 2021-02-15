#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Una estructura por definicion ya iene un apuntador en su nombre
#define MAX 2

struct persona
{
    char nombre[40];
    unsigned short edad;
    float estatura;
    float peso;
};

int main()
{
    int i;
    struct persona pacientes_nutriologia[MAX];
    struct persona *apuntador,*auxiliar;

    apuntador=pacientes_nutriologia;
    auxiliar=apuntador;

    for(i=0;i<MAX;i++,apuntador++)
    {
        printf("\n\nNombre: ");
        fflush(stdin);
        gets(apuntador->nombre); //esto es para cadenas de caracteres. Ya reconoce espacios
        printf("\nSu edad es: ");
        scanf("%i",&apuntador->edad);
        printf("\nSu estatura es: ");
        scanf("%f",&apuntador->estatura);
        printf("\nSu peso es: ");
        scanf("%f",&apuntador->peso);
    }
    apuntador=auxiliar;
    for(i=0;i<MAX;i++,apuntador++)
    {
        printf("\n\nEl nombre es: %s",apuntador->nombre);
        printf("\nLa edad es: %i",apuntador->edad);
        printf("\nLa estatura es: %.2f",apuntador->estatura);
        printf("\nEl peso es: %.1f\n",apuntador->peso);
    }
    return 0;
}
