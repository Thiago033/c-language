#include <stdio.h>

int main(int argc, char const *argv[]) {    

    int arrayInt[5] = {1,2,3,4,5};
    double arrayDouble[5] = {1.1,2.2,3.3,4.4,5.5};
    
    int *ptrInt = arrayInt;
    double *ptrDouble = arrayDouble;

    printf("arrayInt size: %d\n", sizeof(arrayInt));
    printf("arrayDouble size: %d\n", sizeof(arrayDouble));

    printf("prtInt size: %d\n", sizeof(ptrInt));
    printf("prtDouble size: %d\n", sizeof(ptrDouble));

    return 0;
}