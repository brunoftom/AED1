#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento(Lista *lst, int elem);
int remove_elemento(Lista *lst, int elem);
int remove_maior(Lista *lst, int *num);
int remove_todos(Lista *lst, int num);
int get_end(Lista lst);
int get_element(Lista lst, int position);
int comparar_listas(Lista lst1, Lista lst2);
#endif // LISTA_H_INCLUDED
