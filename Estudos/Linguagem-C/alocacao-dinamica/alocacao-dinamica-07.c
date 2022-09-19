#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define Y 5
#define X 5

int main() {
    int **A;
    int i, j;

    A = (int **)malloc(Y * sizeof(int *));

    for (i = 0; i < Y; i++) {
        A[i] = (int *)malloc(X * sizeof(int));
    }

    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            A[i][j] = i + j;
        }
    }

    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            printf("%d \t", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < Y; i++) {
        free(A[i]);
    }

    free(A);

    return 0;
}