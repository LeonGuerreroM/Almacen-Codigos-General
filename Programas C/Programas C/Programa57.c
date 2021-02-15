#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *pa,b;
    pa=NULL;

    if(pa==NULL)
    {
        printf("\n\nEl apuntador es nulo");
    }
    pa=&b;
    if(pa!=NULL)
    {
        printf("\n\nEl apuntador ya no es nulo y tiene la direccion: %p\n\n",pa);
    }
    return 0;
}
