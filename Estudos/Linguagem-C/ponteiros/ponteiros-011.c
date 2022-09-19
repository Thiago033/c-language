#include <stdio.h>

int main() {
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("%d", y);
    printf("%d", *p);
    printf("%d", x);

    return 0;
}