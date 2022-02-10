//STRUCT DOS MONSTROS
struct monstros
{
  char nome[30];
	int vida;
	int forca;
};

//STRUCT STATUS DOS MONSTROS
struct monstros goblin={"Goblin Vigia", 20, 5};
struct monstros goblin2={"Goblin Acougueiro", 40, 10};
struct monstros goblin3={"Goblin Covarde", 25, 16};
struct monstros lobo={"Lobo", 50, 18};
struct monstros golem={"Golem", 75, 25};

//DECLARAÇÃO DAS FUNÇÕES
void level_up(personagem *jogador);
void GameOver(personagem *jogador);
void limpar_buffer (void);
void comando_invalido(int erro);
int scaninteiro(void);

//BATALHA
void batalha(struct monstros monstro, personagem *jogador, item *inventario)
{
	system("clear");
  
  int dano;
  int dano_monstro;
  int aleatorio;
  int erro;
  int escolha;

  printf("Voce encontra um %s. \n\n", monstro.nome);

	while (monstro.vida > 0)
	{
		do
		{
			comando_invalido(erro);
			erro=0;
			
			printf("Vida do %s: %d\n\n", monstro.nome, monstro.vida);

			printf("Sua vida: %d\n", jogador->vida);
			printf("Sua mana: %d\n\n", jogador->mana);

			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
			printf("|  [1] Ataque                   |\n");
			printf("|  [2] Magia                    |\n");
			printf("|  [3] Usar Item                |\n");
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
			escolha = scaninteiro();

			switch (escolha)
			{
			case 1: //ATAQUE NORMAL
				aleatorio = (rand() % 4)+1; //multiplicador aleatorio de dano
        if(aleatorio==5){
          dano = jogador->forca + (aleatorio * 2)  + jogador->arma_eq.ataque;
        }
        else{
          dano = jogador->forca + aleatorio  + jogador->arma_eq.ataque;
        }
				  monstro.vida -= dano;
        
				if (aleatorio==5) //se o multiplicador aleatorio for o maximo(5);
				{
					printf("Voce causou um dano CRITICO!\n");
				}
				
				printf("Voce causou %d de dano ao %s.\n", dano, monstro.nome);
				break;

			case 2: //ATAQUE MAGICO
				aleatorio = (rand() % 11)+1 - jogador->inteligencia;	//sorteia um numero aleatorio de 1 a 12 - inteligencia do jogador
        if(aleatorio < 0)
        {
          aleatorio = 1;
        }
				jogador->mana -= aleatorio;    //retira de 1 a 12 pontos de mana do jogador
				printf("Voce conjura uma magia gastando %d pontos de mana e ataca %s\n", aleatorio, monstro.nome);

				aleatorio = (rand() % 4)+6;
        dano = (jogador->inteligencia + aleatorio + jogador->arma_eq.ataque) * 2;
				monstro.vida -= dano;

				if (aleatorio==10)
				{
					printf("Voce causou um dano CRITICO!\n");
				}

				printf("O ataque causou %d de dano ao %s.\n\n", dano, monstro.nome);
				sleep(3);
				break;

			case 3: 
        abrir_inventario(inventario, jogador);
				break;

			default:
			  erro=1;
			  break;
			}

		}while(erro==1);

		//############ ATAQUE DO MONSTRO ##############
		if (monstro.vida>0)
		{
			if (jogador->destreza > (rand() % 50) + 1)
			{
				printf("Voce consegue desviar do ataque do %s \n", monstro.nome);
			}
			else
			{
				aleatorio = (rand() % 4)+1; //multiplicador de dano do monstro
        dano_monstro = monstro.forca + aleatorio*2 - ((int)jogador->defesa*0.2);
        if(dano_monstro < 0)
        {
          dano_monstro = 0;
        }
				jogador->vida -= dano_monstro;

				if (aleatorio==5)
				{
					printf("Voce recebe um dano CRITICO!\n");
				}

				printf("O %s te ataca e causa %d de dano!\n", monstro.nome, dano_monstro);

				GameOver(jogador); //verifica se a vida do jogador ainda eh maior que 1
			}
		}
		//############ MONSTRO MORTO ##############
		else
		{
			printf("Voce derrota o %s e avanca. \n", monstro.nome);

			//Funcao para dropar um item/pocao aleatorio ao derrotar um monstro
			random_drop(inventario);
      level_up(jogador);
		}

		sleep(3);
		system("clear");
	}
  return;
}


