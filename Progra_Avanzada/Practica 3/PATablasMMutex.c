#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>


pthread_mutex_t gate1;
pthread_mutex_t gate2;
pthread_mutex_t gate3;
pthread_mutex_t gate4;
pthread_mutex_t gate5;
pthread_mutex_t gate6;
pthread_mutex_t gate7;
pthread_mutex_t gate8;
pthread_mutex_t gate9;
pthread_mutex_t gate10;

void* tabla1(void *parametros);
void* tabla2(void *parametros);
void* tabla3(void *parametros);
void* tabla4(void *parametros);
void* tabla5(void *parametros);
void* tabla6(void *parametros);
void* tabla7(void *parametros);
void* tabla8(void *parametros);
void* tabla9(void *parametros);
void* tabla10(void *parametros);


int main(){
  system("clear");
  pthread_t i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
  pthread_mutex_init(&gate1,NULL);
  pthread_mutex_init(&gate2,NULL);
  pthread_mutex_init(&gate3,NULL);
  pthread_mutex_init(&gate4,NULL);
  pthread_mutex_init(&gate5,NULL);
  pthread_mutex_init(&gate6,NULL);
  pthread_mutex_init(&gate7,NULL);
  pthread_mutex_init(&gate8,NULL);
  pthread_mutex_init(&gate9,NULL);
  pthread_mutex_init(&gate10,NULL);

  pthread_mutex_lock(&gate1);

  pthread_create(&i1,NULL,tabla1,NULL);
  pthread_create(&i2,NULL,tabla2,NULL);
  pthread_create(&i3,NULL,tabla3,NULL);
  pthread_create(&i4,NULL,tabla4,NULL);
  pthread_create(&i5,NULL,tabla5,NULL);
  pthread_create(&i6,NULL,tabla6,NULL);
  pthread_create(&i7,NULL,tabla7,NULL);
  pthread_create(&i8,NULL,tabla8,NULL);
  pthread_create(&i9,NULL,tabla9,NULL);
  pthread_create(&i10,NULL,tabla10,NULL);

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

  pthread_mutex_destroy(&gate1);
  pthread_mutex_destroy(&gate2);
  pthread_mutex_destroy(&gate3);
  pthread_mutex_destroy(&gate4);
  pthread_mutex_destroy(&gate5);
  pthread_mutex_destroy(&gate6);
  pthread_mutex_destroy(&gate7);
  pthread_mutex_destroy(&gate8);
  pthread_mutex_destroy(&gate9);
  pthread_mutex_destroy(&gate10);
  return 0;
}


void* tabla1(void *parametros){
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx1=%d, ",i+1,(i+1)*1);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla2(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx2=%d, ",i+1,(i+1)*2);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla3(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx3=%d, ",i+1,(i+1)*3);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla4(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx4=%d, ",i+1,(i+1)*4);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla5(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx5=%d, ",i+1,(i+1)*5);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla6(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx6=%d, ",i+1,(i+1)*6);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla7(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx7=%d, ",i+1,(i+1)*7);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla8(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate9);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx8=%d, ",i+1,(i+1)*8);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate10);
  pthread_exit(0);
}

void* tabla9(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate10);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx9=%d, ",i+1,(i+1)*9);
  }
  printf("\n");
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate8);
  pthread_exit(0);
}

void* tabla10(void *parametros){
  pthread_mutex_lock(&gate1);
  pthread_mutex_lock(&gate2);
  pthread_mutex_lock(&gate3);
  pthread_mutex_lock(&gate4);
  pthread_mutex_lock(&gate5);
  pthread_mutex_lock(&gate6);
  pthread_mutex_lock(&gate7);
  pthread_mutex_lock(&gate8);
  pthread_mutex_lock(&gate9);
  int i=0;
  for(i=0;i<10;i++){
    printf("%dx10=%d,",i+1,(i+1)*10);
  }
  printf("\n");
  pthread_exit(0);
  pthread_mutex_unlock(&gate1);
  pthread_mutex_unlock(&gate2);
  pthread_mutex_unlock(&gate3);
  pthread_mutex_unlock(&gate4);
  pthread_mutex_unlock(&gate5);
  pthread_mutex_unlock(&gate6);
  pthread_mutex_unlock(&gate7);
  pthread_mutex_unlock(&gate8);
  pthread_mutex_unlock(&gate9);
  pthread_mutex_unlock(&gate10);
}
