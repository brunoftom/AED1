#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
int obtem_valor_elem(Lista *lst, int i, int nro);
void print1(Lista lst);

#endif // LISTA_H_INCLUDED
