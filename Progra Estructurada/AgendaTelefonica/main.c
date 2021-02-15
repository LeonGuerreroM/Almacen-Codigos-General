#include <stdio.h>
#include <stdlib.h>

struct Agenda{
char telefono[15];
int id;
char nombre[15];
}typedef Agenda;

void Agregar(){
    Agenda A1;
    printf("Ingresa el nombre:\n");
    scanf("%s",A1.nombre);
    printf("Ingresa el telefono:\n");
    scanf("%s",A1.telefono);
    printf("Ingresa el id:\n");
    scanf("%d",&(A1.id));

    FILE *fp;
    if((fp=fopen("Agenda.bin","ab+"))==NULL){
        printf("Error al abrir el programa\n");
    }
    else{
        fwrite(&A1,sizeof(Agenda),1,fp);
        fclose(fp);
    }

}
void Visualizar();
void Modificar();

int main()
{
    int opc;
    do{
        printf("1. Agregar datos\n");
        printf("2. Visualizar Agenda\n");
        printf("3. Modificar Datos\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:Agregar();break;
            case 2:Visualizar();break;
            case 3:Modificar();break;
        }
    }while(opc!=5);




    return 0;
}
void Visualizar(){
    FILE *fp;
    int i;
    if((fp=fopen("Agenda.bin","rb"))==NULL){
        printf("Error al abrir el archivo");
    }else{
        fseek(fp,0,SEEK_END);
        long bytes=ftell(fp);
        int registros=bytes/sizeof(Agenda); //total de bytes entre los bytes de la estructura, me dice los bloques de la estructura, o sea, los registros
        Agenda *A;
        A=(Agenda*)malloc(sizeof(Agenda)*registros);
        fseek(fp,0,SEEK_SET);
        fread(A,sizeof(Agenda),registros,fp); //lectura de todos los registros mediante el espacio de memoria reservado
        for(i=0;i<registros;i++){
            printf("%s %s %d\n",(A+i)->nombre,(A+i)->telefono,(A+i)->id);
        }
    }
}
void Modificar(){ //No se pueden borrar cosas, se borra el archivo y se crea uno nuevo con lo que si debe estar
}
