#include<stdio.h>
#include<stdlib.h>

long serieFib( long x );


int main()
{
   long fib;
   long x;
   int i;
   printf("Hola, haremos una pequeña serie de Fibonacci de forma recursiva \n\n");

   for(i=0;i<100;i++){
    printf(" %d",serieFib(i));
   }

   printf("Hasta luego");
   return 0;

}


long serieFib( long x )
{

   if (x == 0 || x == 1) {
      return x;
   }
   else {
      return serieFib(x - 1) + serieFib(x - 2);
   }

}
