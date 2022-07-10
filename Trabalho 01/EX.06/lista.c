#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAXN 20
#define MAX 11

struct no
{
    int info;
    struct no * prox;
    struct no * ant;
};
typedef struct no * Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1; // Lista vazia
    }
    else
    {
        return 0; // Lista NÃO vazia
    }
}

int insere_elemento(Lista *lst, int elem)
{
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0; // Falha: nó não alocado
    }
    N->info = elem; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = *lst; // Sucessor do novo nó recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0)  // Se lista NÃO vazia
    {
        (*lst)->ant = N; // Faz o antecessor do 1o nó ser o novo nó
    }
    *lst = N; // Faz a lista apontar para o novo nó
    return 1;
}

int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst))  // Trata lista vazia
    {
        return 0;
    }
    Lista aux = *lst; // Faz aux apontar para 1o nó
    while (aux->prox != NULL && aux->info != elem)
    {
        aux = aux->prox;
    }
    if (aux->info != elem)
    {
        return 0; // Elemento não está na lista
    }
    if (aux->prox != NULL)
    {
        (aux)->prox->ant = aux->ant;
    }
    if (aux->ant != NULL)
    {
        (aux)->ant->prox = aux->prox;
    }
    if (aux == *lst)
    {
        *lst = aux->prox;
    }
    free(aux);
    return 1;
}

int remove_maior(Lista *lst, int *num)
{
    if (lista_vazia(*lst))  // Trata lista vazia
    {
        return 0;
    }

    int maior = (*lst)->info;

    Lista aux = *lst; // Faz aux apontar para 1o nó
    Lista aux2 = aux;
    while (aux->prox != NULL)
    {
        if(maior < aux->info)
        {
            maior = aux->info;
            aux2 = aux;
        }
        aux = aux->prox;
    }

    if (aux2->prox != NULL)
    {
        (aux2)->prox->ant = aux2->ant;
    }
    if (aux2->ant != NULL)
    {
        (aux2)->ant->prox = aux2->prox;
    }
    if (aux2 == *lst)
    {
        *lst = aux2->prox;
    }
    *num = maior;
    free(aux);
    free(aux2);
    return 1;
}

int remove_todos(Lista *lst, int num)
{
    if(lista_vazia(*lst))
    {
        return 0;
    }
    int ch = 0;
    Lista tmp = *lst, tmp2;
    while(tmp != NULL)
    {
        ch = 0;
        if(tmp->info == num)
        {
            ch = 1;
            tmp2 = tmp;
            if(tmp->ant != NULL)
            {
                tmp->ant->prox = tmp->prox;
            }
            if(tmp->prox != NULL)
            {
                tmp->prox->ant = tmp->ant;
            }
            if(*lst == tmp)
            {
                *lst = tmp->prox;
            }
        }
        tmp = tmp->prox;
        if(ch)
            free(tmp2);
    }
    return 1;
}

int get_end(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
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

    return pos+1;
}


int get_element(Lista lst, int position)
{

    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL && pos < position)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->info;
}

int comparar_listas(Lista lst1, Lista lst2)
{
    int size1 = get_end(lst1), size2 = get_end(lst2);

    if(size1 != size2)
        return 0;

     int c = 0;

     Lista tmp1 = lst1->prox;
     Lista tmp2 = lst2->prox;

     while((tmp1 != NULL) && (tmp1->info == tmp2->info))
    {
        tmp1 = tmp1->prox;
        tmp2 = tmp2->prox;
        c ++;
    }

    if(c == size1)
        return 1;
    else
        return 0;
}
