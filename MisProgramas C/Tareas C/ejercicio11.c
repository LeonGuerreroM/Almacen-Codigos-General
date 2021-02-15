#include<stdio.h>
#include<stdlib.h>

int main()
{
   char nombre[10]="hola.txt";
   char linea[81];
   int i;
   FILE *fichero;

   fichero = fopen( nombre, "r" );
   printf( "Fichero: %s -> ", nombre );
   if( fichero )
      printf( "existe (ABIERTO)\n" );
   else
   {
      printf( "Error (NO ABIERTO)\n" );
      return 1;
   }


   printf( "La primera linea del fichero: %s\n\n", nombre );
   printf( "%s\n", fgets(linea, 81, fichero) );

   rewind( fichero );
   printf("Aqui usamos la funcion rewind para volver al inicio del archivo\n");
   printf("Porque si no, a continuacion se mostrarian los 7 primeros caracteres despues de la primera linea\n");
   printf("Porque ya avanzo hasta ahi, pero lo regresamos y asi\n");
   printf("Nos puede mostrar las primeros 7 caracteres reales\n\n");

   printf( "Los 7 primeros caracteres del fichero: %s\n\n", nombre );
   for( i=1; i<=7; i++) {
   printf( "%c", fgetc(fichero) );
   }

   printf("\n\nSi existiera error, usariamos aqui fputs");
   fputs( "Ejemplo de fputs \'fputs\'\n", fichero ); //Hatsat donde se, solo se usara si existe un error

   printf("\n\nAqui mi fseek me llevara al final del archivo");

   fseek( fichero, 0L, SEEK_END );

   printf( "\n\nPara demostrarlo usare fgetc. Si no estuviera al final, esta funcion me imprimiria en panatalla 2 caracateres: %s\n\n", nombre );
   for( i=1; i<=2; i++) {
   printf( "%c", fgetc(fichero) );
   }
   printf("\n\nNo lo hizo, porque el puntero esta al final y ya no hay mas caracteres\n\n");
   printf("Hastal luego");

   if( !fclose(fichero) )
      printf( "\nFichero cerrado\n" );
   else
   {
      printf( "\nError: fichero NO CERRADO\n" );
      return 1;
   }

   return 0;
}
