#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, c;
    for(i=1, j=10; j<20; i++, j+=3){
            c=i+j;
        printf("El valor de c es %d\n\n\n",c);
    }
    system("pause");
    return 0;

}
