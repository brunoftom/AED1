#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"

int main()
{
    int op, elem, i, k, l, m, n, lista;
    Lista lst1;
    Lista lst2;
    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Remover elemento\n");
            printf(" 5. Verificar tamanho\n");
            printf(" 6. Verificar media de elementos\n");//
            printf(" 7. Verificar listas iguais\n");//
            printf(" 8. Remover ocorrencias do elemento da lista\n");
            printf(" 9. Remover maior elemento da lista\n");
            printf(" 10. Verificar multiplos de 3\n");//
            printf(" 11. Imprimir lista\n");
            printf(" 12. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 11)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 11));

        switch(op)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n");
                lst1 = cria_lista();
                lst2 = cria_lista();
                if(lst1 != NULL  && lst2 != NULL)
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
                printf("\nOpcao 3 escolhida -  3. Inserir elemento\n");
                printf("\nQual lista deseja remover o elemento? (1 ou 2) ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    printf("\nDigite o elemento que deseja inserir: ");
                    scanf("%d", &elem);
                    insere_elemento(&lst1, elem);
                }
                if(lista == 2)
                {
                    printf("\nDigite o elemento que deseja inserir: ");
                    scanf("%d", &elem);
                    insere_elemento(&lst2, elem);
                }
                getch();
                break;
            case 4:
                printf("\nOpcao 4 escolhida -  Remover elemento\n");

                printf("\nQual elemento deseja remover? ");
                scanf("%d", &elem);
                if(remove_elemento(&lst1, elem) == 0)
                {
                    printf("\nElemento nao esta na lista\n");
                }
                else
                {
                    printf("\nElemento %d removido com sucesso!!", elem);
                }
                getch();
                break;
            case 5:
                printf("\nOpcao 5 escolhida -  Verificar tamanho\n");
                if (lst1 == NULL || lista_vazia(lst1) == 1)
                {
                    printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
                }
                else
                {
                    printf("A lista tem tamanho: %d", get_end(lst1));
                }
                getch();
                break;
            case 6:
                printf("\nOpcao 6 escolhida -  Verificar media de elementos\n");
                getch();
                break;
            case 7:
                printf("\nOpcao 7 escolhida -  Verificar listas iguais\n");
                if(comparar_listas(lst1, lst2))
                {
                    printf("\nListas iguais\n");
                }
                else{
                    printf("\nListas diferentes\n");
                }

                getch();
                break;
            case 8:
                printf("\nOpcao 8 escolhida -  Remover todos as ocorrencias do elemento da lista\n");
                if (lst1 == NULL || lista_vazia(lst1) == 1)
                {
                    printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
                }
                else
                {
                    printf("\nDigite o valor que você deseja excluir: ");
                    scanf("%d", &elem);
                    remove_todos(&lst1, elem);
                }
                getch();
                break;
            case 9:
                printf("\nOpcao 9 escolhida -  Remover maior elemento da lista\n");

                if (lst1 == NULL || lista_vazia(lst1) == 1)
                {
                    printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
                }
                else
                {
                    remove_maior(&lst1, &elem);
                    printf("O maior número que foi excluído era: %d", elem);
                }
                getch();
                break;
            case 10:
                printf("\nOpcao 10 escolhida -  Verificar multiplos de 3\n");
                getch();
                break;
            case 11:
                printf("\nOpcao 11 escolhida -  Imprimir lista\n");
                k = get_end(lst1);
                printf("\nQual lista deseja imprimir? ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    if (lst1 == NULL || lista_vazia(lst1) == 1)
                    {
                    printf("\n\nLISTA 1 VAZIA!!\n\n");
                    }
                    else
                    {
                        l = 0;
                        printf("lista 1:\n");
                        while (l<k)
                        {
                            elem = get_element(lst1, l);
                            printf("\nNum [%d]: %d",l+1, elem);
                            l++;
                        }
                    }
                }
                if(lista == 2)
                {
                    m = get_end(lst2);
                    if (k < 0 && lst2 == NULL || lista_vazia(lst2))
                    {
                        printf("\n\nLISTA 2 VAZIA!!\n\n");
                    }
                    else
                    {
                        n = 0;
                        printf("lista 2:\n");
                        while (n<m)
                        {
                            elem = get_element(lst2, n);
                            printf("\nNum [%d]: %d",n+1, elem);
                            n++;
                        }
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
        }while(op != 12);
    return 0;
}
