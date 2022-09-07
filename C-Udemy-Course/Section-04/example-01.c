#include <stdio.h>

int main(int argc, char const *argv[]) {    

    int a = 5, b = 10;

    printf("size = %d\n", sizeof(a + b));
    printf("size = %d\n", sizeof(a)+ sizeof(b));
    printf("size = %d\n", sizeof(char));
    
    printf("size 'a'= %d\n", sizeof('a'));
    printf("size ''a''= %d\n", sizeof("a"));
    

    return 0;
}