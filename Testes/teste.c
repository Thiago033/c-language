#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *nomes;

    nomes = (char*)malloc(sizeof(char));

    printf("%d\n", strlen(nomes));


    //(strlen(nomes) + strlen(nomeAdicionar)) * sizeof(char) + 2

    return 0;
}