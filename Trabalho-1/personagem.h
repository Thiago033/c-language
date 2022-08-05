#define N_ITENS 15

struct item_stats
{
  int item_id;
  char *nome;
  int defesa;
  int ataque;
};

typedef struct item
{
  struct item_stats stats;

  int quantidade;
  struct item *proximo;
} item;

// 1 a 9 utilizaveis
struct item_stats pocao_vida = {1, "Pocao de vida", 50, 0};
struct item_stats pocao_mana = {2, "Pocao de mana", 50, 0};
// 10 a 19 armas
struct item_stats espada_inicial = {10, "Espada de Cobre", 0, 2};
struct item_stats cajado_inicial = {11, "Cajado Basico", 0, 2};
struct item_stats adaga_inicial = {12, "Adaga de Cobre", 0, 2};
struct item_stats espada_longa = {13, "Espada Longa", 1, 5};
struct item_stats adaga_elfica = {14, "Adaga Elfica", 0, 5};
struct item_stats cajado_ancestral = {15, "Cajado Ancestral", 0, 5};
// 20 a 29 escudos
struct item_stats escudo_incial = {20, "Escudo de madeira", 3, 0};
struct item_stats escudo_aco = {21, "Escudo de Aco", 5, 0};
// 30 a 39 armaduras
struct item_stats armadura_incial = {30, "Camisa de pano", 1, 0};
struct item_stats cota_malha = {31, "Cota de Malha", 3, 0};
struct item_stats armadura_real = {32, "Armadura Real", 5, 0};
// 40 a 49
struct item_stats capacete_inicial = {40, "Chapeu comum", 1, 0};
struct item_stats capacete_aco = {41, "Capacete de Aco", 3, 0};

struct item_stats *todos_itens[N_ITENS] = {&pocao_vida, &pocao_mana, &capacete_inicial, &escudo_incial, &espada_inicial, &armadura_incial, &espada_longa, &adaga_elfica, &cajado_ancestral, &escudo_aco,
                                           &cota_malha, &armadura_real, &capacete_aco, &adaga_inicial, &cajado_inicial};

typedef struct personagem
{
  char nome[100];
  int classe; // 1 - Guerreiro, 2 - Mago, 3 - Ladino
  int vida_max;
  int vida;
  int mana_max;
  int mana;

  int defesa;
  int forca;
  int destreza;
  int vitalidade;
  int inteligencia;

  struct item_stats capacete_eq;
  struct item_stats armadura_eq;
  struct item_stats arma_eq;
  struct item_stats escudo_eq;

  int progresso;
  int valido;
} personagem;

void criarPersonagem(personagem *jogador);
item *inicializa(personagem *jogador);
void adicionar_item(item *PH, struct item_stats item_adicionado);
void imprime_inventario(item *PH, personagem *jogador);
void abrir_inventario(item *PH, personagem *jogador);
void random_drop(item *inventario);

void criarPersonagem(personagem *jogador)
{
  int pontosDisponiveis = 10;
  int pontosTeste = 10;
  int escolha, classe_escolhida = 0;

  jogador->forca = 0;
  jogador->destreza = 0;
  jogador->vitalidade = 0;
  jogador->inteligencia = 0;

  printf("Digite o nome do personagem: ");
  scanf("%s[^\n]", jogador->nome);

  while (!classe_escolhida)
  {
    printf("1 - Guerreiro, 2 - Mago, 3 - Ladino\n");
    printf("Escolha sua classe: ");
    scanf("%d", &jogador->classe);
    if (jogador->classe == 1)
    {
      jogador->vitalidade += 3;
      jogador->forca += 4;
      jogador->arma_eq = espada_inicial;
      classe_escolhida++;
    }
    else if (jogador->classe == 2)
    {
      jogador->inteligencia += 5;
      jogador->arma_eq = cajado_inicial;
      classe_escolhida++;
    }
    else if (jogador->classe == 3)
    {
      jogador->destreza += 5;
      jogador->arma_eq = adaga_inicial;
      classe_escolhida++;
    }
  }

  while (pontosDisponiveis > 0)
  {
    printf("Distribua %d pontos entre seus 4 atributos\n\n", pontosDisponiveis);

    printf("Pontos em forca: ");
    scanf("%d[^\n]", &escolha);
    pontosTeste -= escolha;
    if (pontosTeste < 0)
    {
      jogador->forca = pontosDisponiveis;
      pontosDisponiveis = 0;
    }
    else
    {
      pontosDisponiveis -= escolha;
      jogador->forca += escolha;
    }
    printf("\n");

    if (pontosDisponiveis > 0)
    {
      printf("Pontos restantes: %d\n", pontosDisponiveis);
      printf("Pontos em destreza: ");
      scanf("%d[^\n]", &escolha);
      pontosTeste -= escolha;
      if (pontosTeste < 0)
      {
        jogador->destreza = pontosDisponiveis;
        pontosDisponiveis = 0;
      }
      else
      {
        pontosDisponiveis -= escolha;
        jogador->destreza += escolha;
      }
      printf("\n");
    }

    if (pontosDisponiveis > 0)
    {
      printf("Pontos restantes: %d\n", pontosDisponiveis);
      printf("Pontos em vitalidade: ");
      scanf("%d[^\n]", &escolha);
      pontosTeste -= escolha;
      if (pontosTeste < 0)
      {
        jogador->vitalidade = pontosDisponiveis;
        pontosDisponiveis = 0;
      }
      else
      {
        pontosDisponiveis -= escolha;
        jogador->vitalidade += escolha;
      }
      printf("\n");
    }

    if (pontosDisponiveis > 0)
    {
      printf("Pontos restantes: %d\n", pontosDisponiveis);
      printf("Pontos em inteligencia: ");
      scanf("%d[^\n]", &escolha);
      pontosTeste -= escolha;
      if (pontosTeste < 0)
      {
        jogador->inteligencia = pontosDisponiveis;
        pontosDisponiveis = 0;
      }
      else
      {
        pontosDisponiveis -= escolha;
        jogador->inteligencia += escolha;
      }
      printf("\n");
    }

    system("clear");
  }

  jogador->mana_max = 5 + (jogador->inteligencia * 5);
  jogador->vida_max = 10 + (jogador->vitalidade * 10);
  jogador->mana = jogador->mana_max;
  jogador->vida = jogador->vida_max;

  jogador->valido = 1;
  jogador->progresso = 0;

  jogador->capacete_eq = capacete_inicial;
  jogador->armadura_eq = armadura_incial;
  jogador->escudo_eq = escudo_incial;
  jogador->defesa = jogador->arma_eq.defesa + jogador->armadura_eq.defesa + jogador->escudo_eq.defesa + jogador->capacete_eq.defesa;

  system("clear");
  printf("Personagem criado.\n\n");
}

