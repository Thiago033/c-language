#include <stdio.h>
#include <string.h>
#include <string.h>
#include <math.h>

int soma(int num);

int main() {
    int num;

    printf("Digite um numero para calcular a soma:\n");
    scanf("%d", &num);

    printf("%d", soma(num));

    return 0;
}

int soma(int num) {
    if(num == 0) return 0;

    return num += soma(num - 1);
}