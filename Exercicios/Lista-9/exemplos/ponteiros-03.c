/*
    ======================================
    |   CODIGO SOMENTE PARA EXPLICACAO   |
    |       ELE NAO IRA COMPILAR         |
    ======================================
*/

#include <stdio.h>

int main() {
    /*
        Explicacao:

        considerando um vetor de inteiro de 3 posicoes:
        int vetor[3];

                                 elementos do vetor: | vetor[0] | vetor[1] | vetor[2]
        enderecos de memoria dos elementos no vetor: |   1000   |   1001   |  1002

            a variavel ponteiro "pvetor" recebe o endereco do primeiro elemento no vetor
            pvetor += 2
            1000 += 2  (1002)
                      vetor[2]
        
        ao adicionar 2 ao ponteiro do vetor (pvetor), ficamos com endereco 1002, que aponta para o terceiro elemento do vetor, no endereco de memoria 1002.

    */

    int num[20], *pnum, diff;

    char str[30], *pstr, *pnome, nome[20];

    //vetor nao precisa do operador de endereco "&"
    //Cada variavel de ponteiro recebe o endereco do PRIMEIRO elemento do vetor
    pnum = num;
    pstr = str;
    pnome = nome;

    pnum += 3;  //pnum = &num[3]
    //nesse caso, a variavel ponteiro "pnum" vai para o endereco de memoria apontado e substitui o valor encontrado nesse endereco por 10
    *pnum = 10; //num[3] = 10


    pstr++;     //pstr = str[1]
    
    diff = pstr - pnum; //INCORRETO: Os ponteiros apontam para tipos diferentes
                        // diff e pnum = INT , pstr = CHAR

    diff = pstr - pnome; /* CORRETO: mas o valor não tem
                      * necessáriamente o sentido de "numero
                      *      de bytes entre pn e pstr".
                      */

    
    //pnome recebe o endereco do primeiro elemento de str
    pnome = str;

    //pstr recebe o endereco do elemento de posicao 30 no vetor
    pstr = &str[30];

    /*
        diff recebe a diferenca entre pstr e pnome

        Ex:
            diff = pstr - pnome;
            diff = 1030 - 1000 <- endereco dos elementos no vetor
            diff = 30
    */
    diff = pstr - pnome; // diff = 30

    //------------------------------------------------------------------------------

    char nome[20], *pnome;
    int val[10],*pval;

    pnome = nome; //Equivalente a pstr = &nome[0]
    pval = val; //Equivalente a ptr = &val[0]

    pnome = nome + 4; //Equivalente a pstr = &nome[4]
    pval = val + 5; //Equivalente a ptr = &val[5]

    /* pstr = nome++;    ATENCAO: INCORRETO !!!
                        //"nome" NÃO É UM PONTEIRO

                        nome++, mesma coisa que: nome = nome + 1
    */

   //-------------------------------------------------------------------------------

   int val[10], x, *pval;

    pval = val; //Equivalente a pval = &val[0]

    *(pval + 3) = 7; // val[3] = 7
    pval[3] = 10;    // val[3] = 10
                     // Equivalente a *(pval + 3) = 10

    //Suponto que o ponteiro esteja no endereco 1000
    //Ponteiro vai passar para o valor 1004
    pval += 4;

    //ponteiro que esta em 1004 vai receber mais 3 e ira para o endereco 1007

    //pval[3] eh a mesma coisa que *(pval + 3)
    //                             *(1004 + 3)

    pval[3] = 20; //ATENCAO: val[7] = 20

    return 0;
}