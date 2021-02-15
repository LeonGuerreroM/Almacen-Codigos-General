#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

//@autor leonm;
pthread_mutex_t tipoA;
pthread_mutex_t tipoB;
//pthread_cond_t exc;
//pthread_cond_t exc2;
int recursoA=0;
int recursoB=0;
int exceso=0;

void* h1(void *parametros);
void* h2(void *parametros);
void* h3(void *parametros);

int main(){
  system("clear");
  pthread_t i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30;
  pthread_mutex_init(&tipoA,NULL);
  pthread_mutex_init(&tipoB,NULL);
  //pthread_cond_init(&exc,NULL);
  //pthread_cond_init(&exc2,NULL);

  pthread_create(&i1,NULL,h1,NULL);
  pthread_create(&i2,NULL,h1,NULL);
  pthread_create(&i3,NULL,h1,NULL);
  pthread_create(&i4,NULL,h1,NULL);
  pthread_create(&i5,NULL,h1,NULL);
  pthread_create(&i6,NULL,h1,NULL);
  pthread_create(&i7,NULL,h1,NULL);
  pthread_create(&i8,NULL,h1,NULL);
  pthread_create(&i9,NULL,h1,NULL);
  pthread_create(&i10,NULL,h1,NULL);
  pthread_create(&i11,NULL,h2,NULL);
  pthread_create(&i12,NULL,h2,NULL);
  pthread_create(&i13,NULL,h2,NULL);
  pthread_create(&i14,NULL,h2,NULL);
  pthread_create(&i15,NULL,h2,NULL);
  pthread_create(&i16,NULL,h2,NULL);
  pthread_create(&i17,NULL,h2,NULL);
  pthread_create(&i18,NULL,h2,NULL);
  pthread_create(&i19,NULL,h2,NULL);
  pthread_create(&i20,NULL,h2,NULL);
  pthread_create(&i21,NULL,h3,NULL);
  pthread_create(&i22,NULL,h3,NULL);
  pthread_create(&i23,NULL,h3,NULL);
  pthread_create(&i24,NULL,h3,NULL);
  pthread_create(&i25,NULL,h3,NULL);
  pthread_create(&i26,NULL,h3,NULL);
  pthread_create(&i27,NULL,h3,NULL);
  pthread_create(&i28,NULL,h3,NULL);
  pthread_create(&i29,NULL,h3,NULL);
  pthread_create(&i30,NULL,h3,NULL);

  pthread_join(i1,NULL);
  pthread_join(i2,NULL);
  pthread_join(i3,NULL);
  pthread_join(i4,NULL);
  pthread_join(i5,NULL);
  pthread_join(i6,NULL);
  pthread_join(i7,NULL);
  pthread_join(i8,NULL);
  pthread_join(i9,NULL);
  pthread_join(i10,NULL);
  pthread_join(i11,NULL);
  pthread_join(i12,NULL);
  pthread_join(i13,NULL);
  pthread_join(i14,NULL);
  pthread_join(i15,NULL);
  pthread_join(i16,NULL);
  pthread_join(i17,NULL);
  pthread_join(i18,NULL);
  pthread_join(i19,NULL);
  pthread_join(i20,NULL);
  pthread_join(i21,NULL);
  pthread_join(i22,NULL);
  pthread_join(i23,NULL);
  pthread_join(i24,NULL);
  pthread_join(i25,NULL);
  pthread_join(i26,NULL);
  pthread_join(i27,NULL);
  pthread_join(i28,NULL);
  pthread_join(i29,NULL);
  pthread_join(i30,NULL);

  pthread_mutex_destroy(&tipoA);
  pthread_mutex_destroy(&tipoB);
  //pthread_cond_destroy(&exc);
  //pthread_cond_destroy(&exc2);

}

void* h1(void *parametros){
  while(1){
    if(exceso<100){
      pthread_mutex_lock(&tipoA);
      printf("Tipo 1, accede al recurso A=%d\n",recursoA);
      recursoA++;
      pthread_mutex_unlock(&tipoA);
      exceso++;
    }else{
      //pthread_cond_wait(&exc,&tipoA);
      //pthread_cond_signal(&exc2);
      exceso=0;
    }
  }
}

void* h2(void *parametros){
  while(1){
    if(exceso<100){
      pthread_mutex_lock(&tipoB);
      printf("Tipo 2, accede al recurso B=%d\n",recursoB);
      recursoB++;
      pthread_mutex_unlock(&tipoB);
      exceso++;
    }else{
      //pthread_cond_wait(&exc2,&tipoB);
      //pthread_cond_signal(&exc);
      exceso=0;
    }
  }
}

void* h3(void *parametros){
  while(1){
    pthread_mutex_lock(&tipoA);
    pthread_mutex_lock(&tipoB);
    printf("Tipo 3, accede al recurso A=%d---B=%d\n",recursoA,recursoB);
    recursoA++;
    recursoB++;
    pthread_mutex_unlock(&tipoA);
    pthread_mutex_unlock(&tipoB);
    //pthread_cond_signal(&exc);
    //pthread_cond_signal(&exc2);
  }
}
