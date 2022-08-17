#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void *elements = (void*)malloc(size * sizeof(int));
int main(int argc, char const *argv[])
{
    int *pBuffer;

    char nome[10] = "joao";
    int numero = 4587;

    memcpy(pBuffer, nome, 11);

    for (int i = 0; i < 10; i++)
    {
        printf("%c", pBuffer[i]);
    }
    


    return 0;
}