#include <stdio.h>

int main() {
    int i = 10;
    int *pNum;
    int **ppNum;

    pNum = &i;

    ppNum = &pNum;

   
    printf("%d\n", i);
    printf("%d\n", *pNum);
    printf("%d\n", **ppNum);

    printf("endereco de ppNum %d\n", ppNum);
    printf("conteudo de ppNum (endereco de pNum) %d\n", *ppNum);
    printf("endereco de pNum %d\n", pNum);

    return 0;
}