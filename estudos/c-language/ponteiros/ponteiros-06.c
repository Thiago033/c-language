#define LEN 50

struct endereco {
    char rua[LEN];
    char cidade_estado_cep[LEN];
};

void obtem_endereco(struct endereco *);
void imprime_endereco(struct endereco);

int main(){
    struct endereco residencia;

    printf("Entre seu endereco residencial:\n");
    obtem_endereco(&residencia);

    printf("\nSeu endereco:\n");
    imprime_endereco(residencia);
    
    return 0;
}

/*
============================================================
ObtemEndereco

Pede ao usuario para digitar seu endereco
============================================================
*/
void ObtemEndereco(struct endereco *localizacao) {
    printf("Entre rua: ");
    gets(localizacao->rua);

    printf("Entre cidade/estado/cep: ");
    gets(localizacao->cidade_estado_cep);
}

/*
============================================================
ImprimeEndereco

Printa no terminal o endereco digitado pelo usuario
============================================================
*/
void ImprimeEndereco(struct endereco localizacao) {
    printf("%s\n", localizacao.rua);
    printf("%s\n", localizacao.cidade_estado_cep);
}