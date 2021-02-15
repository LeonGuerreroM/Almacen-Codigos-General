#include<math.h>


void Calcular(int a, int b, int c){

    double x1, x2;
    //ALCANCE DE VARIABLES
    //vars locales que solo existen mientras trabaje la funcion, pues cuando lo mando al main se queda el valor pero ya no estan referenciadas a una direccion de memoria
    double x1i, x2i;
    int d;
    d=pow(b,2)-(4*a*c);
    if(d>=0){
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        x1i=0;
        x2i=0;
    }else{
        x1=x2=(-b/(2*a));
        x1i=sqrt(fabs(d))/(2*a);
        x2i=-sqrt(fabs(d))/(2*a);
    }

    printf("x1=%lf %+lf i/n",x1,x1i);
    printf("x2=%lf %+lf i/n",x2,x2i);


}

