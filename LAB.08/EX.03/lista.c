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
        return 0; // Lista N�O vazia
    }
}

int insere_elemento(Lista *lst, int elem)
{
    // Aloca um novo n� e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0; // Falha: n� n�o alocado
    }
    N->info = elem; // Insere o conte�do (valor do elem)
    N->ant = NULL; // N�o tem antecessor do novo n�
    N->prox = *lst; // Sucessor do novo n� recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0)  // Se lista N�O vazia
    {
        (*lst)->ant = N; // Faz o antecessor do 1o n� ser o novo n�
    }
    *lst = N; // Faz a lista apontar para o novo n�
    return 1;
}

int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst))  // Trata lista vazia
    {
        return 0;
    }
    Lista aux = *lst; // Faz aux apontar para 1o n�
    while (aux->prox != NULL && aux->info != elem)
    {
        aux = aux->prox;
    }
    if (aux->info != elem)
    {
        return 0; // Elemento n�o est� na lista
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


int get_element(Lista lst, int position)
{

    Lista aux = lst; // Ponteiro auxiliar para o 1o n�
    int pos = 0;

    while (aux->prox != NULL && pos < position)
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

    Lista aux = lst; // Ponteiro auxiliar para o 1o n�
    int pos = 0;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
        pos++;
    }

    return pos+1;
}