//FUNCAO PARA MENSAGEM DE GAMEROVER
void GameOver(personagem *jogador)
{
	if (jogador->vida < 1)
	{
		printf("Game Over");
		exit(1);
	}
  return;
}


//ACEITAR SOMENTE INTEIROS
int scaninteiro(void) 
{
	char inteiro[60];

	scanf("%s", inteiro);
    limpar_buffer();

	if(isdigit(inteiro[0]))
    {
      return inteiro[0]-48;
    }
	else
    {
      return 0;
    }
}


//TESTANDO SE O NUMERO EH VALIDO PARA O SWITCH-CASE
void comando_invalido(int erro)
{
    if (erro == 1)
    {
      printf("Comando invalido!!!\n");
		  printf("Tente novamente.\n\n");
      sleep(2);
    }
    return;
}


//LIMPAR BUFFER A CADA SCANF()
void limpar_buffer (void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

// LEVEL UP AO FINAL DE CADA BATALHA
void level_up(personagem *jogador)
{
  int pontosDisponiveisLevelup = 10;
	int pontosTesteLevelup = pontosDisponiveisLevelup;
	int escolhaLevelup;
  int vit_antiga = jogador->vitalidade;
  int int_antiga = jogador->inteligencia;

  while(pontosDisponiveisLevelup > 0)
  {
	printf("Distribua %d pontos entre seus 4 atributos\n", pontosDisponiveisLevelup);
	printf("Pontos em forca: ");
	scanf("%d[^\n]", &escolhaLevelup);
	pontosTesteLevelup -= escolhaLevelup;
	if (pontosTesteLevelup < 0) {
		jogador->forca += pontosDisponiveisLevelup;
		pontosDisponiveisLevelup = 0;
	} else {
		pontosDisponiveisLevelup -= escolhaLevelup;
		jogador->forca += escolhaLevelup;
	}

	printf("Pontos restantes: %d\n", pontosDisponiveisLevelup);
	printf("Pontos em destreza: ");
	scanf("%d[^\n]", &escolhaLevelup);
	pontosTesteLevelup -= escolhaLevelup;
	if (pontosTesteLevelup < 0) {
		jogador->destreza += pontosDisponiveisLevelup;
		pontosDisponiveisLevelup = 0;
	} else {
		pontosDisponiveisLevelup -= escolhaLevelup;
		jogador->destreza += escolhaLevelup;
	}

	printf("Pontos restantes: %d\n", pontosDisponiveisLevelup);
	printf("Pontos em vitalidade: ");
	scanf("%d[^\n]", &escolhaLevelup);
	pontosTesteLevelup -= escolhaLevelup;
	if (pontosTesteLevelup < 0) {
		jogador->vitalidade += pontosDisponiveisLevelup;
		pontosDisponiveisLevelup = 0;
	} else {
		pontosDisponiveisLevelup -= escolhaLevelup;
		jogador->vitalidade += escolhaLevelup;
	}

	printf("Pontos restantes: %d\n", pontosDisponiveisLevelup);
	printf("Pontos em inteligencia: ");
	scanf("%d[^\n]", &escolhaLevelup);
	pontosTesteLevelup -= escolhaLevelup;
	if (pontosTesteLevelup < 0) {
		jogador->inteligencia += pontosDisponiveisLevelup;
		pontosDisponiveisLevelup = 0;
	} else {
		pontosDisponiveisLevelup -= escolhaLevelup;
		jogador->inteligencia += escolhaLevelup;
	}

  }
  jogador->mana_max += 5 + (jogador->inteligencia);
	jogador->vida_max += 10 + (jogador->vitalidade);
  jogador->vida += (jogador->vitalidade - vit_antiga) * 10;
  jogador->mana += (jogador->inteligencia - int_antiga) * 5;
  return;
}