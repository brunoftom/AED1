#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 20

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

    if(lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    //incremente elemento na lista
    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if(lista_vazia(lst) == 1 || elem <(*lst)->info)
        return 0;
    
    Lista aux = *lst;
    
    //trata elem 1o da lista
    if(elem == (*lst)->info)
    {
        *lst = aux->prox;//aponta para o 2o no
        free(aux);
        return 1;
    }
    
    //percorre ate final da lista, achar o elem ou maior
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    
    if(aux->prox = NULL || aux->prox->info> elem)
        return 0;
    
    //remove elemento da lista 
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

void print1(Lista lst)
{
    printf("Lista: { ");
    for(lst; lst != NULL; lst = lst->prox)
    {
        printf(" %d ", lst->info);

    }
    printf(" }");
}
