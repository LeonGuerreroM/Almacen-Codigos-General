#include<stdio.h>

int main(){
//recuerda que para cada una de lñas peracions con arreglos es un for
int a[4][4] = {0};
int b[4][4] = {0};
int c[4][4] = {0};
int i, j, k;
for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		scanf("%d",&a[i][j]);
	}
	
}

for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		printf("%d  ",a[i][j]);
	}
}

for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		scanf("%d",&b[i][j]);
	}
	
}

for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		printf("%d  ",b[i][j]);
	}
}

for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		c[i][j]=a[i][j]+b[i][j];
	}	
}

for(i=0;i<4;i++){
	printf("\n");
	for(j=0;j<4;j++){
		printf("%d  ",c[i][j]);
	}
}




	
return 0;	
}

