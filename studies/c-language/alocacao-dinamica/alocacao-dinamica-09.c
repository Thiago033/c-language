#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char sobrenome[25];
    int anoNascimento;
};

typedef struct aluno aluno;

int main(int argc, char const *argv[]) {

    aluno *ptrAluno;

    ptrAluno = malloc(sizeof(aluno) * 1);

    if ( !ptrAluno ) printf("ERRO!\nMemoria indisponivel.\n");

    int resp, nAlunos = 1, i = 0;

    do {
        printf("Digite a matricula do aluno %d:\n", nAlunos);
        scanf("%d", &ptrAluno[i].matricula);

        printf("Digite o sobrenome do aluno %d:\n", nAlunos);
        scanf("%s", ptrAluno[i].sobrenome);

        printf("Digite o ano de nascimento do aluno %d:\n", nAlunos);
        scanf("%d", &ptrAluno[i].anoNascimento);

        printf("Adicionar mais um aluno? | SAIR [0]\n");
        scanf("%d", &resp);

        if (resp != 0) {
            nAlunos++;
            ptrAluno = realloc(ptrAluno, sizeof(aluno) * nAlunos);
        }

        i++;

    } while (resp != 0);

    //Printa todos os alunos registrados na struct
    for (int i = 0; i < nAlunos; i++) {
        printf("Aluno %d\n", i+1);
        printf("Matricula %d\n", ptrAluno[i].matricula);
        printf("Sobrenome %s\n", ptrAluno[i].sobrenome);
        printf("Ano de nascimento %d\n", ptrAluno[i].anoNascimento);
        printf("\n");
    }   

    free(ptrAluno);

    return 0;
}