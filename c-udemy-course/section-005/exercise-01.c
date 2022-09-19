#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int sumArray(int *arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

double arrayAverage(int *arr, int size) {
    int sumOfArray = sumArray(arr, size);
    
    double arrayAverage = sumOfArray / size;

    return arrayAverage;

}

int main(int argc, char const *argv[]) {
    int grades[SIZE] = {80,90,72,92};

    double avarage = arrayAverage(grades, SIZE);

    printf("%.2f", avarage);

    return 0;

}