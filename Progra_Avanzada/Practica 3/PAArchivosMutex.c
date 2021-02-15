#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t mEscritores, mLectores1,mLectores2,aux;
int escrito=0;//,bandera=0;
FILE *arch;

void apertura();
void* Lector1(void *parametros);
void* Lector2(void *parametros);
void* escritor1(void *parametros);
void* escritor2(void *parametros);

int main(){

  system("clear");

  pthread_t hilo1, hilo2, hilo3, hilo4;
  pthread_mutex_init(&mEscritores,NULL);
  pthread_mutex_init(&mLectores1,NULL);
  pthread_mutex_init(&mLectores2,NULL);
  pthread_mutex_init(&aux,NULL);

  pthread_mutex_lock(&aux);

  apertura();

  pthread_create(&hilo1,NULL,Lector1,NULL);
  pthread_create(&hilo2,NULL,Lector2,NULL);
  pthread_create(&hilo3,NULL,escritor1,NULL);
  pthread_create(&hilo4,NULL,escritor2,NULL);

  pthread_join(hilo1,NULL);
  pthread_join(hilo2,NULL);
  pthread_join(hilo3,NULL);
  pthread_join(hilo4,NULL);

  return 0;
}

void apertura(){
  arch=fopen("LectoresEscritores.txt","wr");
  if(arch!=NULL)
    printf("archivo abierto\n");
  else
    printf("error al abrir el archivo\n");
}

void* Lector1(void *parametros){
  //pthread_mutex_lock(&mLectores1);
  //pthread_mutex_lock(&mEscritores);
  pthread_mutex_lock(&aux);
  printf("dentro de lector1 %d\n",escrito);
  //int cont=0;
  char buffer[5];

  if(escrito==1){
    while(1){
      int i;
      pthread_mutex_lock(&mLectores1);
      pthread_mutex_lock(&mEscritores);

      printf("tratara de leer\n");
      fgets(buffer,5,arch);
      //printf("%s\n",buffer);
      for(i=0;i<5;i++){
        printf("%c",buffer[i]);
      }
      printf("\n");
      printf("trato de leer\n");
      //cont++;
      //if(cont==1){
        pthread_mutex_unlock(&mEscritores);
        pthread_mutex_unlock(&mLectores1);
        //cont=0;
      //}
    }
  }
  pthread_exit(0);
}


void* Lector2(void *parametros){
  //pthread_mutex_lock(&mLectores1);
  //pthread_mutex_lock(&mEscritores);
  pthread_mutex_lock(&aux);
  printf("dentro de lector1 %d\n",escrito);
  //int cont=0;
  char buffer[2];

  if(escrito==1){
    while(1){
      int i;
      pthread_mutex_lock(&mLectores1);
      pthread_mutex_lock(&mEscritores);

      printf("tratara de leer2\n");
      fgets(buffer,2,arch);
      //printf("%s\n",buffer);
      for(i=0;i<2;i++){
        printf("%c",buffer[i]);
      }
      printf("\n");
      printf("trato de leer2\n");
      //cont++;
      //if(cont==1){
        pthread_mutex_unlock(&mEscritores);
        pthread_mutex_unlock(&mLectores1);
        //cont=0;
      //}
    }
  }
  pthread_exit(0);
}




void* escritor1(void *parametros){
  //if(bandera==0){
    //pthread_mutex_lock(&mEscritores);
    //bandera++;
  //}else{
    /*pthread_mutex_lock(&mEscritores);
    pthread_mutex_lock(&mLectores1);
    pthread_mutex_lock(&mLectores2);*/
  //}
  //int cont=0;
  char buffer[]="texto de prueba\n";
  while(1){
    pthread_mutex_lock(&mEscritores);
    pthread_mutex_lock(&mLectores1);
    pthread_mutex_lock(&mLectores2);
    fputs(buffer,arch);
    escrito=1;
    //printf("escriotr1\n");
    //cont++;
    //if(cont==3){
      pthread_mutex_unlock(&mEscritores);
      pthread_mutex_unlock(&aux);
      pthread_mutex_unlock(&mLectores1);
      pthread_mutex_unlock(&mLectores2);
      //cont=0;
    //}
  }
  pthread_exit(0);
}

void* escritor2(void *parametros){
  /*if(bandera==0){
    pthread_mutex_lock(&mEscritores);
    bandera++;
  }else{*/
    /*pthread_mutex_lock(&mEscritores);
    pthread_mutex_lock(&mLectores1);
    pthread_mutex_lock(&mLectores2);*/
  //}*/
  //int cont=0;
  char buffer[]="TEXTO DE PRUEBA\n";
  while(1){
    pthread_mutex_lock(&mEscritores);
    pthread_mutex_lock(&mLectores1);
    pthread_mutex_lock(&mLectores2);
    fputs(buffer,arch);
    escrito=1;
    //printf("texto muy largo para diferenciar\n");
    //cont++;
    //if(cont==3){
      pthread_mutex_unlock(&mEscritores);
      pthread_mutex_unlock(&aux);
      pthread_mutex_unlock(&mLectores1);
      pthread_mutex_unlock(&mLectores2);
      //cont=0;
    //}
  }
  pthread_exit(0);
}
