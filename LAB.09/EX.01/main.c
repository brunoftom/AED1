#include <stdio.h>
#include <stdlib.h>
#define max 20

#include "pilha.h"

int main()
{
    Pilha p1;
    int op, elem, pilha;

    do{
        system("CLS || clear");
        do{
            printf(" --- PILHA ESTATICA SEQUENCIAL --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Remover elemento\n");
            printf(" 5. Imprimir pilha\n");
            printf(" 6. Ler topo da pilha\n");
            printf(" 7. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 7)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 7));

        switch(op)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar pilha\n");
                p1 = cria_pilha();
                getch();
                break;
            case 2:
                printf("\nOpcao 2 escolhida -  Verificar pilha vazia\n");

                if(pilha_vazia(p1) != -1)
                {
                    printf("\nPilha vazia\n");
                }
                else
                {
                    printf("\Pilha nao esta vazia");
                }
                getch();
                break;
            case 3:
                printf("\nOpcao 3 escolhida -  Inserir elemento\n");

                printf("\nQual elemento deseja inserir na pilha? ");
                scanf("%d", &elem);
                if(push(p1, elem) == 1)
                {
                    printf("\nElemento inserido com sucesso\n");
                }
                else
                {
                    printf("\nNao foi possivel inserir o elemento na pilha\n");
                }
                getch();
                break;
            case 4:
                printf("\nOpcao 4 escolhida -  Remover elemento\n");

                printf("\nQual elemento deseja remover na pilha? ");
                scanf("%d", &elem);
                if(pop(p1, &elem) == 1)
                {
                    printf("\nElemento removido com sucesso\n");
                }
                else
                {
                    printf("\nElemento nao encontrado na pilha\n");
                }
                getch();
                break;
            case 5:
                printf("\nOpcao 5 escolhida -  imprimir pilha\n");
                pilha = print1(p1);
                getch();
                break;
            case 6:
                printf("\nOpcao 6 escolhida -  ler topo da  pilha\n");
                printf("\nElemento que esta no topo: ");
                le_topo((p1,&elem));
            case 7:
                printf("\n\nFim do programa \n\n");
                break;
            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 7);

    return 0;
}
