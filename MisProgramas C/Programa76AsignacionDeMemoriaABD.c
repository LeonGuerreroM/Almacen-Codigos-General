#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct persona //typedef redefine un tipo de dato con el nombre que quiera. en lugar de declarar enteros con int, los puedo declarar con numerito
{
    char *nombre;
    int edad;
    char *direccion;
}PERSONA; //toda esa estructura se llama como lo que estadespues de los parentesis

typedef struct alumno
{
    PERSONA p; //como herencia en java. Porque das el tipo de dato que en si ya es una estructura
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
    ALUMNO *apuntador_alumno; //lo mismo pero con un apuntador
    PROFESOR *apuntador_profesor;
    char *descripcion;
    short n_dias;
    short n_alumnos;
};

char* asignar_memoria_cadena(void); //no mandas nad apero si regresa un apuntador a algo
PERSONA* asignar_memoria_persona(void);
PROFESOR* asignar_memoria_profesor(void);
ALUMNO* asignar_memoria_alumnos(short n);


int main()
{
    struct curso CursoC;
    int i;
    printf("\nDescripcion del Curso de C: ");
    CursoC.descripcion/*accede a la descripcion en la estructura*/=asignar_memoria_cadena(); //mando a llamar una funcion, que refresa un char y ademas la descripcion es char
    printf("\nDias del Curso de C: ");
    scanf("%d%*c"/*este tipo de scan con doble % y * permite convivir con gets*/,&CursoC.n_dias); //guarda directamente algo en una estructura
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
    cadena=(char*)malloc((strlen(auxiliar)+1)*sizeof(char)); //malloc regresa null si no hay memoria suficiente
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
    auxiliar=(PROFESOR*/*para*/)malloc(sizeof(PROFESOR)); //cuento
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
