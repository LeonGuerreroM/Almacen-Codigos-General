#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct persona
{
    char *nombre;
    int edad;
    char *direccion;
}PERSONA;

typedef struct alumno
{
    PERSONA p;
    char *carrera;
    short nivel;
}ALUMNO;

typedef struct profesor
{
    PERSONA p;
    short clave;
}PROFESOR;

struct curso
{
    ALUMNO *apuntador_alumno;
    PROFESOR *apuntador_profesor;
    char *descripcion;
    short n_dias;
    short n_alumnos;
};

char* asignar_memoria_cadena(void);
PERSONA* asignar_memoria_persona(void);
PROFESOR* asignar_memoria_profesor(void);
ALUMNO* asignar_memoria_alumnos(short n);


int main()
{
    struct curso CursoC;
    int i;
    printf("\nDescripcion del Curso de C: ");
    CursoC.descripcion=asignar_memoria_cadena();
    printf("\nDias del Curso de C: ");
    scanf("%d%*c",&CursoC.n_dias);
    printf("\nDatos del profesor del Curso de C\n");
    CursoC.apuntador_profesor=asignar_memoria_profesor();
    printf("\nNumero de alumnos del Curso de C: ");
    scanf("%d%*c",&CursoC.n_alumnos);
    CursoC.apuntador_alumno=asignar_memoria_alumnos(CursoC.n_alumnos);
    printf("\n\n\nLos datos que fueron introducidos son\n\n");
    printf("\nLa descripcion es: %s\n",CursoC.descripcion);
    printf("\nProfesor del curso %s\n",CursoC.apuntador_profesor->p.nombre);
    printf("\n\n\nAsistentes al curso\n\n");
    for(i=0;i<CursoC.n_alumnos;i++)
    {
        printf("\t\t%s\n",(CursoC.apuntador_alumno+i)->p.nombre);
    }
    return 0;
}

char* asignar_memoria_cadena(void)
{
    char auxiliar[200];
    char *cadena;
    gets(auxiliar);
    cadena=(char*)malloc((strlen(auxiliar)+1)*sizeof(char));
    if(cadena==NULL)
    {
        puts("\nError en la asignación de memoria\n");
        exit(-1);
    }
    strcpy(cadena,auxiliar);
    return cadena;
}

PROFESOR* asignar_memoria_profesor(void)
{
    PROFESOR *auxiliar;
    auxiliar=(PROFESOR*)malloc(sizeof(PROFESOR));
    auxiliar->p=*asignar_memoria_persona();
    printf("\nClave del profesor: ");
    scanf("%d%*c",&auxiliar->clave);
    return auxiliar;
}

PERSONA* asignar_memoria_persona(void)
{
    PERSONA *auxiliar;
    auxiliar=(PERSONA*)malloc(sizeof(PERSONA));
    printf("\nNombre: ");
    auxiliar->nombre=asignar_memoria_cadena();
    printf("\nEdad: ");
    scanf("%d%*c",&auxiliar->edad);
    printf("\nDireccion: ");
    auxiliar->direccion=asignar_memoria_cadena();
    return auxiliar;
}

ALUMNO* asignar_memoria_alumnos(short n)
{
    int i;
    ALUMNO* auxiliar;
    auxiliar=(ALUMNO*)calloc(n,sizeof(ALUMNO));
    if(auxiliar==NULL)
    {
        puts("\nError en la asignación de memoria\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        (auxiliar+i)->p=*asignar_memoria_persona();
        printf("\nCarrera a la que pertenece: ");
        (auxiliar+i)->carrera=asignar_memoria_cadena();
        printf("\nNivel que curso: ");
        scanf("%d%*c",&(auxiliar+i)->nivel);
    }
    return auxiliar;
}
