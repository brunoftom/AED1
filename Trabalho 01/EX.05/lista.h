#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst,int elem);
int remove_inicio(Lista *lst,int *elem);
int obtem_valor_elem(Lista lst,int pos,int *elem);
int insere_inicio(Lista *lst,int elem);
int insere_posicao(Lista *lst,int pos,int elem);
int remove_final(Lista *l, int *elem);
int remove_par(Lista *lst);
int apaga_lista(Lista *lst);
int remove_elem(Lista *l, int *elem);
int get_fim(Lista *l, int *i);

#endif // LISTA_H_INCLUDED
