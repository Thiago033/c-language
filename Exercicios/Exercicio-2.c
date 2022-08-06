//=======================================================
// Lista 1
// Exercício 2

// Faça um programa que armazena nomes.
// O programa deve armazenar todos os nomes na mesma string
// O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos. Não pode ter desperdício de memória.

// Faça o seguinte menu:
// 1) Adicionar nome
// 2) Remover nome
// 3) Listar
// 4) Sair
//=======================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct Pessoa{
    char* nome;
    int idade;
    int telefone;
}pessoa[MAX];

void Menu();
void AdicionarNome();
void RemoverNome();
void ListarNomes();

char* AlocarMemoria(int tamanho);

int main() {
    int indiceRegistro = 0;
    int opcao;

    do {

        Menu();
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 0:
                printf("saiu");
                break;

            case 1:
                printf("1 opcao");
                AdicionarNome(indiceRegistro++);
                break;

            case 2:
                printf("2 opcao");
                break;
            
            case 3:
                printf("3 opcao");
                break;
            
            case 4:
                printf("4 opcao");
                break;
            
            default:
                printf("Opcao invalida! Tente novamente!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}

/*
================================================
Menu
 
Imprime o menu para interacao com o usuario
================================================
*/
void Menu() {

    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Buscar\n");
    printf("4) Listar\n");
    printf("0) Sair\n");
}

/*
================================================
AdicionarNome
 
Funcao para adicionar nomes ao vetor
================================================
*/
void AdicionarNome(int indiceRegistro) {
    char dado[MAX];

    printf("Digite o nome: \n");
    scanf("%s", dado);
    //X
    setbuf(stdin, NULL);

    pessoa[indiceRegistro].nome = AlocarMemoria(strlen(dado));
    strcpy(pessoa[indiceRegistro].nome, dado);
}

/*
================================================
AlocarMemoria
 
Funcao para alocar corretamente o espaco de memoria para os dados

================================================
*/
char* AlocarMemoria(int tamanho){
    char* dado = NULL;
    dado = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(dado == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }
    return dado;
}