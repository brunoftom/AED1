#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 20

#include "lista.h"

int main()
{
    int op, elem, qtd, n, lista, k;
    Lista lst1;
    Lista lst2;
    Lista lst3;
    Lista invertida;
    Lista impares;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Verificar tamanho\n");
            printf(" 6. Calcular media da lista\n");
            printf(" 7. Verificar iguais\n");
            printf(" 8. Intercalar listas\n");
            printf(" 9. Inverter listas\n");
            printf(" 10. Retornar Impares\n");
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
                lst2 = cria_lista();
                lst3 = cria_lista();
                if(lst1 != NULL && lst2 != NULL && lst3 == NULL)
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
                        printf("Elemento %d: ", i+1);
                        scanf("%d", &elem);
                        insere_elem(&lst1, elem);
                    }
                }
                if(lista == 2)
                {
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
                        printf("Elemento %d: ", i+1);
                        scanf("%d", &elem);
                        insere_elem(&lst2, elem);
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
                    if(remove_elem(&lst1, n) == 0)
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
                    if(remove_elem(&lst2, n) == 0)
                    {
                        printf("\nElemento nao encontrado na lista!\n");
                    }else{
                        printf("\nElemento removido com sucesso!\n");
                    }
                }
                getch();
                break;
            case 5:
                printf("\nOpcao 5 escolhida -  Verificar tamanho\n");

                printf("\nLista 1: %d elementos", tamanho_lista(lst1));
                printf("\nLista 2: %d elementos", tamanho_lista(lst2));
                printf("\nLista 3: %d elementos", tamanho_lista(lst3));
                getch();
                break;
            case 6:
                printf("\nOpcao 6 escolhida -  Calcular media da lista\n");
                printf("\nQual lista deseja calcular a  media? (1 ou 2) ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    k = tamanho_lista(lst1);
                    printf("\nA media da lista 1 eh: %.2f", calcular_media(&lst1, k));
                    getch();
                    break;
                }
                if(lista == 2)
                {
                    k = tamanho_lista(lst1);
                    printf("\nA media da lista 2 eh: %.2f", calcular_media(&lst2, k));
                }
                getch();
                break;
            case 7:
                printf("\nOpcao 7 escolhida -  Verificar iguais\n");
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
                printf("\nOpcao 8 escolhida -  Intercalar listas\n");

                if(intercalar_lista(lst1, lst2, &lst3) == 0)
                {
                    printf("\nNao foi possivel intercalar as listas");
                }
                else
                {
                    printf("\nListas intercaladas");
                    getch();
                }
                getch();
                break;
            case 9:
                printf("\nOpcao 9 escolhida -  Inverter listas\n");
                printf("\nInverter lista 1 ou lista 2? ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    invertida = cria_lista();
                    inverter_lista(lst1, &invertida);
                    printf("Lista invertida: ");
                    print1(invertida);
                    getch();
                    break;
                }
                else if(lista == 2)
                {
                    invertida = cria_lista();
                    inverter_lista(lst2, &invertida);
                    printf("Lista invertida: ");
                    print1(invertida);
                    getch();
                    break;
                }
                getch();
                break;
            case 10:
                printf("\nOpcao 10 escolhida -  Retornar impares\n");
                printf("\nDeseja ver os impares da lista 1 ou 2? ");
                scanf("%d", &lista);
                if(lista == 1)
                {
                    impares = cria_lista();
                    lista_impares(lst1, &impares);
                    printf("Impares lista 1: ");
                    print1(impares);
                    getch();
                    break;
                }else if(lista == 2)
                {
                    impares = cria_lista();
                    lista_impares(lst2, impares);
                    printf("Impares lista 2: ");
                    print1(impares);
                    getch();
                    break;
                }
                getch();
                break;
            case 11:
                printf("\nOpcao 11 escolhida -  Imprimir lista\n");

                printf("\nLista 1:");
                print1(lst1);

                printf("\nLista 2:");
                print1(lst2);

                printf("\nLista 3:");
                print1(lst3);

                getch();
                break;
            case 12:
                printf("\n\nFim do programa \n\n");
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 12);

    return 0;
}
