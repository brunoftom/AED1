#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;

Lista cria_Lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst, int elem);
int remove_inicio(Lista *lst, int *elem);
int obtem_valor_elem(Lista lst, int i);
int get_end(Lista lst);
void print1(Lista lst);

#endif // LISTA_H_INCLUDED
