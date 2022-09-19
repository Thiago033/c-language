#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genericSwap(void *num1, void *num2, int size){
    //size - specifies the number of bytes
    void* tempMemory = malloc(size);

    //Memory copy function
    //void * memcpy(void *dest, void *src, size_t num)

    memcpy(tempMemory, num1, size);
    memcpy(num1, num2, size);
    memcpy(num2, tempMemory, size);
}

int main(int argc, char const *argv[]) {

    int num1 = 1, num2 = 2, size;
    printf("Before: num1: %d, num2: %d\n", num1, num2);

    genericSwap(&num1, &num2, sizeof(int));

    printf("After: num1: %d, num2: %d\n", num1, num2);
    return 0;
}