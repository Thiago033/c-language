#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int *numbers = (int*)malloc(3 * sizeof(int));
    int *newNumbers = NULL;

    if (!numbers) return 1;

    numbers[0] = 30;
    numbers[1] = 20;
    numbers[2] = 10;

    newNumbers = (int*)myRealloc(numbers, sizeof(int) * 3, sizeof(int) * 4);

    return 0;
}

void* myRealloc(void *scrblock, unsigned oldsize, unsigned newsize){
    int i;
    int smallSize;
    if (oldsize < newsize) {
        smallSize = oldsize;
    } else {
        smallSize = newsize;
    }
    
    char *resultArr = (char*)malloc(newsize);

    if(!resultArr) return NULL;

    for (int i = 0; i < smallSize; i++) {   
        resultArr[i] = ((char*)scrblock)[i];
    }
    
    free(scrblock);
    
    return resultArr; 
}