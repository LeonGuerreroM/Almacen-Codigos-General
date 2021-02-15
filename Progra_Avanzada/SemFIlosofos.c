#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

#define N 5               //num. de filosofos
#define IZQ (i-1)%N      //vecino izquierdo de i
#define DER (i+1)%N      //vecino derecho de i
#define PENSANDO 0
#define CON_HAMBRE 1
#define COME 2

pthread_t filos[N];       //hilos que representan a los filósofos
sem_t mutex ;             //semáforo para la sección crítica
sem_t s[N];               //semáforos para los filósofos
int estado [N] ;          //estado actual de cada filósosfo

//El semaforo mutex solamente se ocupa antes de modificar si un filosofo esta comiendo
//El semaforo para los filosofos solo se libera si el filosofo esta comiendo. De otra manera, se bloquea
void pensar (int i) //metodo para que el filosofo vaya a pensar
{
  int t ;
  t = rand() % 11;
  printf("Filosofo %d pensando \n", i) ;
  estado[i] = PENSANDO; //cambia su estado
  sleep (t) ;
}

void comer (int i) //metodo para que el filosofo coma
{
  printf("Filósofo %d esta comiendo \n", i);
  estado[i] = COME; //modifica su estado
  sleep (5);
}


void verifica(int i) //metodo que valida que pueda tomar ambos tenedores pues los filosofos de a lado bo estan usandolos
//ademas, si es posible, los  toma y come
{
  if( estado[i]==CON_HAMBRE && estado[IZQ]!=COME && estado[DER]!=COME ){
    estado[i] = COME; //el filosofo come
    printf("Filósofo %d comiendo\n", i) ;
    sem_post(&s[i]); //sale de la seccion critica y libera el semaforo
  }
}

void toma_tndrs(int i) //metodo para que el filosofo tome los tenedores
{
  sem_wait(&mutex);             //entra a la sección crítica, hace uso del semaforo (o lo bloquea)
  estado[i] = CON_HAMBRE;      //al filosofo le da hambre y cambia su estado
  verifica(i);                 //verifica que pueda tomar los tenedores
  sem_post(&mutex);            //sale de la sección crítica y el semaforo puede permitir la entrada a alguien más
  sem_wait(&s[i]);            //se bloquea si no consiguió los tenedores
}

void deja_tndrs(int i) //metodo para dejar de comer
{
  sem_wait(&mutex);       //de nuevo entra a la sección critica
  estado[i] = PENSANDO;  //deja de comer y se pone a pensar
  verifica(IZQ);
  verifica(DER);
  sem_post(&mutex);
}

void* filosofos (int i) //ciclo del filosofo
{
  int j ;
  for (; ; )
    {
      pensar(i) ;
      toma_tndrs(i) ;
      comer(i) ;
      deja_tndrs(i) ;
    }
}

int main()
{
  int i ;
  for(i = 0; i < 5; i++){
    sem_init (&s[i], 0, 1);
    estado[i] = PENSANDO ;
  }
  sem_init (&mutex, 0, 1);
  //creamos un hilo de ejecucion para cada filosofo, que ejecuta filosofos()
  for (i=0; i<N; i++)
    pthread_create(&filos[i], NULL, (void*) filosofos,NULL);
  //cada hilo espera a que terminen los demás y libera los recursos
  for (i=0; i<N; i++){
    pthread_join(filos[i],NULL);
  }
}

