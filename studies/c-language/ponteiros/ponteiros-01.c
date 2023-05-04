#include <stdio.h>

int main()
{

    int i = 3;

    //"p" é o nome da variável e int * é o tipo de "p" (ponteiro para int).
    int* p;

    p = &i;

    printf("%d \n", i);

    //Vai no endereco de memoria e pega o valor que esta nesse endereco (nesse caso i = 3)
    printf("%d \n", *p);

    //Vai no endereco de memoria onde esta a variavel "i" e adiciona 5 ao seu valor
    *p = *p + 5;

    //i++;

    printf("%d \n", i);
    printf("%d \n", *p);

    return 0;
}