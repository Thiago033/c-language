#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p;

    p = (int *) malloc(5 * sizeof(int));

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