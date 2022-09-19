#include <stdio.h>

int main(int argc, char const *argv[]) {    

    int a = 5;

    void *ptr = &a;

    printf("%d", *(int *)ptr);
    
    return 0;
}