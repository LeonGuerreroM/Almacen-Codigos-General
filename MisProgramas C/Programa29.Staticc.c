#include<stdio.h>
#include<stdlib.h>

int funcion();

int main(){
    int i;
    for(i=0;i<2;i++){
        printf("La variable estatica vale %d\n\n\n",funcion());
    }
    return 0;
}

int funcion()
{
    static int i=0; //hace que su valor sea el ultimo que tomo la i
    printf("La variable estatica vale: %d\n\n",i);
    i++;
    return 0;


}
