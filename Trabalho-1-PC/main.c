#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "personagem.h"
#include "salvarCarregar.h"
#include "combate.h"

int menu(personagem *jogador);
void jogar(personagem *jogador, item *inventario);
void queda(personagem *jogador);

int main()
{
  personagem jogador;
  item *inventario;
  inventario = inicializa(&jogador);

  system("clear");
  for (;;)
  {
    switch (menu(&jogador))
    {
    case 1:
      criarPersonagem(&jogador);
      break;
    case 2:
      carregarPersonagem(&jogador, inventario);
      break;
    case 3:
      salvar(&jogador, inventario);
      break;
    case 4:
      if (jogador.valido)
      {
        jogar(&jogador, inventario);
      }
      else
      {
        printf("Crie ou carregue um personagem para jogar.\n\n");
      }
      break;
    case 5:
      exit(1);
    default:
      system("clear");
      printf("Comando invalido. tente novamente.\n\n");
    }
  }
  return 0;
}

int menu(personagem *jogador)
{
  int escolha;

  if (jogador->valido)
  {
    printf("      == Personagem Atual == \n");
    printf(" Nome: %s\tCapacete: %s\n", jogador->nome, jogador->capacete_eq.nome);
    printf(" Vida: %d/%d\t\tArmardura: %s\n", jogador->vida, jogador->vida_max, jogador->armadura_eq.nome);
    printf(" Mana: %d/%d\t\tEscudo: %s\n", jogador->mana, jogador->mana_max, jogador->escudo_eq.nome);
    printf(" Forca: %d\t\tArma: %s\n", jogador->forca, jogador->arma_eq.nome);
    printf(" Destreza: %d\n", jogador->destreza);
    printf(" Vitalidade: %d\n", jogador->vitalidade);
    printf(" Inteligencia: %d\n", jogador->inteligencia);
    if (jogador->classe == 1)
      printf(" Classe: Guerreiro\n");
    else if (jogador->classe == 2)
      printf(" Classe: Mago\n");
    else if (jogador->classe == 3)
      printf(" Classe: Ladino\n");
  }
  else
  {
    printf("Nenhum personagem selecionado, crie ou carregue para iniciar o jogo.\n\n");
  }

  printf("  ----- Escolha uma opcao -----\n");
  printf("  1. Criar novo personagem\n");
  printf("  2. Carregar um personagem\n");
  printf("  3. Salvar\n");
  printf("  4. Jogar\n");
  printf("  5. Sair\n\n");

  printf("Escolha: ");
  scanf("%d[^\n]", &escolha);
  system("clear");

  return escolha;
}

void procurou()
{
  printf("Voce ja procurou nesta sala.\n");
  sleep(2);
  return;
}

