#include<stdio.h>
#include<stdlib.h>

float suma(float x, float y);
float resta(float x, float y);
float multiplicacion(float x, float y);
float division(float x, float y);

int main()
{
    float x,y;
    float (*funcion[])(float,float)={suma,resta,multiplicacion,division};
    char signo, operadores[]={'+','-','*','/'};
    int i;
    unsigned char t;
    puts("\nCalculadora de operaciones\n");
    do
    {
        printf("\n\nEscribe la operacion: ");
        scanf("%f%c%f",&x,&signo,&y);
        for(i=0;i<4;i++)
        {
            if(signo==operadores[i])
                printf("\n\n%.1f %c %.1f = %.2f",x,signo,y,funcion[i](x,y));
        }
        printf("\n\nQuieres otra operacion: [s/n]: ");
        scanf("%*c%c",&t);
        t=tolower(t);
    }while(t=='s');

    return 0;
}

float suma(float x, float y)
{
    return x+y;
}
float resta(float x, float y)
{
    return x-y;
}
float multiplicacion(float x, float y)
{
    return x*y;
}
float division(float x, float y)
{
    return x/y;
}

