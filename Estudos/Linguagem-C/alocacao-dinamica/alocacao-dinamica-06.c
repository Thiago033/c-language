#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *nomes;

char* alocarMemoria(int tamanho);

int main() {

    char dados[20];
    printf("Digite um nome:\n");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);

    int length = strlen(dados);
    
    nomes[0] = alocarMemoria(length);
    strcpy(nomes[0], dados);
    
    printf("%s", *nomes);

    return 0;
}

/*
==================================================
alocarMemoria

aloca memoria para a palavra no vetor de strings
==================================================
*/
char* alocarMemoria(int tamanho){
    char* info = NULL;

    info = malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }

    return info;
}