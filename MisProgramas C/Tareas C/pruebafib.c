#include <stdio.h>

long fibonacci( long n ); /* prototipo de la funciÃ³n */

/* la funciÃ³n main comienza la ejecuciÃ³n del programa */
int main()
{
   long resultado; /* valor fibonacci */
   long numero;    /* numero a introducir por el usuario */

   /* obtiene un entero del usuario */
   printf( "Introduzca un entero: " );
   scanf( "%ld", &numero);

   /* calcula el valor fibonacci del nÃºmero introducido por el usuario */
   resultado = fibonacci( numero );

   /* despliega el resultado */
   printf( "Fibonacci( %ld ) = %ldn", numero, resultado );

   return 0; /* indica terminaciÃ³n exitosa */

} /* fin de main */

/* definiciÃ³n de la funciÃ³n recursiva fibonacci */
long fibonacci( long n )
{
   /* caso base */
   if ( n == 0 || n == 1 ) {
      return n;
   } /* fin de if */
   else { /* paso recursivo */
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } /* fin de else */

} /* fin de la funciÃ³n fibonacci */
