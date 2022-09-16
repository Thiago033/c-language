#include <stdio.h>

int main(int argc, char const *argv[]) {    

    int grades[3] = {80,90,100};

    int *gradesPtr = grades;

    printf("grades start at: %p\n", gradesPtr);
    printf("grades start at: %p\n", gradesPtr+1);

    return 0;
}