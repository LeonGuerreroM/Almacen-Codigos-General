#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *pa, b, i;
    int a[]={1,2,3,4,5,6,7,8,9,10};

    pa=&a[6];
    b=*pa;
    *pa=400;

    printf("\n\nEl valor de a[6]= %d\n",a[6]);
    printf("\n\nEl valor de &a[6]= %d\n",&a[6]);
    printf("\n\nEl valor de pa= %d\n",pa);
    printf("\n\nEl valor de pa= %p en hexadecimal\n",pa);
    printf("\n\nEl valor de b= %d\n",b);
    printf("\n\nEl valor de *pa= %d\n",*pa);

    return 0;
}
