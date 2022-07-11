#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct node{
    int info;
	struct node* prox;
};

Lista cria_lista(){
    Lista cab;
    cab = (Lista)malloc(sizeof(struct node));

    if(cab != NULL)
    {
        cab->prox = NULL;
        cab->info = 0; //guarda a quantidade
    }

    return cab;
}

int lista_vazia(Lista lst)
{
    if(lst->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *lst, int elem)
{
    Lista N = (Lista) malloc(sizeof(struct node));
    if (N == NULL)
    {
        return 0;
    }

    N->info = elem;

    Lista aux = (*lst);

    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;// Opcional: Incrementa qtde de nós na lista

    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if(lista_vazia(lst) == 1)
    {
        return 0;
    }

    Lista aux = *lst;

    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

     if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    (*lst)->info--;

    return 1;
}

int obtem_valor_elem(Lista lst, int i, int *nro){
    if(lst == NULL || lista_vazia(lst))
        return 0;

    *nro = (*lst).prox;

    return 1;
}

void print1(Lista *lst)
{
    Lista aux = (*lst)->prox;
    do
    {
        printf(" [%d]", aux->info);
        aux = aux->prox;

    }while(aux != NULL);
}
