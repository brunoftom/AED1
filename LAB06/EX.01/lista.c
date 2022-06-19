#include <stdio.h>
#include <stdlib.h>
#define max 20
#include <conio.h>

#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst)
{
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = elem;
    N->prox = *lst;
    *lst = N;

    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if(lista_vazia(lst) == 1)
        return 0;

    Lista aux  = *lst;
    if(elem == (*lst)->info)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;

    if(aux->prox == NULL)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);

    return 1;
}

int obtem_valor_elem(Lista lst, int i, int *nro){
    if(lst == NULL || lista_vazia(lst))
        return 0;

    *nro = (*lst).prox;

    return 1;
}


int get_end(Lista lst)
{
    if (lst == NULL || lista_vazia(&lst) == 1)
    {
        return 0; // Falha
    }

    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
        pos++;
    }

    return pos;
}

void print1(Lista lst)
{
    printf("Lista: { ");
    for(lst; lst != NULL; lst = lst->prox)
    {
        printf(" %d ", lst->info);

    }
    printf(" }");
}