void jogar(personagem *jogador, item *inventario)
{

  int procura = 0;
  int controle_menu = 0;
  int opcoes_jogo;
  int escolher_final = 0;

  while (escolher_final == 0 && controle_menu == 0)
  {
    switch (jogador->progresso)
    {
      //######### ENTRADA ###########
    case 0:
    {
      system("clear");
      printf("=========Entrada=========\n\n");
      printf("Apos uma longa viagem, voce finalmente chegou a entrada da masmorra.\nSe tudo der certo, ao final, voce conseguira o que veio buscar.");
      printf("\n\nO que se passa pela sua cabeca?");
      printf("\n[1]: Cheguei ate aqui, nao posso voltar agora.\n[2]: Talvez eu nao devesse ter saido de casa. Melhor voltar.\n[3]: Voltar ao menu.\n");

      scanf("%d", &opcoes_jogo);
      // troquei isso por switch case, e deu ruim. N recomendo.
      if (opcoes_jogo == 1)
      {
        jogador->progresso += 1;
        break;
      }
      else if (opcoes_jogo == 2)
      {
        system("clear");
        printf("Apos um momento de consideracao, voce decide comecar a longa jornada de volta para casa.\nA vida de aventureiro realmente nao e para voce.");
        printf("\n====Fim de jogo====\n");
        sleep(3);
        break;
      }
      else if (opcoes_jogo == 3)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }
    // ######### SALA 1 ###########
    case 1:
    {
      system("clear");
      printf("=========Sala em ruinas=========\n");
      printf("Como esperado, e escuro aqui. Voce acende uma tocha, a luz reflete das paredes de tijolos de pedra, iluminando a sala e a entrada de um corredor, que parece se estender ate onde a luz alcanca.");
      printf("\nTalvez 15 metros? Nao da pra ter certeza.");
      printf("\nFora o corredor, a sala mostra claros sinais de abandono. Qualquer mobilia que um dia existiu, ja se tornou poeira ou esta em pedacos. Estranhas manchas marrons adornam o chao, passando uma sensacao de que, o que quer que esteja la dentro, nao e muito amigavel.");
      printf("\nO que voce deseja fazer?");
      printf("\n[1]: Seguir em frente, nao ha nada de interessante nessa sala.\n[2]: Explorar a sala, talvez tenha algo escondido na poeira.\n[3]: Abrir o inventario.\n[4]: Voltar ao menu.\n");
      scanf("%d", &opcoes_jogo);
      if (opcoes_jogo == 1)
      {
        system("clear");
        batalha(goblin, jogador, inventario);
        jogador->progresso += 1;
        procura = 0;
        break;
      }
      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
        }
        else
        {
          procurou();
        }
        break;
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }
    //############## SALA 2 ###############
    case 2:
    {
      system("clear");
      printf("=========Abatedouro=========\n");
      printf("O cheiro de mofo penetra suas narinas conforme voce avanca pelo escuro corredor. Sob a luz da tocha voce percebe rastros recentes no chao empoeirado, provavelmente deixados pela criatura que o atacou quando saia da sala anterior. O corredor faz uma curva a direita, e termina repentinamente em uma antiga porta de madeira, comida por cupins e sem fechadura. Voce empurra a porta, que abre facilmente, com a espada. O som das dobradicas enferrujadas e alto, qualquer coisa na proxima sala certamente o escutou. Com isto em mente voce entra rapidamente, pronto para cortar quem ousar tentar embosca-lo.\nAssim que passa pela porta, o cheiro de mofo da lugar ao cheiro de sangue e carne em decomposicao. Para sua surpresa, nao parece haver ninguem na sala. Nao so isso, mas ela e muito maior e mais bem-cuidada que a sala anterior. Quatro mesas de pedra estao colocadas em duas fileiras, seus tampos manchados com alguma substancia escura. Pequenas e rusticas prateleiras de madeira ficam na metade das paredes, cheias de o que parecem ser pedacos de carne apodrecendo e ossadas de pequenos animais. Facas, serras, e outras ferramentas estao penduradas abaixo das prateleiras, ou espalhadas sobre as mesas. Uma grande bacia de pedra fica no canto da sala, uma canaleta proporciona a drenagem do conteudo da bacia para um barril, do lado da mesma, que parece ser a fonte do cheiro metalico. Alem disso, uma cortina a sua esquerda esconde a entrada de um corredor.");

      printf("O que voce faz?\n[1]: Esse lugar nao me parece bom, seguirei em frente.\n[2]: Talvez eu encontre algo util nas prateleiras.\n[3]: Abrir o inventario\n[4]: Voltar para o menu.\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        printf("De tras da cortina emerge mais uma daquelas criaturas verdes e pequenas, com uma faca em cada mao.");
        sleep(3);
        batalha(goblin2, jogador, inventario);
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }

      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

    // ########### SALA 3 ##########
    case 3:
    {
      system("clear");
      printf("=========Alojamento=========\n");
      printf("Voce usa a cortina para limpar o sangue das suas roupas, antes de atravessar para a proxima sala. Voce tem a impressao de que algo se moveu no canto do seu campo de visao, mas ao olhar, nao ve nada. Cautelosamente, voce caminha entre pilhas de peles e feno jogadas no chao, como que colchoes muito rusticos e improvisados. Claramente, este lugar e algum tipo de dormitorio. Uma segunda cortina leva adiante no lado oposto da sala. E tentador apenas seguir adiante e nao perder mais tempo, mas talvez valha a pena vasculhar um pouco, quem sabe que tipo de tesouro goblins escondem debaixo do colchao.");
      printf("\nO que deseja fazer?\n[1]: Ja perdi muito tempo, preciso seguir em frente.\n[2]: Tesouro nunca e demais, vou procurar um pouco.\n[3]: Abrir inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        printf("Mais um goblin, este estava escondido debaixo de uma pilha de cobertas.");
        sleep(3);
        batalha(goblin3, jogador, inventario);
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();

          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }

      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }
    //############ SALA 4 ##############
    case 4:
    {
      system("clear");
      printf("=========Oficina=========\n");
      printf("A sala seguinte já não é mais construída com tijolos de pedra empilhados. Pelo contrario, parece ter sido escavada na rocha, sendo sustentanda por vigas de madeira apoiando o teto aqui e ali. Uma mesa de madeira, surpreendentemente bem feita, esta encostada na parede a sua direita, sobre a qual voce ve uma variedade de ferramentas, claramente roubadas, a julgar pela qualidade da manufatura. Pedacos de madeira, metal velho e retorcido, pedacos de silex, couro e ossos estão organizados em cestos ao redor da mesa, provavelmente vao servir de materia prima para alguma arma ou ferramenta. A sala nao e muito grande, e outra cortina esconde o caminho em frente. Do outro lado da sala, uma fornalha de barro cheia de carvao, ao lado de um dos grandes tijolos da sala anterior, parecem ser usados para trabalhar com o ferro velho.");
      printf("\nO que deseja fazer?\n[1]: Preciso seguir em frente, antes que mais dessas coisas verdes venham. \n[2]: Talvez tenha algo interessante nesses cestos.\n[3]: Abrir o inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

    //########### SALA 5 ###########
    case 5:
    {
      system("clear");
      printf("=========Cozinha=========\n");
      printf("De todas as salas ate agora, esta e com certeza a mais fedida. Um caldeirao no centro da sala borbulha sobre uma fogueira, exalando vapores que, sinceramente, dao ansia de vomito. Em uma mesa ao lado estao pedacos de carne em decomposicao, cogumelos e ervas. Pedacos de comida e utensilios caidos no chao, bem como a fogueira acesa, sugerem que alguem estava cozinhando recentemente, e correu as pressas. A saida e clara, atraves de um corredor sem cortinas na parede esquerda. No canto oposto da sala, a direita, ha uma gaiola com um porco extremamente gordo e malcuidado, restos de comida em uma tigela na sua frente sugerem que o mesmo serve de lixeira para os goblins.");
      printf("\nO que deseja fazer?\n[1]: Preciso sair daqui o mais rapido possivel, pelo bem do meu nariz.\n[2]: Talvez de pra aproveitar alguma coisa. \n[3]: Abrir o inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

      //############ SALA 6 ############

    case 6:
    {
      printf("=========Canil=========\n");
      printf("Mais uma sala malcheirosa. Esta possui tres jaulas, grandes o suficiente para um animal de medio porte. Todas as jaulas estao vazia no momento, bem como as tigelas colocadas dentro das mesmas. Outra passagem se abre na parede à sua frente, levando a um pequeno corredor.");
      printf("\nO que deseja fazer?\n[1]: Nada pra se ver aqui, vou seguir em frente.\n[2]: Talvez tenham deixado algo pra tras enquanto saiam.\n[3]: Abrir o inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        printf("Escondido nas sombras, um grande lobo salta sobre voce.");
        sleep(3);
        batalha(lobo, jogador, inventario);
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

      //############# SALA 7 ############

    case 7:
    {
      procura = 0;
      system("clear");
      printf("=========Riacho=========\n");
      printf("O corredor abre a sua frente, revelando o que parece ser um pequeno porto, construido na margem de um rio subterraneo que corre da esquerda para a direita. O fato de nao haver nenhum barco no porto sugere que ao menos alguns goblins sairam da toca. Isso explica a escassez dessas criaturas aqui, pois suas tribos normalmente sao muito numerosas. Uma pequena ponte arqueada de madeira permite passagem para o outro lado, onde uma porta, tambem de madeira, marca o lugar para o qual voce deve seguir.");
      printf("\nO que deseja fazer?\n[1]: Seguirei pela ponte, devo estar quase la.\n[2]: Nao custa nada vasculhar um pouco.\n[3]: Abrir o inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        queda(jogador);
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

      //########### SALA 8 ###########

    case 8:
    {
      printf("=========Prisao=========\n");
      printf("Mais uma vez, o cheiro de sangue preenche suas narinas. Atravessando a porta, voce se depara novamente com os tijolos de pedra que viu na entrada. Talvez isso fosse uma antiga base militar ou prisao, pois a sala a sua frente possui quatro celas, duas de cada lado de um corredor central. Apenas uma dessas celas possui um ocupante. Um esqueleto de estatura humana jaz no meio de uma mancha escura no chao. Nao parece haver nada de muito interessante aqui. A melhor opcao e seguir em frente, por mais uma porta.");
      printf("\nO que deseja fazer?\n[1]: Preciso sair daqui antes que os goblins voltem, em frente.\n[2]: Abrir o inventario\n[3]: Voltar ao menu.\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        jogador->progresso += 1;
        break;
      }
      if (opcoes_jogo == 2)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 3)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

    //########### SALA 9 ###########
    case 9:
    {
      printf("=========Quarto do Chefe=========\n");
      printf("Mais uma parte da antiga construcao, remodelada para os propositos dos seus novos ocupantes. As paredes sao cobertas por armarios de metal, a ferrugem nos mesmos sugere que faziam parte da mobilia original do lugar. Os armarios nao possuem portas, e seus interiores estao cheios de ossos, incluindo um cranio humano, peles e armas, dispostos como se fossem trofeus. No centro da sala esta uma caixa grande, cheia de feno, e coberta por peles, incluindo o que parece ser pele de urso. Do outro lado da sala existe outra porta. Voce deve estar chegando perto.");
      printf("\nO que deseja fazer?\n[1]: So mais um pouco, e eu posso voltar pra casa. Em frente!\n[2]: O chefe goblin deve ter algumas coisas valiosas guardadas.\n[3]: Abrir o inventario\n[4]: Voltar ao menu\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        jogador->progresso += 1;
        procura = 0;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        if (procura == 0)
        {
          random_drop(inventario);
          random_drop(inventario);
          procura = 1;
          break;
        }
        else
        {
          procurou();
          break;
        }
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }

      //########### SALA FINAL ###########

    case 10:
    {
      system("clear");
      printf("=======Sala do tesouro=======\n");
      printf("Tenso, preparado para ser esfaqueado a qualquer momento, voce abre a porta. Do outro lado, sob a luz da tocha, voce ve reluzir pilhas e pilhas de ouro. Mais ouro do que voce ja viu na vida. Como esses goblins conseguiram tanto ouro, nao se sabe, mas com uma fracao disso voce ja pode viver uma vida tranquila, sem nunca mais ter que trabalhar. No centro da sala algo chama sua atencao, uma estátua de aproximadamente dois metros de altura, feita de pedra, tem as maos juntas como que em uma oracao e entre seus dedos, pendurado, um amuleto que bate perfeitamente na descricao do artefato que voce veio procurar.");
      printf("\nO que deseja fazer?\n[1]: Pegar o amuleto e sair, os goblins ja devem estar voltando. \n[2]: Além do amuleto, devo ter tempo para pegar um pouco desse ouro.\n[3]: Abrir o inventario\n[4]: Voltar ao menu.\n");

      scanf("%d", &opcoes_jogo);

      if (opcoes_jogo == 1)
      {
        system("clear");
        printf("Voce se aproxima da estatua, que, apesar de imovel, nao deixa de intimidar. Voce puxa o amuleto e guarda em sua mochila, pronto para finalmente deixar este lugar, quando sente o chao tremendo atras de voce. Olhando para tras, o medo enche seu peito quando a estatua, ate entao imovel, desfere um poderoso soco na sua direcao. Voce consegue desviar, mas o golem na sua frente nao parece disposto a lhe deixar ir.\n");
        sleep(7);

        batalha(golem, jogador, inventario);
        escolher_final = 1;
        break;
      }

      if (opcoes_jogo == 2)
      {
        system("clear");
        printf("Voce gasta um certo tempo enchendo a mochila de ouro, puxa o amuleto e guarda em sua mochila, pronto para finalmente deixar este lugar, quando sente o chao tremendo atras de voce. Olhando para tras, o medo enche seu peito quando a estatua, ate entao imovel, desfere um poderoso soco na sua direcao. Voce consegue desviar, mas o golem na sua frente nao parece disposto a lhe deixar ir.\n");
        sleep(7);
        batalha(golem, jogador, inventario);
        escolher_final = 2;
        break;
      }
      if (opcoes_jogo == 3)
      {
        abrir_inventario(inventario, jogador);
        break;
      }
      if (opcoes_jogo == 4)
      {
        controle_menu = 1;
        system("clear");
        break;
      }
      else
      {
        comando_invalido(1);
        break;
      }
    }
    }
  }
  if (escolher_final == 1)
  {
    system("clear");
    printf("Voce destroi o golem, depois de muito esforco. Os goblins ainda nao voltaram. Voce refaz o seu caminho pela masmorra, e imediatamente começa a jornada de volta para casa. La, voce entrega o amuleto e recebe o pagamento prometido. Voce investe esse dinheiro em equipamentos melhores, conhece outros aventureiros, e vive o resto da sua vida trabalhando no ramo. Nao e uma vida ruim, o pagamento e bom, e a adrenalina e constante.");
    printf("\n=========FIM DE JOGO========");
    sleep(15);
    exit(0);
  }
  if (escolher_final == 2)
  {
    system("clear");
    printf("Voce destroi o golem, depois de muito esforco. Porém, nao ha tempo para comemorar, pois o som de muitos passos chega aos seus ouvidos. Os goblins voltaram, e estao no caminho entre voce e a liberdade.\n");
    if (jogador->classe == 1)
    {
      printf("Mas meros goblins nao podem para-lo. Voce acabou de destruir um golem, afinal. Com sua espada em punho, voce avanca pelas ondas de goblins, sem parar. Voce chega ao riacho cansado, e ve nos barcos em que os goblins chegaram, sua saida. Voce pula em um dos barcos, cortando a corda que o prende ao porto, e segue a correnteza rumo a seguranca.");
    }
    if (jogador->classe == 3)
    {
      printf("Nao existe outra saida, so lhe resta correr. Voce avanca mais rapido do que pensava que podia, desviando de flechas e adagas, enquanto goblins inundam os corredores a sua frente. De alguma forma, voce consegue atravessar as fileiras verdes sem grandes ferimentos, e ve no riacho a sua salvacao. Roubando um dos barcos em que os goblins chegaram, voce segue a correnteza rumo a seguranca.");
    }
    if (jogador->classe == 2)
    {
      printf("Mas claro, voce veio preparado. Sair de casa sem meios de voltar rapidamente seria burrice. Abrindo a mochila, voce encontra o pergaminho de teletransporte que guardara justamente para esse tipo de situacao. Voce comeca a recitar, e assim que os primeiros goblins comecam a invadir a sala, voce fecha os olhos e desaparece em um clarao. Ao abri-los novamente, voce esta em sua casa, no circulo de teletransporte que deixara preparado.");
    }
    printf("Estando em casa, voce entrega o amuleto e recebe o pagamento prometido, investe todo o ouro que conseguiu com essa pequena aventura, e vive o resto da vida sem precisar trabalhar, tranquilamente\n");

    printf("=========FIM DE JOGO==========\n");
    sleep(15);
    exit(0);
  }
  return;
}

void queda(personagem *jogador)
{
  if (jogador->destreza >= 4)
    printf("Uma das tabuas estava solta, mas voce conseguiu perceber a tempo, antes de cair na agua.\n");
  else
  {
    printf("Voce pisa em uma tabua solta, caindo no riacho e se ferindo levemente nas pedras do fundo. Voce perde 3 pontos de vida, mas continua em frente.\n");
    jogador->vida -= 3;
  }
  sleep(3);
  system("clear");
  return;
}