#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = (int *) calloc(50,4); //50 inteiros, cada inteiro tem 4 bytes
    char *c = (char *) calloc(200,1); //200 char, cada char tem 1 bytes

    //Com sizeof
    int *v = (int *) calloc(50,sizeof(int)); //50 inteiros, cada inteiro tem sizeof(int) = 4 bytes
    char *c = (char *) calloc(200,sizeof(char)); //200 char, cada char tem sizeof(char) = 1 byte
    


    int *p;

    p = (int *) calloc(5, sizeof(int));

    if (p == NULL)
    {
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Digite p[%d]: \n", i);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("p[%d]: %d\n", i, p[i]);
    }
    
    free(p);

    return 0;
} 