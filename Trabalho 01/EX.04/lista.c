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

int tamanho_lista(Lista lst)
{
    return lst->info;
}


int obtem_valor_elem(Lista lst, int i, int *nro){
    if(lst == NULL || lista_vazia(lst))
        return 0;

    *nro = (*lst).prox;

    return 1;
}

int comparar_listas(Lista lst1, Lista lst2)
{
    int size1 = tamanho_lista(lst1), size2 = tamanho_lista(lst2);
    if(size1 != size2)
        return 0;
    int cont = 0;
    Lista tmp1 = lst1->prox;
    Lista tmp2 = lst2->prox;
    while((tmp1 != NULL) && (tmp1->info == tmp2->info))
    {
        tmp1 = tmp1->prox;
        tmp2 = tmp2->prox;
        cont ++;
    }

    if(cont == size1)
        return 1;
    else
        return 0;
}

Lista intercalar_lista(Lista lst1, Lista lst2)
{
    Lista tmp3 = cria_lista();
    while((lst1->prox != NULL) || (lst2->prox != NULL))
    {
        if(lst1->prox != NULL)
        {
            insere_elem(&tmp3, lst1->info);
            lst1 = lst1->prox;
        }
        if(lst2->prox != NULL)
        {
            insere_elem(&tmp3, lst2->info);
            lst2 = lst2->prox;
        }
    }
    return tmp3;
}

int inverter_lista(Lista lst1, Lista *inv)
{
    if (lst1==NULL||(*inv)!=NULL)
        return 0;

    Lista aux = lst1->prox;
    Lista aux2 = (struct node*)malloc(sizeof(struct node));

    (*inv)=aux2;
    aux2->info = lst1->info;
    aux2->prox = NULL;
    while (aux!=NULL){
        aux2 = (struct node*)malloc(sizeof(struct node));
        aux2->prox = (*inv);
        aux2->info = aux->info;
        (*inv) = aux2;
        aux = aux->prox;
    }

    return 1;
}

void print1(Lista *lst)
{
    Lista aux = (*lst)->prox;
    do
    {
        printf(" [%d]", aux->info);
        aux = aux->prox;

    }
    while(aux != NULL);
}
