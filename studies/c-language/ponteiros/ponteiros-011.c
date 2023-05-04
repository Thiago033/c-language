#include <stdio.h>

int main() {
    int x, y, *p;
    y = 0;
    p = &y; //p = 0
    x = *p; // x = 0
    x = 4;
    (*p)++; // y/p = +1
    --x;
    (*p) += x; // y/p = +x
    y++; // y/p = +1

    printf("%d", y); // 5
    printf("%d", *p); // 5
    printf("%d", x); // 3

    return 0;
}