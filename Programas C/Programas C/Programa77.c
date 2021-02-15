#include <stdio.h>
#include <stdlib.h>

struct registro
{
	    int  folio;
}regw,regr;

int main()
{
      FILE *archivo;
      size_t bytesreg = sizeof(struct registro);
      char reg_folio[10];
      int i;

      archivo=fopen("Archivo.txt","w");
      for(i=0;i<5;i++)
      {
          printf("\n\t\tIntroduce el folio de articulos: ");
          gets(reg_folio);
          regw.folio=atoi(reg_folio);
          fwrite(&regw,bytesreg,1,archivo);
      }
      fclose(archivo);
      archivo=fopen("Archivo.txt","r");
      fread(&regr,bytesreg,1,archivo);
      while(!feof(archivo))
      {
          printf("\n\t\tEl folio de articulo es : %d",regr.folio);
          fread(&regr,bytesreg,1,archivo);
      }
      fclose(archivo);
      return 0;
}
