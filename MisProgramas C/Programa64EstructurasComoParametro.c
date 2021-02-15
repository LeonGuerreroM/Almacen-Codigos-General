#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2

struct persona
{
    char nombre[40];
    unsigned short edad;
    float estatura;
    float peso;
}pacientes_nutriologia[MAX];

void introduce_datos(struct persona *);
void visualiza_datos(struct persona *);

int main()
{
    struct persona *apuntador; //apuntador a toda la estructura

    apuntador=pacientes_nutriologia;

    introduce_datos(apuntador);
    visualiza_datos(apuntador);
    return 0;
}

void introduce_datos(struct persona *apuntador)
{
    int i;
    for(i=0;i<MAX;i++,apuntador++)
    {
        printf("\n\nNombre: ");
        fflush(stdin);
        gets(apuntador->nombre);
        printf("\nSu edad es: ");
        scanf("%i",&apuntador->edad);
        printf("\nSu estatura es: ");
        scanf("%f",&apuntador->estatura);
        printf("\nSu peso es: ");
        scanf("%f",&apuntador->peso);
    }
}
void visualiza_datos(struct persona *apuntador)
{
    int i;
    for(i=0;i<MAX;i++,apuntador++)
    {
        printf("\n\nEl nombre es: %s",apuntador->nombre);
        printf("\nLa edad es: %i",apuntador->edad);
        printf("\nLa estatura es: %.2f",apuntador->estatura);
        printf("\nEl peso es: %.1f\n",apuntador->peso);
    }
}

