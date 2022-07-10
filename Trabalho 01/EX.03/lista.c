#include <stdio.h>
#include <stdlib.h>
#define max 20
#include <conio.h>
#include <math.h>

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

    Lista tmp = *lst;
    while(tmp->prox != NULL && tmp->prox->info < elem)
        tmp = tmp->prox;

    N->prox = tmp->prox;
    tmp->prox = N;

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

int obtem_valor_elem(Lista lst, int *nro){
    if(lst == NULL || lista_vazia(lst))
        return 0;

    *nro = lst->prox;

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

int tamanho_lista(Lista lst)
{
    if(lista_vazia(lst))
        return 0;

    int size = 1;
    while(lst->prox != NULL)
    {
        lst = lst->prox;
        size ++;
    }
    return size;
}
int comparar_listas(Lista lst1, Lista lst2)
{
    int size1 = tamanho_lista(lst1), size2 = tamanho_lista(lst2);
    if(size1 != size2)
        return 0;


    int cont = 0;
    while((lst1 != NULL) && (lst1->info == lst2->info))
    {
        lst1 = lst1->prox;
        lst2 = lst2->prox;
        cont ++;
    }

    if(cont == size1)
        return 1;
    else
        return 0;
}

int inserePos(Lista *no, int elem)//funcao para ordenar a lista 3 (concatenada)
{

    Lista newNode = (Lista) malloc(sizeof(struct no));
    if(newNode == NULL)
        return 0;

    newNode->info = elem;
    newNode->prox = NULL;
    if(*no != NULL)
        (*no)->prox = newNode;
    *no = newNode;
    return 1;
}

int inverter_lista(Lista lst1, Lista *inv)
{
    if (lst1==NULL||(*inv)!=NULL)
        return 0;

    Lista aux = lst1->prox;
    Lista aux2 = (struct no*)malloc(sizeof(struct no));

    (*inv)=aux2;
    aux2->info = lst1->info;
    aux2->prox = NULL;
    while (aux!=NULL){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux2->prox = (*inv);
        aux2->info = aux->info;
        (*inv) = aux2;
        aux = aux->prox;
    }

    return 1;
}

int intercalar_lista(Lista lst1, Lista lst2, Lista *lst3)
{
    int ch = 1;
    Lista tmp3 = NULL;
    while((lst1 != NULL) && (lst2 != NULL))
    {
        if(lst1->info <= lst2->info)
        {
            if(!inserePos(&tmp3, lst1->info))
                return 0;
            lst1 = lst1->prox;
        }
        else
        {
            if(!inserePos(&tmp3, lst2->info))
                return 0;
            lst2 = lst2->prox;
        }
        if(ch)
        {
            *lst3 = tmp3;
            ch = 0;
        }
    }
    while(lst1 != NULL)
    {
        if(!inserePos(&tmp3, lst1->info))
            return 0;
        lst1 = lst1->prox;
        if(ch)
        {
            *lst3 = tmp3;
            ch = 0;
        }
    }
    while(lst2 != NULL)
    {
        if(!inserePos(&tmp3, lst2->info))
            return 0;
        lst2 = lst2->prox;
        if(ch)
        {
            *lst3 = tmp3;
            ch = 0;
        }
    }
    return 1;
}

int lista_impares(Lista lst, Lista *b)
{
    return 1;
}
int calcular_media(Lista *lst, int tam)
{
    int soma, elem, aux, i;
    float media;
    if(lst == NULL)
        return 0;
    elem = (*lst)->info;
    aux = (*lst)->prox;

    for(lst; lst < tam; lst++)
    {
        soma = elem + aux;
    }

    return soma/tam;
}

void print1(Lista lst)
{
    printf(" { ");
    for(lst; lst != NULL; lst = lst->prox)
    {
        printf(" %d ", lst->info);

    }
    printf(" }");
}
