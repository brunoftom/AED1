#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAXN 20
#define MAX 11

struct no
{
    int termo;
    int expoente;
    struct no * prox;
};
typedef struct no * Lista;

Lista cria_lista()
{
    // Aloca nó cabeçalho
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));
    // Coloca lista no estado de vazia
    if (cab != NULL)   // Só se alocação NÃO falhar
    {
        cab->prox = NULL;
        cab->termo = 0;
    } // Opcional: guardar qtde
    return cab;
}

int lista_vazia(Lista lst)
{
    if (lst->prox == NULL)
    {
        return 1; // Lista vazia
    }
    else
    {
        return 0; // Lista NÃO vazia
    }
}
int insere_ord (Lista *lst, int termo, int expoente)
{
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0; // Falha: nó não alocado
    }
    N->expoente = expoente; // Insere o conteúdo (valor do expoente)
    N->termo = termo; // Insere o conteúdo (valor do termo)

    // Percorrimento da lista
    Lista aux = *lst; // Faz aux apontar para nó cabeçalho
    Lista aux2 = *lst; // Faz aux apontar para nó cabeçalho
    while (aux->prox != NULL && aux->prox->expoente < expoente)
    {
        aux = aux->prox; // Avança
    }
    aux2 = aux;
    while (aux2->prox != NULL && aux2->prox->expoente <= expoente)
    {
        if (expoente == aux2->prox->expoente)
        {
            aux2->prox->termo = aux2->prox->termo + termo;
            free(N);
            return 1;
        }
        aux2 = aux2->prox;

    }
    // Insere o novo nó na lista
    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->termo++;// Opcional: Incrementa qtde de nós na lista
    return 1;
}

int remove_ord (Lista *lst, int expoente)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }
    Lista aux = *lst; // Ponteiro auxiliar para nó cabeçalho
    // Percorrimento até final de lista, achar elem ou nó maior
    while((*aux).prox != NULL && aux->prox->expoente < expoente)
    {
        aux = (*aux).prox; //aux pega endereço de próxima região
    }
     if((*aux).prox == NULL || aux->prox->expoente > expoente) //fim da lista
        return 0; // Falha
    // Remove elemento da lista
    Lista aux2 = aux->prox; // Aponta nó a ser removido
    aux->prox = aux2->prox; // Retira nó da lista
    free(aux2); // Libera memória alocada
    (*lst)->termo--;// Opcional: Decrementa qtde de nós na lista
    return 1;
}

int get_expoente(Lista lst, int position)
{

    Lista aux = lst->prox; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL && pos < position)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->expoente;
}
int get_termo(Lista lst, int position)
{

    Lista aux = lst->prox; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL && pos < position)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->termo;
}

int resultado(Lista lst, int number)
{
    if (lst == NULL || lista_vazia(lst) == 1)
    {
        return 0; // Falha
    }

    Lista aux = lst->prox; // Ponteiro auxiliar para o 1o nó
    int result = 1, resultfinal = 0;

    while (aux != NULL)
    {
        for(int i = 0; i < aux->expoente; i++)
        {
            result = result * number;
        }
        result = result * aux->termo;
        resultfinal = resultfinal + result;
        result = 1;
        aux = aux->prox;
    }

    return resultfinal;
}

int get_end(Lista lst)
{
    return lst->termo;
}

void limpa_lista(Lista *lst)
{
    while((*lst)->prox != NULL)
    {
        Lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    (*lst)->termo = 0;
}


