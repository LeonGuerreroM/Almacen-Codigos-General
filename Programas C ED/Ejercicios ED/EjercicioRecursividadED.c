#include <stdio.h>
#include <stdlib.h>
//int multi(int a, int b);
int fact(int a);

int main (){
int res;
int m,n;
scanf("%d",&m);
//scanf("%d",&n);
//res=multi(m,n);
res=fact(m);
printf("%d",res);

return 0;
}

/*int multi(int a, int b){
	if(a>0 && b>0){
		return a+multi(a,(b-1));
	}else{
		return 0;
	}
	
}*/

int fact(int a){
	if(a>0){
		return a*fact(a-1);
	}else if(a==0){
		return 1;
	}else{
		printf("No valido");
	}
}
