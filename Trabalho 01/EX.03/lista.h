#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
int obtem_valor_elem(Lista lst, int *nro);
int get_end(Lista lst);
void print1(Lista lst);
int comparar_listas(Lista lst1, Lista lst2);
int tamanho_lista(Lista lst);
int intercalar_lista(Lista lst1, Lista lst2, Lista *lst3);
int inserePos(Lista *node, int elem);
int inverter_lista(Lista lst1, Lista *inv);
int lista_impares(Lista lst, Lista *b);
int calcular_media(Lista *lst, int tam);
#endif // LISTA_H_INCLUDED
