#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 20

#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_Lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_final(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;

    if(lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }
    else
    {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    return 1;
}

int remove_inicio(Lista *lst, int *elem)
{
    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = (*lst)->prox;//aux aponta para 1o no

    *elem = aux->info;//retorna valor do no a ser removido

    if(*lst == (*lst)->prox)
        *lst = NULL;
    else
        (*lst)->prox = aux->prox;

    free(aux);
    return 1;

}

int obtem_valor_elem(Lista lst, int i)
{
    Lista aux = lst->prox; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux != lst && pos < i)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->info;
}

int get_end(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
    {
        return 0; // Falha
    }

    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != lst)
    {
        aux = aux->prox;
        pos++;
    }

    return pos;
}

void print1(Lista lst)
{
    int k = 0, l=0, i =0;
    k = get_end(lst);
    if (lst == NULL || lista_vazia(lst) == 1 || k < 0)
    {
        printf("\n\nLISTA VAZIA!!\n\n");
    }
    else
    {
        printf("Lista: { ");
        while (l<=k)
        {
            i = obtem_valor_elem(lst, l);
            printf(" %d ", i);
            l++;
            }
         printf(" }");
    }
}
