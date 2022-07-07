#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct node *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
int obtem_valor_elem(Lista lst, int i, int *nro);
int get_end(Lista lst);
void print1(Lista *lst);
int comparar_listas(Lista lst1, Lista lst2);
int tamanho_lista(Lista lst);
Lista intercalar_lista(Lista lst1, Lista lst2);
int inverter_lista(Lista lst1, Lista *inv);
#endif // LISTA_H_INCLUDED
