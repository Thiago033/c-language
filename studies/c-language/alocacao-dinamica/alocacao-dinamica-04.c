#include <stdio.h>
#include <stdlib.h>

int main() {

    
    int *p = (int *) malloc(5 * sizeof(int));

    int *p1 =  (int *) realloc(p, 15 * sizeof(int));

    if (p1 != NULL)
    {
        p = p1;
        free(p1);
    }
    
    return 0;
} 