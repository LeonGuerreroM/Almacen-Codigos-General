#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct persona
{
    char nombre[30];
    unsigned short edad;
    float estatura;
    float peso;
};

int main()
{
    char nombre_aux[20],apellido_aux[20];
    struct persona *apuntador;
    struct persona *apuntador2;
    struct persona jorge;
    struct persona esteban;
    struct persona rosa;
    struct persona pancha;
    struct persona maria={"Maria Hernandez Lopez",23,1.60,57.2};

    printf("\n\nEl tamaño de la estrutura persona es: %d", sizeof(jorge));

    printf("\n\nEl nombre es: %s",maria.nombre);
    printf("\nLa edad es: %i",maria.edad);
    printf("\nLa estatura es: %.2f",maria.estatura);
    printf("\nEl peso es: %.1f\n",maria.peso);

    strcpy(jorge.nombre,"Jorge Gutierrez");
    jorge.edad=40;
    jorge.estatura=1.67;
    jorge.peso=80.0;

    printf("\n\nEl nombre es: %s",jorge.nombre);
    printf("\nLa edad es: %i",jorge.edad);
    printf("\nLa estatura es: %.2f",jorge.estatura);
    printf("\nEl peso es: %.1f\n",jorge.peso);

    apuntador=&esteban;

    strcpy(apuntador->nombre,"Esteban Fernandez");
    apuntador->edad=16;
    apuntador->estatura=1.80;
    apuntador->peso=65.7;

    printf("\n\nEl nombre es: %s",apuntador->nombre);
    printf("\nLa edad es: %i",apuntador->edad);
    printf("\nLa estatura es: %.2f",apuntador->estatura);
    printf("\nEl peso es: %.1f\n",apuntador->peso);

    printf("\n\nEl nombre completo de rosa es: ");
    scanf("%s",&rosa.nombre);
    //fflush(stdin); para que el teclado no se vicie o llene de caracteres
    printf("\nSu edad es: ");
    scanf("%i",&rosa.edad);
    printf("\nSu estatura es: ");
    scanf("%f",&rosa.estatura);
    printf("\nSu peso es: ");
    scanf("%f",&rosa.peso);

    printf("\n\nEl nombre es: %s",rosa.nombre);
    printf("\nLa edad es: %i",rosa.edad);
    printf("\nLa estatura es: %.2f",rosa.estatura);
    printf("\nEl peso es: %.1f\n",rosa.peso);

    apuntador2=&pancha;
    printf("\n\nEl nombre real de pancha es: ");
    scanf("%s",&nombre_aux);
    printf("\nSu apellido es: ");
    scanf("%s",&apellido_aux);
    strcat(apuntador2->nombre,nombre_aux);
    strcat(apuntador2->nombre," ");
    strcat(apuntador2->nombre,apellido_aux);

    printf("\nSu edad es: ");
    scanf("%i",&apuntador2->edad);
    printf("\nSu estatura es: ");
    scanf("%f",&apuntador2->estatura);
    printf("\nSu peso es: ");
    scanf("%f",&apuntador2->peso);

    printf("\n\nEl nombre es: %s",apuntador2->nombre);
    printf("\nLa edad es: %i",apuntador2->edad);
    printf("\nLa estatura es: %.2f",apuntador2->estatura);
    printf("\nEl peso es: %.1f\n",apuntador2->peso);

    return 0;
}
