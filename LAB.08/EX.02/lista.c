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

int insere_inicio(Lista *lst, int elem)
{
   // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;// Falha: nó não alocado
    }
    N->info = elem; // Insere o conteúdo (valor do elem)

    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo nó (último nó)
    }

    // Trata lista com elementos (1 ou +)
    else
    {
        N->prox = (*lst)->prox; // Faz o novo nó apontar o 1o nó
        (*lst)->prox = N; // Faz o último nó apontar para o novo nó
    }
    return 1;
}

int remove_final(Lista *lst, int *elem)
{
    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox; // Faz aux apontar para primeiro nó
    Lista aux2 = (*lst); // Faz aux2 apontar para primeiro nó
    *elem = (*lst)->info; // Retorna valor do nó a ser removido
    if (*lst == (*lst)->prox)  // Trata lista com 1 único nó
    {
        *lst = NULL;
    }
    else  // Trata lista com + de 1 elemento
    {
        while(aux != (*lst))//percorrer até o último nó
        {
            aux2 = (*aux2).prox; //penúltimo elem
            aux = (*aux).prox; //ultimo elem
        }
        (*lst) = aux2;
        (*lst)->prox = aux->prox;
    }
    free(aux);
    free(aux2);
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
