// CARREGAR PERSONAGEM
void carregarPersonagem(personagem *jogador, item *inventario)
{
	FILE *fp;
	item *p = inventario;
	item *item_lido;
	int i, qnt_teste, id_teste;
	char nome[100];

	printf("Digite o nome do personagem: ");
	scanf("%s", nome);
	strcat(nome, ".txt");
	if ((fp = fopen(nome, "r")) == NULL)
	{
		system("clear");
		printf("Nao foi possivel encontrar este personagem.\n\n");
		jogador->valido = 0;
	}
	else
	{

		fscanf(fp, "%s", jogador->nome);
		fscanf(fp, "%d", &jogador->forca);
		fscanf(fp, "%d", &jogador->destreza);
		fscanf(fp, "%d", &jogador->vitalidade);
		fscanf(fp, "%d", &jogador->inteligencia);
		fscanf(fp, "%d", &jogador->vida);
		fscanf(fp, "%d", &jogador->mana);
		fscanf(fp, "%d", &jogador->classe);
		fscanf(fp, "%d", &jogador->progresso);
		fscanf(fp, "%d", &jogador->capacete_eq.item_id);
		fscanf(fp, "%d", &jogador->armadura_eq.item_id);
		fscanf(fp, "%d", &jogador->escudo_eq.item_id);
		fscanf(fp, "%d", &jogador->arma_eq.item_id);

		for (i = 0; i < N_ITENS; i++)
		{
			if (todos_itens[i]->item_id == jogador->capacete_eq.item_id)
			{
				jogador->capacete_eq = *todos_itens[i];
			}
			if (todos_itens[i]->item_id == jogador->armadura_eq.item_id)
			{
				jogador->armadura_eq = *todos_itens[i];
			}
			if (todos_itens[i]->item_id == jogador->escudo_eq.item_id)
			{
				jogador->escudo_eq = *todos_itens[i];
			}
			if (todos_itens[i]->item_id == jogador->arma_eq.item_id)
			{
				jogador->arma_eq = *todos_itens[i];
			}
		}

		while (((fscanf(fp, "%d", &id_teste)) != EOF) && ((fscanf(fp, "%d", &qnt_teste)) != EOF))
		{
			item_lido = (item *)malloc(sizeof(item));
			for (i = 0; i < N_ITENS; i++)
			{
				if (todos_itens[i]->item_id == id_teste)
				{
					item_lido->stats = *todos_itens[i];
					break;
				}
			}

			item_lido->stats.item_id = id_teste;
			item_lido->quantidade = qnt_teste;

			item_lido->proximo = NULL;
			p->proximo = item_lido;

			p = p->proximo;
		}

		jogador->mana_max = 5 + (jogador->inteligencia * 5);
		jogador->vida_max = 10 + (jogador->vitalidade * 10);
		jogador->valido = 1;

		system("clear");
		printf("Personagem carregado.\n");
	}
	return;
}

// SALVAR PERSONAGEM
void salvar(personagem *jogador, item *inventario)
{
	if (jogador->valido)
	{
		item *p = inventario;
		FILE *fp;
		char nome[100];
		strcpy(nome, jogador->nome);
		strcat(nome, ".txt");
		fp = fopen(nome, "w");

		fprintf(fp, "%s ", jogador->nome);
		fprintf(fp, "%d ", jogador->forca);
		fprintf(fp, "%d ", jogador->destreza);
		fprintf(fp, "%d ", jogador->vitalidade);
		fprintf(fp, "%d ", jogador->inteligencia);
		fprintf(fp, "%d ", jogador->vida);
		fprintf(fp, "%d ", jogador->mana);
		fprintf(fp, "%d ", jogador->classe);
		fprintf(fp, "%d ", jogador->progresso);
		fprintf(fp, "%d ", jogador->capacete_eq.item_id);
		fprintf(fp, "%d ", jogador->armadura_eq.item_id);
		fprintf(fp, "%d ", jogador->escudo_eq.item_id);
		fprintf(fp, "%d\n", jogador->arma_eq.item_id);

		while (p->proximo != NULL)
		{
			p = p->proximo;
			fprintf(fp, "%d %d ", p->stats.item_id, p->quantidade);
		}

		printf("Personagem salvo. \n\n");
	}
	else
	{
		system("clear");
		printf("Nao ha jogador valido para salvar.\n\n");
	}
	return;
}