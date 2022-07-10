#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10
#include "lista.h"

int main()
{
    int op, elem, qtd, n, lista, tamanho, menor;
    Lista lst1;
    Lista lst2;
    Lista lst3;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar listas\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Remover impares\n");
            printf(" 6. Verificar menor elemento\n");
            printf(" 7. Ordenar lista\n");
            printf(" 8. Verificar tamanho da lista\n");
            printf(" 9. Concatenar listas\n");
            printf(" 10. Imprimir lista\n");
            printf(" 11. SAIR\n");
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
                lst3 = cria_lista();
                if(lst1 == NULL && lst2 == NULL && lst3 == NULL)
                {
                    printf("Falha na criacao das listas!\n\n");
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

                if(lista_vazia(lst2) == 1){
                    printf("\nLista 2 esta vazia\n");
                }else{
                    printf("\nLista 2 nao esta vazia\n");
                }

                if(lista_vazia(lst3) == 1){
                    printf("\nLista 3 esta vazia\n");
                }else{
                    printf("\nLista 3 nao esta vazia\n");
                }
                getch();
                break;

            case 3:
                printf("\nOpcao 3 escolhida -  Inserir elemento\n");

                printf("Qual lista deseja inserir os elementos? (1 ou 2) ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    if(lista_cheia(lst1) == 1)
                        printf("Lista esta cheia \n");

                    printf("\nQuantos elementos deseja inserir na lista 1? ");
                    scanf("%d", &qtd);
                    while(qtd<0 || qtd>max)
                    {
                        printf("\nQuantidade inválida!\n");
                        printf("\nDigite novamente: ");
                        scanf("%d", &qtd);
                    }
                    printf("Insira os elementos:\n");

                    for(int i = 0;i<qtd; i++)
                    {
                        if(lista_cheia(lst1) == 1){
                        printf("Lista 1 esta cheia \n");
                    }
                    printf("Elemento %d: ", i+1);
                    scanf("%d", &elem);
                    insere_elem(lst1, elem);
                    }
                }
                if(lista == 2)
                {
                    if(lista_cheia(lst1) == 1)
                        printf("Lista esta cheia \n");

                    printf("\nQuantos elementos deseja inserir na lista 2? ");
                    scanf("%d", &qtd);
                    while(qtd<0 || qtd>max)
                    {
                        printf("\nQuantidade inválida!\n");
                        printf("\nDigite novamente: ");
                        scanf("%d", &qtd);
                    }
                    printf("Insira os elementos:\n");

                    for(int i = 0;i<qtd; i++)
                    {
                        if(lista_cheia(lst2) == 1){
                        printf("Lista 2 esta cheia \n");
                    }
                    printf("Elemento %d: ", i+1);
                    scanf("%d", &elem);
                    insere_elem(lst2, elem);
                    }
                }
                getch();
                break;
            case 4:
                printf("\nOpcao 4 escolhida -  Remover elemento\n");

                printf("\nQual lista deseja remover o elemento? (1 ou 2) ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    if(lista_vazia(lst1) == 1 ){
                        printf("\nLista vazias\n");
                        break;
                    }
                    printf("\nQual elemento deseja remover da lista 1? ");
                    scanf("%d", &n);
                    if(remove_elem(lst1, n) == 0)
                    {
                        printf("\nElemento nao encontrado na lista!\n");
                    }else{
                        printf("\nElemento removido com sucesso!\n");
                    }
                }
                if(lista == 2)
                {
                    printf("Qual elemento deseja remover da lista 2? ");
                    scanf("%d", &n);
                    if(remove_elem(lst2, n) == 0)
                    {
                        printf("\nElemento nao encontrado na lista!\n");
                    }else{
                        printf("\nElemento removido com sucesso!\n");
                    }
                }
                getch();
                break;
            case 5:
                printf("\nOpcao 5 escolhida -  Remover impares\n");
                if(lista_vazia(lst1) == 1 && lista_vazia(lst2) == 1 ){
                    printf("\nListas 1 e 2 vazias\n");
                    getch();
                    break;
                }

                printf("Lista 1 ou 2? ");
                scanf("%d", &lista);

                if(lista == 1)
                {
                    if(remove_impares(lst1) == 0)
                    {
                        printf("\nNao foi possivel remover os elementos");
                        getch();
                        break;
                    }
                    else
                    {
                        printf("\nElementos impares removidos");
                        getch();
                        break;
                    }

                }else if(lista == 2)
                {
                    if(remove_impares(lst2) == 0)
                    {
                        printf("\nNao foi possivel remover os elementos");
                    }
                    else
                    {
                        printf("\nElementos impares removidos");
                    }
                }
                getch();
                break;
            case 6:
                printf("\nOpcao 6 escolhida - Verificar menor elemento\n");
                if(lista_vazia(lst1) == 1 && lista_vazia(lst2) == 1 ){
                    printf("\nListas 1 e 2 vazias\n");
                    break;
                }

                printf("Lista 1 ou 2? ");
                scanf("%d", &lista);

                if(lista == 1)
                {
                    menor_elemento(lst1, &menor);
                    printf("Menor elemento da lista 1: %d", menor);
                }else if(lista == 2)
                {
                    menor_elemento(lst2, &menor);
                    printf("Menor elemento da lista 2: %d", menor);
                }
                getch();
                break;
            case 7:
                printf("\nOpcao 7 escolhida - Ordenar lista\n");

                break;
            case 8:
                printf("\nOpcao 8 escolhida - Verificar tamanho das listas\n");

                printf("\nLista 1: ");
                tamanho_lista(lst1, &tamanho);
                printf(" %d ", tamanho);
                printf("\nLista 2: ");
                tamanho_lista(lst2, &tamanho);
                printf(" %d ", tamanho);
                printf("\nLista 3: ");
                tamanho_lista(lst3, &tamanho);
                printf(" %d ", tamanho);
                getch();
                break;
            case 9:
                printf("\nOpcao 09 escolhida -  Concatenar listas\n");
                if(lista_vazia(lst1) == 1 && lista_vazia(lst2) == 1 ){
                    printf("\nListas 1 e 2 vazias\n");
                    break;
                }

                lst3 = concatenar_listas(lst1,lst2);
                printf("\nLista concatenada: \n");
                print1(lst3);
                getch();
                break;
            case 10:
                printf("\nOpcao 10 escolhida -  Imprimir listas\n");
                if(lista_vazia(lst1) == 1 && lista_vazia(lst2) == 1 && lista_vazia(lst3) == 1){
                    printf("\nListas vazias\n");
                    break;
                }
                printf("\nLista 1: ");
                print1(lst1);

                printf("\nLista 2: ");
                print1(lst2);

                printf("\nLista 3: ");
                print1(lst3);

                getch();
                break;
            case 11:
                printf("\n\nFim do programa \n\n");
                break;
            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 11);

    return 0;
}
