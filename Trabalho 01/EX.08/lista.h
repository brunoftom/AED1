#ifndef COMPLEXO_H_INCLUDED
#define COMPLEXO_H_INCLUDED
#define MAXN 20
#define MAX 11

#endif // COMPLEXO_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord (Lista *lst, int termo, int expoente);
int remove_ord(Lista *lst, int expoente);
int get_expoente(Lista lst, int position);
int get_termo(Lista lst, int position);
int get_end(Lista lst);
void limpa_lista(Lista *lst);
int resultado(Lista lst, int number);
