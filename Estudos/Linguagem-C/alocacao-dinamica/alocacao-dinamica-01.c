#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[30], *memchar;
int *memint, i;

int main() {
    memchar = malloc (sizeof(buf));

    if (memchar == NULL) {
        printf ("Erro em alocacao de memoria\n");
        exit (1);
    }
    else {
        memcpy (memchar, buf, sizeof(buf));
    }

    memint = (int *) calloc (1, sizeof(int));

    if (memint == NULL) {
        printf ("Erro em alocacao de inteiros\n");
        exit (1);
    } else {
        i = 0;

        do {
            scanf("%d", memint + i);
            if (memint[i]) {
                memint = (int *) realloc (memint, (i + 2) * sizeof(int));
            
                if (memint == NULL)
                    break;
            }
        } while (memint[i++]);
    }

    return 0;
}