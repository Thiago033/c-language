#include <stdio.h>

int main() {
    char *cUFFS = "UFFS";

    printf("%c\n", *cUFFS);
    cUFFS++;

    printf("%c\n", *cUFFS);
    cUFFS += 1;

    printf("%c\n", *cUFFS);
    cUFFS = cUFFS+1;

    printf("%c\n", *cUFFS);
    cUFFS -= 3;

    printf("%c\n", *cUFFS);

    return 0;
}