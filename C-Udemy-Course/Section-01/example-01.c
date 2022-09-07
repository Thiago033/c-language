#include <stdio.h>

int main(int argc, char const *argv[]) {    

    int a = 5;
    int *p;

    p = &a;

    printf("%d\n", a);
    printf("%p\n", &a);

    printf("%d\n", *p);
    printf("%p\n", p);

    printf("%p\n", &p);
    
    *p = 8;

    printf("%d\n", a);

    return 0;
}