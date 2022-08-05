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
#define MAX 80

void Menu();
void AdicionarNome();
void RemoverNome();
void ListarNomes();

int main() {

    int opcao;

    do {

        Menu();
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                printf("1 opcao");
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
    } while (opcao <= 0 || opcao > 4);
    
    return 0;
}

/*
================================================
Menu
 
Imprime o menu para interacao com o usuario
================================================
*/
void Menu() {

    int opcao;

    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Sair\n");
}

/*
================================================
AdicionarNome
 
Funcao para adicionar nomes ao vetor
================================================
*/
void AdicionarNome() {
    //Declara um buffer para efetuar a leitura
    char buffer[MAX];

    gets(buffer);
}