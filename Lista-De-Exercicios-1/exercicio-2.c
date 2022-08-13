#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **nomes;
    nomes = malloc(1 * sizeof(char *));
    int opcao;

    char buffer[100];
    int length = 0;
    int i = 1;
    int j = 0;
    int indiceRemover;

    do {
        printf("Digite uma opcao: \n");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        if (opcao == 1) {

            nomes = realloc(nomes, i * sizeof(char *));

            printf("Digite um nome: \n");
            fgets(buffer, 100, stdin);

            length = strlen(buffer);
            buffer[length-1] = '\0';

            nomes[j] = malloc(length * sizeof(char));

            strcpy(nomes[j], buffer);

            i++;
            j++;

        } else if (opcao == 2) { 
            for (int i = 0; i < j; i++) {
                printf("nomes[%d] = %s \n", i , nomes[i]);
            }

        } else if (opcao == 3) { 
            printf("Digite o indice do nome a ser removido: \n");
            scanf("%d", &indiceRemover);
            
            for (int i = indiceRemover; i < j-1; ++i) {
                nomes[i] = nomes[i+1];
            }
            
            nomes = realloc(nomes, (j-1)*sizeof(char));

            j--;

        } else if (opcao == 0) {
            printf("Saindo do programa!");
            
        } else {
            printf("Opcao invalida!");

        }
    } while (opcao != 0);

    return 0;
}