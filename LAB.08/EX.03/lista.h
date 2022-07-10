#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento(Lista *lst, int elem);
int remove_elemento(Lista *lst, int elem);
int get_element(Lista lst, int position);
int get_end(Lista lst);

#endif // LISTA_H_INCLUDED
