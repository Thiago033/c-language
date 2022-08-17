#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int *pBuffer;

    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int vetor2[10] = {41,42,43,44,45,46,47,48,49,50};

    // printf("%d \n", sizeof(vetor));

    pBuffer = vetor;

    for (int i = 0; i < 10; i++) {
        printf("%d\n", *pBuffer);
        printf("%d\n", pBuffer);
        pBuffer++;
    }

    // pBuffer = vetor2;

    // printf("\n\n");

    // for (int i = 0; i < 10; i++) {
    //     printf("%d", *pBuffer);
    //     pBuffer++;
    // }

    return 0;
}