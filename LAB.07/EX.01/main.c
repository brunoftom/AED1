#include <stdio.h>
#include <stdlib.h>
#define max 11

#include "lista.h"

int main()
{
     int op, elem, qtd, n;
     Lista lst;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Imprimir lista\n");
            printf(" 6. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 6)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 6));

        switch(op)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n");
                lst = cria_lista();
                if(lst == NULL)
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
                if(lista_vazia(lst) == 1){
                    printf("\nLista esta vazia\n");
                }else{
                    printf("\nLista nao esta vazia\n");
                }
                getch();
                break;

            case 3:
                printf("\nOpcao 3 escolhida -  Inserir elemento\n");

                printf("Quantos elementos deseja inserir na lista? ");
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
                    insere_elem(&lst, elem);
                }
                getch();
                break;

            case 4:
                printf("\nOpcao 4 escolhida -  Remover elemento\n");
                if(lista_vazia(lst) == 1){
                    printf("\nLista esta vazia\n");
                }

                printf("Qual elemento deseja remover? ");
                scanf("%d", &n);
                if(remove_elem(&lst, n) == 0)
                {
                    printf("\nElemento nao encontrado na lista!\n");
                }else{
                    printf("\nElemento removido com sucesso!\n");
                }
                getch();
                break;

            case 5:
                printf("\nOpcao 5 escolhida -  Imprimir lista\n");
                print1(lst);
                getch();
                break;

            case 6:
                printf("\n\nFim do programa \n\n");
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 6);

    return 0;
}
