#include <stdio.h>
#include <stdlib.h>
//En la esttructura las riecciones de las variables estan juntas. En la union estan en la misma posicion
//Se usa union porque aunque haya muchas variabkles no se usan todas al mismo tiempo
//conversiones numericas con funciones
// t texto b binario
struct registro
{
    int  folio;
}regw,regr; //variables de estructura

int main()
{
      FILE *archivo; //tipo file
      size_t bytesreg = sizeof(struct registro);
      char reg_folio[10];
      int i;

      archivo=fopen("Archivo.txt","w"); //con w se crea al archivo, si ya esta lo sobreescribe
      //fopen abrir de diferentes formas
      for(i=0;i<5;i++)
      {
          printf("\n\t\tIntroduce el folio de articulos: ");
          gets(reg_folio);
          regw.folio=atoi(reg_folio);
          fwrite(&regw,bytesreg,1,archivo); //de donde tomo la info, tamaño, cuentos elementos, donde grabar
      }
      fclose(archivo); //cierro archivo
      archivo=fopen("Archivo.txt","r"); //lo abro
      fread(&regr,bytesreg,1,archivo); //para leer. Lee lo primero y luego avanza en el cursor
      while(!feof(archivo)) //feof fin de archivo
      {
          printf("\n\t\tEl folio de articulo es : %d",regr.folio);
          fread(&regr,bytesreg,1,archivo); //sin ++ porque solito aumenta a la proxima posicion
      }
      fclose(archivo);
      return 0;
}
