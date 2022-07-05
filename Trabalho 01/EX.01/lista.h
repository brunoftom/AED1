#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, int elem);
int remove_elem(Lista lst, int elem);
int obtem_valor_elem(Lista lst, int i, int *nro);
int tamanho_lista(Lista lst, int *tam);
Lista concatenar_listas(Lista l, Lista l2);
int menor_elemento(Lista lst, int *elem);
int remove_impares(Lista lst);
int get_valor(Lista l, int i, int *elem);
#endif // LISTA_H_INCLUDED
