#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*int a, b, c;
    double x1, x2, xi1, xi2, d;

    printf("Calculadora de Ecuaciones de segundo grado\n");
    printf("Ingrese los coefiucientes a, b y c\n");

    scanf("%d %d %d",&a,&b,&c); //lo que se ponga entre las %d se debe poner al momento de capturar las variables, como %d; es 5;

    d = (pow(b,2)-(4*(a*c)));


    if(d==0){
        x1=-b/(2*a);
        x2=x1; //o x2=x1=-b/(2*a);

        printf("x1=%.2lf y x2=%.2lf \n",x1,x2);

    }else if(d>=0){
        x1=((-b+(sqrt(d)))/(2*a));
        x2=((-b-(sqrt(d)))/(2*a));

        printf("x1=%.2lf y x2=%.2lf \n",x1,x2);
    }else{
       x2=x1=-b/(2*a); //fabs calcula el valor absoluto de un numero
       xi1=((sqrt(fabs(d)))/(2*a));
       xi2=((sqrt(fabs(d)))/(2*a));
       printf("x1=%.2lf y x2=%+.2lf i\n",x1,xi1); //el mas es para que ponga positivo o negativo
       printf("x2=%.2lf y x2=%+.2lf i\n",x2,xi2);

    } */

    //calculo de factorial de un numero

    int n;
    int f=1;
    //int i;


    printf("Calculo del factorial de un numero \n");
    printf("Ingresa un numero \n");
    scanf("%d",&n);
    int i=n;

    /*for(i=n;i>1;i--){
        f*=i; // o f=f*i
    } */

    //--------------------

    /* while(i>1){
        f=f*i;
        i--;
    } */


    do{

        if(i!=0){

        f=f*i;
        i--;
        }

    }while(i>1);


    printf("El factorial de %d es %d ",n,f);
    return 0;
}
