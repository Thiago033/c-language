#include <stdio.h>
#include <string.h>
#include <string.h>
#include <math.h>

int fatorial(int fat);

int main() {
    int num;

    printf("Digite um numero para calcular o fatorial:\n");
    scanf("%d", &num);

    printf("%d", fatorial(num));

    return 0;
}

int fatorial(int fat) {
    if(fat == 0) return 1;

    return fat *= fatorial(fat - 1);
}