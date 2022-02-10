#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    float C,F, K;  
    printf("Escreva a temperatura em graus celsius: ");//conversao de celsius pra kelvin e fahrenheit
    scanf("%f",&C);
    //F = C * 1.8 + 32;//calculo para fahrenheit
    //K = C + 273.15;//calculo para kelvin
    printf("\nDe celsius pra Fahrenheit = %.2f \n", F);
    printf("\nDe celsius pra Kelvin = %.2f \n", K);
}