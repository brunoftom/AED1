#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "lista.h"

#define MAX 50

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar lista de soldados (tecle 1):\n");
    printf("[2]. Inserir nomes dos soldados na lista (tecle 2):\n");
    printf("[3]. Iniciar processo de eliminação (tecle 3):\n");
    printf("[4]. Imprimir lista de soldado(s) (tecle 4):\n");
    printf("[5]. Pegar posição de soldado (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista soldados;
    Lista eliminados;
    eliminados = cria_lista();
    Lista original = cria_lista();

    int escolha = 0;
    int choice;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpção 1 escolhida -  Criar lista de soldados\n\n");
                soldados = cria_lista();
                if(soldados == NULL)
                {
                    printf("Lista criada com sucesso!\n");
                }
                break;

            case 2:
                printf("\nOpção 2 escolhida -  Inserir nomes de soldados na lista\n\n");
                int qtdd;
                char nome[MAX];

                printf("Quantidade de nomes de soldados a serem inseridos na lista: ");
                scanf("%d", &qtdd);

                while(qtdd<0)
                {
                    printf("\nQuantidade inválida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na lista:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    printf("    Soldado %d: ", i+1);
                    scanf("%s", nome);
                    insere_soldado(&soldados, nome);
                    insere_soldado(&original, nome);
                }
                break;

            case 3:
                if(lista_vazia(soldados) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }


                printf("\nOpção 3 escolhida - Iniciar processo de eliminação\n");
                printf("\nEscolha uma das três opções de início de contagem:\n");
                printf("    1. A partir do primeiro soldado da lista - tecle 1\n");
                printf("    2. A partir de uma posição sorteada aleatoriamente da lista - tecle 2\n");
                printf("    3. A partir de um soldado específico - tecle 3\n\n");

                scanf("%d", &choice);

                while(choice != 1 && choice != 2 && choice != 3)
                {
                    printf("Número inválido, digite novamente!\n");
                    scanf("%d", &choice);
                }
                printf("\n");

                int fim, numero;
                char removido[MAX], primeiro[MAX];

                srand(time(NULL));
                get_fim(&soldados, &fim);

                if(choice == 1)
                {
                    while(fim > 1)
                    {
                        get_values(&soldados, primeiro, 1);
                        numero = 1+ rand() % 20; //para nunca gerar 0
                        contagem_primeiro_soldado(&soldados, &eliminados, numero, removido);
                        remove_pos(&soldados, numero, removido);
                        //insere_soldado(&eliminados, removido);
                        printf("Primeiro soldado: %s\n", primeiro);
                        printf("Contagem: %d\n", numero);
                        printf("Soldado eliminado: %s\n\n", removido);
                        fim--;
                    }

                }else if(choice == 2)
                {
                    while(fim > 1)
                    {
                        int posicao;
                        posicao = 1+ rand() % 20;

                        while(posicao > fim)
                        {
                            posicao = 1+ rand() % 20;
                        }

                        char sorteado[MAX];
                        numero = 1+ rand() % 20;
                        get_values(&original, sorteado, posicao);
                        contagem_posicao_aleatoria(&soldados, posicao);
                        remove_pos(&soldados, numero, removido);
                        insere_soldado(&eliminados, removido);
                        printf("Posição de início: %d\n", posicao);
                        printf("Soldado sorteado: %s\n", sorteado);
                        printf("Contagem: %d\n", numero);
                        printf("Soldado eliminado: %s\n\n", removido);
                        fim--;
                    }
                }else if(choice == 3)
                {
                    while(fim > 1)
                    {
                        int verifica;
                        char especifico[MAX];
                        numero = 1+ rand() % 20;

                        printf("\nNome do soldado para iniciar a contagem: ");
                        scanf("%s", especifico);

                        verifica = get_posicao(soldados, especifico);
                        while(verifica == 0)
                        {
                            printf("\nSoldado inexistente ou já eliminado!\n");
                            printf("Digite outro nome: ");
                            scanf("%s", especifico);
                            verifica = get_posicao(soldados, especifico);
                        }

                        contagem_soldado_especifico(&soldados, especifico);
                        remove_pos(&soldados, numero, removido);
                        insere_soldado(&eliminados, removido);
                        printf("Contagem: %d\n", numero);
                        printf("Soldado eliminado: %s\n\n", removido);
                        fim--;
                    }
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir lista de soldado(s)\n\n");
                printf("Soldado sobrevivente (tecle 1) ou soldados eliminados (tecle 2): ");

                scanf("%d", &choice);

                while(choice != 1 && choice != 2)
                {
                    printf("Número inválido, digite novamente!\n");
                    scanf("%d", &choice);
                }

                int f;
                char name[MAX];

                if(choice == 1)
                {
                    if(lista_vazia(soldados) == 1)
                    {
                        printf("Lista vazia!\n\n");
                        break;
                    }

                    get_fim(&soldados, &f);

                    printf("\nSoldado sobrevivente: ");

                    for(int i=1; i <= f; i++)
                    {
                        get_values(&soldados, name, i);
                        printf("%s\n", name);
                    }
                }else if(choice == 2)
                {
                    if(lista_vazia(eliminados) == 1)
                    {
                        printf("Lista vazia!\n\n");
                        break;
                    }

                    get_fim(&eliminados, &f);

                    printf("\nSoldados eliminados:\n\n");

                    for(int i=1; i < f+1; i++)
                    {
                        get_values(&eliminados, name, i);
                        printf("    Soldado %d - %s\n", i, name);
                    }
                }
                printf("\n");
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Pegar posição de soldado\n\n");
                if(lista_vazia(soldados) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int posicao;
                char sold[MAX];
                printf("Nome do soldado: ");
                scanf("%s", sold);

                posicao = get_posicao(soldados, sold);

                if(posicao == 0)
                {
                    printf("Não há soldado com tal nome!\n");
                }else
                {
                    printf("Posição do soldado %s: %d\n\n", sold, posicao);
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha != 6);

    return 0;
}
