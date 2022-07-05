#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10
#include "lista.h"

struct lista{
    int no[max];
    int fim;
};
typedef struct lista *Lista;

Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->fim = 0;

    return lst;
}

int lista_vazia(Lista lst){
    if(lst->fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista lst){
    if(lst->fim == max)
        return 1;
    else
        return 0;
}

int insere_elem(Lista lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1)
        return 0;

    lst->no[lst->fim] = elem;
    lst->fim++;

    return 1;
}

int remove_elem(Lista lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;

    int i, aux = 0;

    while(aux < lst->fim && lst->no[aux] != elem)
        aux++;

    if(aux == lst->fim)
        return 0;

    for(i = aux+1; i<lst->fim; i++){
        lst->no[i-1] = lst->no[i];
    }

    lst->fim--;
    return 1;
}

int obtem_valor_elem(Lista lst, int i, int *nro){
    if(lst == NULL || lista_vazia(lst))
        return 0;

    *nro = (*lst).no[i];

    return 1;
}

Lista concatenar_listas(Lista lst1, Lista lst2)
{
    if(lst1 == NULL || lst2 == NULL)
        return NULL;
    if(lista_vazia(lst1) && lista_vazia(lst2))
        return NULL;
    if (lst1->fim + lst2->fim > max)
        return NULL;

    Lista lst3 = cria_lista();

    int i = 0;
    while(i < lst1->fim)
    {
        lst3->no[i] = lst1->no[i];
        lst3->fim++;
        i++;
    }
    i = 0;
    while (i < lst2->fim){
        lst3->no[lst3->fim] = lst2->no[i];
        lst3->fim++;
        i++;
    }
    return lst3;

}

int menor_elemento(Lista lst, int *elem)
{
    if(lst == NULL)
        return 0;
    int aux = 0, menor;

    menor = lst->no[aux];

    while(aux < lst->fim)
    {
        if(lst->no[aux+1] < menor)
        {
            menor = lst->no[aux+1];
        }
        aux++;
    }

    *elem = menor;

    return 1;
}

int remove_impares(Lista lst)
{
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;
    int j = 0, fim, elem;

    tamanho_lista(lst,&fim);

    for(int i = 0; i<fim; i++)
    {
        get_valor(lst, i, &elem);
        if(fmod(elem, 2) == 0)
        {
            lst->no[j] = lst->no[i];
            j++;
        }
    }
    lst->fim  = j;

    return 1;
}

int get_valor(Lista l, int i, int *elem)
{
    if(l == NULL || lista_vazia(l))
    {
        return 0;
    }

    *elem = l->no[i]; //lista estática sequencial, então elemento tem posição indexada

    return 1;
}

int tamanho_lista(Lista lst, int *tam)
{
    if(lst == NULL)
        return 0;
    *tam = lst->fim;

    return 1;
}

void print1(Lista lst)
{
    printf("Lista: { ");
    for(int i =0; i<lst->fim; i++)
    {
        printf(" %d ", lst->no[i]);

    }
    printf(" }");
}
