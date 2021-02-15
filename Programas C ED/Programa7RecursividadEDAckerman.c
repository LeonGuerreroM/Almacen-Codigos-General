#include <stdio.h>
#include <stdlib.h>

long ackerman(int a, int b);


int main (){
long res;
int m,n;
scanf("%d",&m);
scanf("%d",&n);
res=ackerman(m,n);
printf("%d",res);

return 0;
}

long ackerman(int a, int b){
	if(a==0 && b>0){
		return b+1;
	}else if(a>0 && b==0){
		return ackerman((a-1),1);
	}else if(a>0 && b>0){
		return ackerman((a-1),ackerman(a,(b-1)));
	}else{
		return 0;
	}
	
}
