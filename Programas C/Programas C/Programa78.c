#include <stdio.h>
#include <stdlib.h>

int main()
{
      FILE *archivo;
      int i,regr;
      archivo=fopen("Archivo_V2.txt","w");
      for(i=0;i<5;i++)
      {
          printf("\n\t\tNumero a guardar: %d",i);
          fprintf(archivo,"%d\t",i);
      }
      fclose(archivo);
      archivo=fopen("Archivo_V2.txt","r");
      fscanf(archivo,"%d",&regr);
      while(!feof(archivo))
      {
                 printf("\n\t\tNumero guardado: %d",regr);
                 fscanf(archivo,"%d",&regr);
      }
      fclose(archivo);
      return 0;
}
