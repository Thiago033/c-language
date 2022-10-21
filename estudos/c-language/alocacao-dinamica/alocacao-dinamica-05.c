#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p = (int *) malloc(sizeof(int));

    int opcao = 0;
    int count = 0;
    int num;
    int ponteiro = 2;

    while (opcao < 15)
    {
        printf("Digite um numero inteiro:\n");
        scanf("%d", &num);

        p[count] = num;
        count++;

        // printf("Digite 1 para adicionar mais um numero.\n");
        // scanf("%d", &opcao);

        p =  (int *) realloc(p,  ponteiro * sizeof(int)); 
        ponteiro++;

        opcao++;
    }

    for (int i = 0; i < 15; i++)
    {
        printf(" numero %d: %d\n", i+1, p[i]);
        printf(" endereco %d:\n", &p[i]);
    }

    return 0;
} 