#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

int suma(int *array);
long mult(int *array);
float promedio(int *array);
float de(int *array);
int compara (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(){
    printf("Bienvenido. Realizaremos operaciones con los numeros de un arreglo\n\n\n");
    printf("Primero, llene el arreglo \n\n\n");
    int numeros[10];
    int i;
    for(i=0;i<10;i++){
        printf("Introduce la posicion %d\n\n",i);
        scanf("%d",&numeros[i]);
    }
    printf("Genial, procedamos... \n\n");
    Sleep(3000);
    int a=suma(numeros);
    int suma = 0;
    for(i=0;i<10;i++){
        suma += numeros[i];
    }
    long b;
    b=mult(numeros);
    float c=promedio(numeros);
    float d=de(numeros);
    printf("El resultado de la suma es: %d\n\n",a);
    printf("El resultado de la multiplicacion es: %ld\n\n",b);
    printf("El promedio es: %.2f\n\n",c);
    printf("La desviacion estandart es: %.2f\n\n",d);
    qsort(numeros, 10, sizeof(int), compara);
    printf("El valor mayor es: %d\n\n",numeros[9]);
    printf("El valor menor es: %d\n\n",numeros[0]);
    printf("Hasta Luego");
    return 0;
    }

int suma(int *array){
    int j;
    int suma = 0; //SIEMPRE AL UTILIZAR UNA VARIABLE DE TOTAL DEBES INICIALIZARLA EN 0
    for(j=0;j<10;j++){
        suma += array[j];
    }
    return suma;
}

long mult(int *array){
    int i;
    long multiplicacion = 0;
    for(i=0;i<10;i++){
        multiplicacion *= array[i];
    }
    return multiplicacion;
}

float promedio(int *array){
    int j;
    float suma = 0; //SIEMPRE TRATA D EHACER LAS OPERACIONES CON PURAS VARIABLES DEL TIPO DE DATO QUE QUIERES RETORNAR PORQUE PODRIA HABER CONVERSIONES DE VARIABLES
    for(j=0;j<10;j++){
        suma += array[j];
    }
    float promedio = (suma/10);
    return promedio;
}

float de(int *array){
    int j;
    int i;
    int suma; //
    int aux;
    for(j=0;j<10;j++){
        suma += array[j];
    }
    int promedio = (suma/10);
    for (i=0;i>10;i++){
        aux += (array[i]-promedio)^2;
    }
    int aux2=(aux/10);
    float des=(sqrt(aux2));
    return des;
}
