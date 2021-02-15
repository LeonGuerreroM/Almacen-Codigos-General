#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float introduce_angulo();
float calcula_seno(float A);
float calcula_coseno(float A);

int main()
{
    int opcion;
    float angulo,resultado;
    do
    {
        printf("\n\nMenu de calculadora\n");
        printf("\n[1] Seno: ");
        printf("\n[2] Coseno");
        printf("\n[3] Salir");
        printf("\n\nElige opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                angulo=introduce_angulo();
                resultado=calcula_seno(angulo);
                printf("\n\nEl resultado es: %f",resultado);
                break;
            case 2:
                angulo=introduce_angulo();
                resultado=calcula_coseno(angulo);
                printf("\n\nEl resultado es: %f",resultado);
                break;
            case 3:
                printf("\n\nAdios");
                break;
            default:
                printf("\n\nTe equivocaste de opcion");
        }
    }while(opcion!=3);
    return 0;
}

float introduce_angulo()
{
    float angulo;
    printf("\nIntroduce el angulo (en grados): ");
    scanf("%f",&angulo);
    return angulo;
}

float calcula_seno(float A)
{
    return sin(A*3.14159/180);
}
float calcula_coseno(float A)
{
    return cos(A*3.14159/180);
}
