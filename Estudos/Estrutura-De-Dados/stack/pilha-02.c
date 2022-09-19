#include <stdio.h>

const int MAX = 10;

struct Aluno
{
    int ra;
    char nome[50];
};

struct Pilha
{
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
};

bool PUSH(){

}

bool POP(){

}

void Listar(Pilha *pilha){
    while (!Empty(pilha)) {
        Aluno aluno;
        POP(pilha, &aluno);
        printf("%i - %s", aluno->ra, aluno->nome);
    }
}


int main() {


    return 0;
}