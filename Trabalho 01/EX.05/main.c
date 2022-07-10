#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"

int main()
{
    int op, elem, i, pos;
    Lista lst1;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento (final)\n");
            printf(" 4. Inserir elemento (inicio)\n");
            printf(" 5. Inserir elemento (posicao)\n");
            printf(" 6. Remover elemento (inicio)\n");
            printf(" 7. Remover elemento (posicao)\n");
            printf(" 8. Verificar tamanho\n");
            printf(" 9. Verificar maior elemento\n");
            printf(" 10. Remover pares\n");
            printf(" 11. Imprimir lista\n");
            printf(" 12. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 12)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 12));

        switch(op)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n");
                lst1 = cria_lista();
                if(lst1 != NULL)
                {
                    printf("Falha na criacao da lista!\n\n");
                    return 0;
                }else{
                    printf("Lista criada com sucesso!!\n\n");
                }
                getch();
                break;
            case 2:
                printf("\nOpcao 2 escolhida -  Verificar lista vazia\n");
                if(lista_vazia(lst1) == 1){
                    printf("\nLista 1 esta vazia\n");
                }else{
                    printf("\nLista 1 nao esta vazia\n");
                }
                getch();
                break;

            case 3:
                printf("\nOpcao 3 escolhida -  3. Inserir elemento (final)\n");

                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &elem);

                insere_final(&lst1, elem);
                getch();
                break;
            case 4:
                printf("\nOpcao 5 escolhida - Inserir elemento (inicio)\n");
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &elem);
                insere_inicio(&lst1, elem);
                getch();
                break;
            case 5:
                printf("\nOpcao 5 escolhida - Inserir elemento (posicao)\n");
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &elem);
                printf("\ndigite a posicao: ");
                scanf("%d",&i);
                insere_posicao(&lst1,i, elem);
                getch();
                break;
            case 6:
                printf("\nOpcao 6 escolhida -  Remover elemento (inicio) \n");

                if(remove_inicio(&lst1, &elem) == 0)
                {
                    printf("\nLista vazia\n");
                }
                else
                {
                    printf("\nElemento %d removido com sucesso!!", elem);
                }
                getch();
                break;
            case 7:
                printf("\nOpcao 7 escolhida -  Remover elemento (posicao) \n");

                int c;
                printf("Posição: ");
                scanf("%d", &pos);

                    remove_pos(&lst1, pos, c);
                    printf("\nElemento removido: %d\n\n", c);
                    break;
                getch();
                break;
            case 8:
                printf("\nOpcao 8 escolhida -  Verificar tamanho\n");

                if(lista_vazia(lst1) == 1)
                {
                    printf("\nLista vazia!\n\n");
                    break;
                }

                int tam;
                get_fim(&lst1, &tam);
                //printf("Tamanho da lista: %d\n\n", tam);
                printf("\nTamanho da lista : %d elementos\n", tam);

                getch();
                break;
            case 9:
                printf("\nOpcao 9 escolhida -  Verificar maior elemento\n");

                getch();
                break;
            case 10:
                printf("\nOpcao 8 escolhida -  Remover pares\n");
                if(remove_par(&lst1)==0)
                {
                    printf("\nerro:lista vazia\n");
                }
                else
                {
                    printf("\nElementos pares removidos!!\n");
                getch();
                break;
            case 11:
                printf("\nOpcao 11 escolhida -  Imprimir lista\n");

                if(lista_vazia(lst1)==1)
                    printf("\nlista vazia\n");
                else{
                    for(i=1;obtem_valor_elem(lst1,i,&elem)!=0;i++){
                        printf("\n(%d)%d ",i,elem);
                }
                }
                getch();
                break;
            case 12:
                printf("\n\nFim do programa \n\n");
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
                }
        }
    } while(op != 12);

    return 0;
}
