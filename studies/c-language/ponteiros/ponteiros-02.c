#include <stdio.h>

int main()
{
    int *p1, *p2, x = 5;
    float *p3; 

    p1 = &x;
    p2 = p1;

    //ERRADO:
    //warning: assignment to 'float *' from incompatible pointer type 'int *'
    //p3 = p1;

    //*p2 = *p2 + 2;

    printf("%d\n", *p1);
    printf("%d\n", *p2);

    return 0;
}