#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_PROCESOS 3  //Declaramos un macro

int I=0;

//declaramos funciones
void codigo_procesoHijo(int id_proceso);

int main(){
   int _phijos=0;
   int arr_procesos[NUM_PROCESOS]={1,2,3};
   int pid;
   int salida;

//Creacion de hijos
   for(_phijos=0; _phijos< NUM_PROCESOS; _phijos++){
      pid = fork();  //Creamos los hijos
       //Verificamos si realiza correctamente la creacion de hijos
       if(pid == -1){
           perror("Error al crear un proceso: ");
           exit(-1); //Se sale si no realizo correctamente la creacion
	}
   //si no hubo problemas al crear los hijos

       else if(pid==0){
           //es lo que va a realizar cada hijo
           codigo_procesoHijo(arr_procesos[_phijos]);
      }
   }

//lo que va a realizar el padre
	int  _pPadre=0;
	for(_pPadre = 0; _pPadre < NUM_PROCESOS; _pPadre++){
     //el proceso Padre va a esperar a que termine sus hijos
       		 pid = wait(&salida);
    	printf("El proceso hijo %d ha termindo, PID= %d \n", pid,getpid());
        printf("El wait es %d su direccion es: %p \n", salida, &salida);
	}

}

void codigo_procesoHijo(int id_proceso){
     int i;

     for(i=0; i< 5; i++){
        printf("PID = %d Proceso %d: i = %d, I= %d\n",getpid(), id_proceso, i, I++);
}
        // que ya termnino
        exit(id_proceso);


}
        //el hijo va a llamar a exit, para notificarle al padre
