#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>
#define MAXN 20
#define MAX 11

void imprimir_lista(Lista lst)
{
    int k = get_end(lst);
    int l = 0;
    printf("\nP(x) = ");
    while (l<k)
    {
        int expoente = get_expoente(lst, l);
        int termo = get_termo(lst, l);
        if(termo> 0)
        {
            if(expoente == 0)
            {
                printf("%d", termo);
            }
            else  if(expoente == 1)
            {
                printf(" + %dx",termo);
            }
            else
            {
                printf(" + %dx^%d",termo, expoente);
            }
        }
        else if(termo < 0)
        {
            if(expoente == 0)
            {
                printf("%d", termo);
            }
            else  if(expoente == 1)
            {
                printf(" - %dx",termo*-1);
            }
            else
            {
                printf(" - %dx^%d",termo*-1, expoente);
            }
        }
        l++;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    Lista lst;
    int expoente = 0, termo = 0, k = 0, m = 1, option = 0, verifica = 0;

    while(m == 1)
    {

        printf("\n[0] Inicializar a lista");
        printf("\n[1] Inserir registro");
        printf("\n[2] Apagar um registro");
        printf("\n[3] Imprimir Lista");
        printf("\n[4] Limpar lista:  ");
        printf("\n[5] Calcular o valor da expressão:  ");
        printf("\n[6] Sair:  ");

        scanf("%d", &option);
        if (option == 0 && verifica == 0)
        {
            lst = cria_lista();
            verifica = 1;
            printf("\nLISTA CRIADA!!\n");
        }
        else if(verifica == 1)
        {
            if(option == 0)
            {

                printf("\nLISTA JÁ FOI CRIADA ANTERIORMENTE!!\n");

            }
            else if(option == 1)
            {

                printf("\nInsira um termo que acompanha o x: ");
                scanf("%d", &termo);
                printf("\nInsira um expoente: ");
                scanf("%d", &expoente);
                insere_ord(&lst, termo, expoente);
            }
            else if(option == 2)
            {
                if (lst == NULL || lista_vazia(lst) == 1)
                {
                    printf("\n\nLISTA ESTÁ VAZIA!!");
                    printf("\nP(x) = 0x^0\n\n");
                }
                else
                {
                    printf("\nDigite o valor do expoente: ");
                    scanf("%d", &expoente);
                    k = remove_ord(&lst, expoente);
                    if (k == 0)
                    {
                        printf("\n\nELEMENTO NÃO EXISTE!!\n\n");
                    }
                }
            }
            else if(option == 3)
            {
                if (lst == NULL || lista_vazia(lst) == 1)
                {
                    printf("\n\nLISTA ESTÁ VAZIA!!");
                    printf("\nP(x) = 0x^0\n\n");
                }
                else
                {
                    imprimir_lista(lst);
                }

            }
            else if(option == 4)
            {

                if (lst == NULL || lista_vazia(lst) == 1)
                {
                    printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
                    printf("\nP(x) = 0x^0\n\n");
                }
                else
                {
                    limpa_lista(&lst);
                }

            }
            else if(option == 5)
            {
                if (lst == NULL || lista_vazia(lst) == 1)
                {
                    printf("\n\nLISTA ESTÁ VAZIA!!");
                    printf("\nP(x) = 0x^0\n\n");
                }
                else
                {
                    printf("\nDigite o valor de x: ");
                    scanf("%d", &expoente);
                    printf("\n\nO RESULTADO DA FUNÇÃO É: %d\n\n", resultado(lst, expoente));

                }
            }
            else if(option == 6)
            {
                return 0;
            }
            else
            {
                printf("OPÇÃO INVÁLIDA!!");
                return 0;
            }

            printf("\n\n");
        }
        else
        {
            printf("\n\nCRIE UMA LISTA ANTES!!\n\n");
        }
    }

    return 0;
}