item *inicializa(personagem *jogador)
{
  item *p = (item *)malloc(sizeof(item));
  p->proximo = NULL;
  jogador->valido = 0;
  return p;
}

void adicionar_item(item *PH, struct item_stats item_adicionado)
{
  item *p = PH;
  item *novo_item;

  while (p->proximo != NULL)
  {
    p = p->proximo;
    if (p->stats.item_id == item_adicionado.item_id)
    {
      p->quantidade++;
      return;
    }
  }

  novo_item = (item *)malloc(sizeof(item));
  novo_item->stats = item_adicionado;
  novo_item->proximo = NULL;
  novo_item->quantidade = 1;
  p->proximo = novo_item;
  return;
}

void imprime_inventario(item *PH, personagem *jogador)
{
  item *p = PH;

  system("clear");
  printf("Capacete equipado: %s (%d def)\n", jogador->capacete_eq.nome, jogador->capacete_eq.defesa);
  printf("Armadura equipada: %s (%d def)\n", jogador->armadura_eq.nome, jogador->armadura_eq.defesa);
  printf("Escudo equipado: %s (%d def)\n", jogador->escudo_eq.nome, jogador->escudo_eq.defesa);
  printf("Espada equipada: %s (%d atq)\n", jogador->arma_eq.nome, jogador->arma_eq.ataque);
  int cont = 1;
  while (p->proximo != NULL)
  {
    p = p->proximo;
    printf("%d. (%d) %s \n", cont, p->quantidade, p->stats.nome);
    cont++;
  }
  return;
}

void abrir_inventario(item *PH, personagem *jogador)
{
  item *p = PH;
  item *q;
  int escolha, i;

  imprime_inventario(PH, jogador);

  printf("Digite o indice do item que deseja usar (0 para sair): ");
  scanf("%d", &escolha);
  if (escolha == 0)
  {
    return;
  }
  else
  {
    for (i = 0; i < escolha; i++, q = p, p = p->proximo)
      ;
    if (p == NULL)
    {
      printf("Nao ha item com esse indice");
    }
    else
    {
      if (p->stats.item_id >= 1 && p->stats.item_id <= 9)
      {
        switch (p->stats.item_id)
        {
        case 1:
          printf("Voce bebeu uma pocao de vida\n");
          jogador->vida += 20;
          if (jogador->vida > jogador->vida_max)
            jogador->vida = jogador->vida_max;
          break;
        case 2:
          printf("Voce bebeu uma pocao de mana\n");
          jogador->mana += 15;
          if (jogador->mana > jogador->mana_max)
            jogador->mana = jogador->mana_max;
          break;
        }
      }
      else if (p->stats.item_id >= 10 && p->stats.item_id <= 19)
      {
        adicionar_item(PH, jogador->arma_eq);
        jogador->defesa -= jogador->arma_eq.defesa;

        jogador->arma_eq = p->stats;
        jogador->defesa += jogador->arma_eq.defesa;
      }
      else if (p->stats.item_id >= 20 && p->stats.item_id <= 29)
      {
        adicionar_item(PH, jogador->escudo_eq);
        jogador->defesa -= jogador->escudo_eq.defesa;

        jogador->escudo_eq = p->stats;
        jogador->defesa += jogador->escudo_eq.defesa;
      }
      else if (p->stats.item_id >= 30 && p->stats.item_id <= 39)
      {
        adicionar_item(PH, jogador->armadura_eq);
        jogador->defesa -= jogador->armadura_eq.defesa;

        jogador->armadura_eq = p->stats;
        jogador->defesa += jogador->armadura_eq.defesa;
      }
      else if (p->stats.item_id >= 40 && p->stats.item_id <= 49)
      {
        adicionar_item(PH, jogador->capacete_eq);
        jogador->defesa -= jogador->capacete_eq.defesa;

        jogador->capacete_eq = p->stats;

        jogador->defesa += jogador->capacete_eq.defesa;
      }
      p->quantidade--;
      if (p->quantidade == 0)
      {
        q->proximo = p->proximo;
        free(p);
      }
    }
  }
  return;
}

void random_drop(item *inventario)
{
  int indice_drop = rand() % N_ITENS;

  adicionar_item(inventario, *todos_itens[indice_drop]);

  printf("Voce encontrou um(a) %s\n", todos_itens[indice_drop]->nome);
  _sleep(5);
  return;
}
