#include <stdio.h>

struct facil {
    int num;
    char ch;
};

int main() {
    
    struct facil fac,   //variavel para struct facil.
                 *pfac; // variavel ponteiro struct facil.


    pfac = &fac;

    //Se usa ( ) entre a variavel ponteiro "pfac" porque ele precisa primeiro ser deferenciado
    //para depois o operador ".num" ser usado

    (*pfac).num = 32; // o membro "num" da "struct facil" apontada por "pfac"
    (*pfac).ch = 'a'; // o membro "char" da "struct facil" apontada por "pfac"

    //----------------------------------------------------------------------------------------

    //Acesso a membros de estrutura via ponteiro: O operador ->
    pfac->num = 32; // o mesmo que (*pfac).num = 32;
    pfac->ch = 'a'; // o mesmo que (*pfac).ch = ’A’;

    


    return 0;
}