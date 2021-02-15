#include<stdio.h>
#include<stdlib.h>


struct complejo{
    int numero;
    int coef;

};
int suma1(int x, int y);
int suma2(int a, int b);
int resta1(int x, int y);
int resta2(int a, int b);
int multi1(int x, int y);
int multi2(int x, int y, int a, int b);

int main(){
    struct complejo z1;
    struct complejo z2;
    int s1;
    int s2;
    int r1, r2, m1, m2;
    printf("Bienvenido. Este programa es para hacer operaciones (suma, resta y multiplicacion) con numeros complejos\n\n\n");
    printf("LLene lo que se pide a continuacion\n\n\n");
    printf("Z1:\n\n");
    printf("La parte numerica\n");
    scanf("%d",&z1.numero);
    printf("EL coeficiente de la parte imaginaria\n");
    scanf("%d",&z1.coef);
    printf("\nZ2\n\n");
    printf("La parte numerica\n");
    scanf("%d",&z2.numero);
    printf("EL coeficiente de la parte imaginaria\n");
    scanf("%d",&z2.coef);
    printf("\n\n\nSus numeros imaginarios son\n\n");
    printf("\nZ1: %d %di",z1.numero, z1.coef); //se puede mandar como parametro el dato de una estructura con name.dato sin problema
    printf("\nZ2: %d %di",z2.numero, z2.coef);
    s1=suma1(z1.numero, z2.numero);
    s2=suma2(z1.coef, z2.coef);
    printf("\n\nEL resultado de la suma es: %d %di",s1, s2);
    r1=resta1(z1.numero, z2.numero);
    r2=resta2(z1.coef, z2.coef);
    printf("\n\nEL resultado de la resta es: %d %di",r1, r2);
    m1=multi1(z1.numero, z2.numero);
    m2=multi2(z1.numero, z1.coef, z2.numero, z2.coef);
    printf("\n\nEL resultado de la multoplicacion es: %d %di",m1, m2);
    printf("\nHasta Luego");
    return 0;
}
int suma1(int x, int y){
int rr;
rr=x+y;
return rr;
}

int suma2(int a, int b){
int ri;
ri=a+b;
return ri;
}

int resta1(int x, int y){
int rr;
rr=x-y;
return rr;
}

int resta2(int a, int b){
int ri;
ri=a-b;
return ri;
}

int multi1(int x, int y){
int rr;
rr=x*y;
return rr;
}

int multi2(int x, int y, int a, int b){
int ri;
ri=(y*a)+(y*b)+(x*b);
return ri;
}
