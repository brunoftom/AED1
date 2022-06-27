#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
struct no
{
    int info;
    struct no*prox;
};

Lista cria_lista(){
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));

    if(cab != NULL)
    {
        cab->prox = NULL;
        //cab->info = 0; //guarda a quantidade
    }

    return cab;
}

int lista_vazia(Lista lst)
{
    if(lst->prox = NULL)
        return 1;//lista vazia
    else
        return 0;//lista nao esta vazia
}

int insere_elem(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL){return 0;}

    //Preencher os campos do novo no
    N->info = elem;
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    //(*lst)->info++;//incrementa qtd de nos

    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if(lista_vazia(lst) == 1){
        return 0;//falha, lista vazia
    }

    Lista aux = *lst;

    //percorrimento ate achar o elem ou chegar ao final da lista
    while(aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    }
    if(aux->prox == NULL)
        return 0;//trata final da lista

    //remover elem diferente do 1o no da lista

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;

    free(aux2);

    //(*lst)->info--;//decrementa qtd

    return 1;
}

int obtem_valor_elem(Lista *lst, int i, int nro)
{
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;

    nro = (*lst)->info;
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
