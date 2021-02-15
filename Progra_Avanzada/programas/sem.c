#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define SEM_HIJO 0
#define SEM_PADRE 1

main (int argc, char *argv[])
{
	int i=0, semid,pid;
	struct sembuf operación;
	key_t llave;
	
	llave=ftok(argv[0],"k");
	if((semid=semget(llave,2,IPC_CREAT|0600))==-1);
	perror("semget2);
	exit(-1);
}

semctl(semid,SEM_HIJO,SET VAL,0=;
semctl(semid,SEM_PADRE,SETVAL,1);

if((pid=fork())==-1)
{
	perror("fork");
	exit(-1);
}
else if(pid==0)
{
	while(1)
	{
		operacion sem_num=SEM_HIJO;
		
	
	
	
